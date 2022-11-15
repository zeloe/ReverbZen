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
   // add listeners for each parameter
    treeState.addParameterListener(sReverb, this);
    treeState.addParameterListener(sPreDelay, this);
    treeState.addParameterListener(sErDelay, this);
    treeState.addParameterListener(sWidth, this);
    treeState.addParameterListener(sMix, this);
    treeState.addParameterListener(sDamp, this);
    treeState.addParameterListener(sHighPassFreq, this);
    treeState.addParameterListener(sPrePost, this);
    treeState.addParameterListener(sBypass, this);
    treeState.addParameterListener(sLowpass, this);
    
}

ReverbZenAudioProcessor::~ReverbZenAudioProcessor()
{
    // remove listeners for each parameter
    treeState.removeParameterListener(sReverb, this);
    treeState.removeParameterListener(sPreDelay, this);
    treeState.removeParameterListener(sErDelay, this);
    treeState.removeParameterListener(sWidth, this);
    treeState.removeParameterListener(sMix, this);
    treeState.removeParameterListener(sDamp, this);
    treeState.removeParameterListener(sHighPassFreq, this);
    treeState.removeParameterListener(sPrePost, this);
    treeState.removeParameterListener(sBypass, this);
    treeState.removeParameterListener(sLowpass, this);
}
juce::AudioProcessorValueTreeState::ParameterLayout
ReverbZenAudioProcessor::createParameterLayout()
{
    // create parameters
    // you could also use a array with strings and add them in a for loop
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    auto pReverb = (std::make_unique<juce::AudioParameterFloat>(sReverb,
                                                            sReverb,0.01f,1.f,0.75f));
    auto pPreDelay = (std::make_unique<juce::AudioParameterFloat>(sPreDelay,
                                                            sPreDelay,0.01f,1.f,0.1f));
    auto pLowpass = (std::make_unique<juce::AudioParameterFloat>(sLowpass,
                                                                 sLowpass,0.01f,1.f,0.5f));
    
    auto pErDelay = (std::make_unique<juce::AudioParameterFloat>(sErDelay,
                                                                 sErDelay,0.01f,1.f,0.1f));
    auto pWidth = (std::make_unique<juce::AudioParameterFloat>(sWidth,
                                                               sWidth,0.0f,1.f,0.5f));
    auto pMix = (std::make_unique<juce::AudioParameterFloat>(sMix,
                                                            sMix,0.00f,1.f,0.75f));
    auto pDamp = (std::make_unique<juce::AudioParameterFloat>(sDamp,
                                                              sDamp,0.01f,1.f,0.67f));
    
    auto pHighPassFreq(std::make_unique<juce::AudioParameterInt>(sHighPassFreq,sHighPassFreq, 20,20000,5000));
    
    auto pRouting(std::make_unique<juce::AudioParameterInt>(sPrePost,sPrePost, 0, 1, 0));
    
    auto pBypass(std::make_unique<juce::AudioParameterInt>(sBypass,sBypass, 0, 1 ,0));
    
    params.push_back(std::move(pReverb));
    params.push_back(std::move(pPreDelay));
    params.push_back(std::move(pLowpass));
    params.push_back(std::move(pErDelay));
    params.push_back(std::move(pWidth));
    params.push_back(std::move(pDamp));
    params.push_back(std::move(pMix));
    params.push_back(std::move(pHighPassFreq));
    params.push_back(std::move(pRouting));
    params.push_back(std::move(pBypass));
    return {params.begin(),params.end()};
}

