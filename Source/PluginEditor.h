/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Zen_Knob.h"
#include "ReverbVisual.h"
#include "GuiDefines.h"
//==============================================================================
/**
*/
class ReverbZenAudioProcessorEditor  : public juce::AudioProcessorEditor,public juce::Timer
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
    juce::Zen_Knob decayKnob, mixKnob, widthKnob, highPassKnob;
    juce::Label decayLabel, mixLabel, dampLabel, widthLabel, highPassLabel, lowpassLabel, preDelayLabel, earlyDelayLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment decayAttach, mixAttach,widthAttach,highPassAttach;
    juce::ToggleButton bypassButton, prepostButton;
    juce::AudioProcessorValueTreeState::ButtonAttachment bypassAttach, prePostAttach;
    ReverbVisual rv1,rv2;
    void timerCallback() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbZenAudioProcessorEditor)
};
