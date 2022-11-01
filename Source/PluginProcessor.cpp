/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ReverbZenAudioProcessor::ReverbZenAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
,treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    
    treeState.addParameterListener("Reverb", this);
    treeState.addParameterListener("PreDelay", this);
    treeState.addParameterListener("ErDelay", this);
    treeState.addParameterListener("Eramp", this);
    treeState.addParameterListener("Mix", this);
    treeState.addParameterListener("Damp", this);
    
}

ReverbZenAudioProcessor::~ReverbZenAudioProcessor()
{
    treeState.removeParameterListener("Reverb", this);
    treeState.removeParameterListener("PreDelay", this);
    treeState.removeParameterListener("ErDelay", this);
    treeState.removeParameterListener("Eramp", this);
    treeState.removeParameterListener("Mix", this);
    treeState.removeParameterListener("Damp", this);
}
juce::AudioProcessorValueTreeState::ParameterLayout
ReverbZenAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    auto pReverb = (std::make_unique<juce::AudioParameterFloat>("Reverb",
                                                            "Reverb",0.01f,1.f,0.75f));
    auto pPreDelay = (std::make_unique<juce::AudioParameterFloat>("PreDelay",
                                                            "PreDelay",0.01f,1.f,0.1f));
    auto pErDelay = (std::make_unique<juce::AudioParameterFloat>("ErDelay",
                                                            "ErDelay",0.01f,1.f,0.1f));
    auto pEramp = (std::make_unique<juce::AudioParameterFloat>("Eramp",
                                                            "Eramp",0.0f,1.f,0.1f));
    auto pMix = (std::make_unique<juce::AudioParameterFloat>("Mix",
                                                            "Mix",0.00f,1.f,0.75f));
    auto pDamp = (std::make_unique<juce::AudioParameterFloat>("Damp",
                                                            "Damp",0.01f,1.f,0.67f));
    
   
    
    params.push_back(std::move(pReverb));
    params.push_back(std::move(pPreDelay));
    params.push_back(std::move(pErDelay));
    params.push_back(std::move(pEramp));
    params.push_back(std::move(pDamp));
    params.push_back(std::move(pMix));
    
    return {params.begin(),params.end()};
}

void ReverbZenAudioProcessor::parameterChanged(const juce::String &paramterID, float newValue)
{
    if (paramterID == "Reverb")
    {
        fUI->setParamValue("decaydelay", newValue);
    }
    if (paramterID == "Mix")
    {
        fUI->setParamValue("delaywet", newValue);
    }
    if (paramterID == "Damp")
    {
        fUI->setParamValue("damp", newValue);
    }
    if (paramterID == "PreDelay")
    {
        fUI->setParamValue("predelay", newValue);
    }
    if (paramterID == "Eramp")
    {
        fUI->setParamValue("eramp", newValue);
    }
    if (paramterID == "ErDelay")
    {
        fUI->setParamValue("erdelay", newValue);
    }
}


void ReverbZenAudioProcessor::updateParameters()
{
    
    fUI->setParamValue("decaydelay", treeState.getRawParameterValue("Reverb")->load());
    fUI->setParamValue("delaywet", treeState.getRawParameterValue("Mix")->load());
    fUI->setParamValue("damp", treeState.getRawParameterValue("Damp")->load());
    fUI->setParamValue("predelay", treeState.getRawParameterValue("PreDelay")->load());
    fUI->setParamValue("eramp", treeState.getRawParameterValue("Eramp")->load());
    fUI->setParamValue("erdelay", treeState.getRawParameterValue("ErDelay")->load());
    
    
    
    
    
}

//==============================================================================
const juce::String ReverbZenAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ReverbZenAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ReverbZenAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ReverbZenAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ReverbZenAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ReverbZenAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ReverbZenAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ReverbZenAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ReverbZenAudioProcessor::getProgramName (int index)
{
    return {};
}

void ReverbZenAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ReverbZenAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fDSP = new mydsp();
            fDSP->init(sampleRate);
            fUI = new MapUI();
            fDSP->buildUserInterface(fUI);
            inputs = new float*[2];
            outputs = new float*[2];
            for (int channel = 0; channel < 2; ++channel)
            {
                inputs[channel] = new float[samplesPerBlock];
                outputs[channel] = new float[samplesPerBlock];
            }
            updateParameters();
}

void ReverbZenAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ReverbZenAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ReverbZenAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
            buffer.clear (i, 0, buffer.getNumSamples());


    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        for (int i = 0; i < buffer.getNumSamples(); i++) {
                inputs[channel][i] = *buffer.getWritePointer(channel,i);
        }
    }

    fDSP->compute(buffer.getNumSamples(),inputs,outputs);
                
    for (int channel = 0; channel < totalNumOutputChannels; ++channel) {
        for (int i = 0; i < buffer.getNumSamples(); i++){
            *buffer.getWritePointer(channel,i) = outputs[channel][i];
        }
    }
}

//==============================================================================
bool ReverbZenAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ReverbZenAudioProcessor::createEditor()
{
    return new ReverbZenAudioProcessorEditor (*this);
}

//==============================================================================
void ReverbZenAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ReverbZenAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ReverbZenAudioProcessor();
}