void ReverbZenAudioProcessor::parameterChanged(const juce::String &paramterID, float newValue)
{
    // check if parameter has changed and change value
    if (paramterID == sReverb)
    {
        fUI->setParamValue("decaydelay", newValue);
    }
    if (paramterID == sMix)
    {
        fUI->setParamValue("delaywet", newValue);
    }
    if (paramterID == sDamp)
    {
        fUI->setParamValue("damp", newValue);
    }
    if (paramterID == sPreDelay)
    {
        fUI->setParamValue("predelay", newValue);
    }
    if (paramterID == sWidth)
    {
        fUI->setParamValue("width", newValue);
    }
    if (paramterID == sErDelay)
    {
        fUI->setParamValue("erdelay", newValue);
    }
    
    if (paramterID == sPrePost)
    {
        // check value
        if (newValue == 0)
        {
            //set value
            fUI->setParamValue("mixhighpassin", 1);
            fUI->setParamValue("mixhighpassout", 0);
        } else if (newValue == 1)
        {
            fUI->setParamValue("mixhighpassin", 0);
            fUI->setParamValue("mixhighpassout", 1);
        }
    }
    
    if (paramterID == sBypass)
    {
        if (newValue == 0)
        {
            if(treeState.getRawParameterValue(sPrePost)->load() == 0)
            {
                fUI->setParamValue("mixhighpassin", 1);
                fUI->setParamValue("mixhighpassout", 0);
            } else if (treeState.getRawParameterValue(sPrePost)->load() == 1)
            {
                fUI->setParamValue("mixhighpassin", 0);
                fUI->setParamValue("mixhighpassout",1);
            }
        } else if(newValue == 1)
        {
            fUI->setParamValue("mixhighpassin", 0);
            fUI->setParamValue("mixhighpassout", 0);
        }
        
    }
    if(paramterID == sHighPassFreq)
    {
        fUI->setParamValue("highpasscutoff", newValue);
    }
    
    if(paramterID == sLowpass)
    {
        fUI->setParamValue("lowpassfc", newValue);
    }
    
}


void ReverbZenAudioProcessor::updateParameters()
{
    // listeners will only change when moved in this case you can add a function to get parameters in prepare to play
    fUI->setParamValue("decaydelay", treeState.getRawParameterValue(sReverb)->load());
    fUI->setParamValue("delaywet", treeState.getRawParameterValue(sMix)->load());
    fUI->setParamValue("damp", treeState.getRawParameterValue(sDamp)->load());
    fUI->setParamValue("predelay", treeState.getRawParameterValue(sPreDelay)->load());
    fUI->setParamValue("width", treeState.getRawParameterValue(sWidth)->load());
    fUI->setParamValue("erdelay", treeState.getRawParameterValue(sErDelay)->load());
    fUI->setParamValue("lowpassfc", treeState.getRawParameterValue(sLowpass)->load());
    if(treeState.getRawParameterValue(sPrePost)->load() == 0)
    {
        fUI->setParamValue("mixhighpassin", 1);
        fUI->setParamValue("mixhighpassout", 0);
    } else if (treeState.getRawParameterValue(sPrePost)->load() == 1)
    {
        fUI->setParamValue("mixhighpassin", 0);
        fUI->setParamValue("mixhighpassout",1);
    }
    if (treeState.getRawParameterValue(sBypass)->load() == 0)
    {
        if(treeState.getRawParameterValue(sPrePost)->load() == 0)
        {
            fUI->setParamValue("mixhighpassin", 1);
            fUI->setParamValue("mixhighpassout", 0);
        } else if (treeState.getRawParameterValue(sPrePost)->load() == 1)
        {
            fUI->setParamValue("mixhighpassin", 0);
            fUI->setParamValue("mixhighpassout",1);
        }
    } else if(treeState.getRawParameterValue(sBypass)->load() == 1)
    {
        fUI->setParamValue("mixhighpassin", 0);
        fUI->setParamValue("mixhighpassout", 0);
    }
    fUI->setParamValue("highpasscutoff", treeState.getRawParameterValue(sHighPassFreq)->load());
        
    
    
    
    
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
    // faust initialisation
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
    // update parameters
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

    // get inputs
    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        for (int i = 0; i < buffer.getNumSamples(); i++) {
                inputs[channel][i] = *buffer.getWritePointer(channel,i);
        }
    }
    // compute
    fDSP->compute(buffer.getNumSamples(),inputs,outputs);
            
    
    // get outputs
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
    juce::MemoryOutputStream mos (destData, true);
                     treeState.state.writeToStream(mos);
}

void ReverbZenAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
                          if(tree.isValid() )
                          {
                              treeState.replaceState(tree);
                          }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ReverbZenAudioProcessor();
}
