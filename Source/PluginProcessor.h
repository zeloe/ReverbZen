/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "reverb.h"
#include "Parameters.h"
//==============================================================================
/**
*/
class ReverbZenAudioProcessor  : public juce::AudioProcessor,
// listeners for parameters
public juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    ReverbZenAudioProcessor();
    ~ReverbZenAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    // create treestate
    juce::AudioProcessorValueTreeState treeState;
private:
    // create parameter layout
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    // listener function for parameters
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    // update parameters in prepare to play
    void updateParameters ();
    // faust related variables
    MapUI* fUI;
    dsp* fDSP;
    float **inputs;
    float **outputs;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbZenAudioProcessor)
};
