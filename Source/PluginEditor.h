/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Zen_Knob.h"
//==============================================================================
/**
*/
class ReverbZenAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ReverbZenAudioProcessorEditor (ReverbZenAudioProcessor&);
    ~ReverbZenAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ReverbZenAudioProcessor& audioProcessor;
    juce::Zen_Knob decayKnob, dampKnob, mixKnob, erampKnob, erdelayKnob, predelayKnob;
    juce::Label decayLabel, mixLabel, dampLabel, erampLabel, erdelayLabel, predelayLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment decayAttach, dampAttach, mixAttach,
    erampAttach, erdelayAttach, preDelayAttach;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbZenAudioProcessorEditor)
};
