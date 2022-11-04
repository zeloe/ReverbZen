/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ReverbZenAudioProcessorEditor::ReverbZenAudioProcessorEditor (ReverbZenAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
decayKnob("Decay", 0, 1, 0.01, 0),
dampKnob("Damp", 0, 1, 0.01, 0),
mixKnob("Mix", 0, 1, 0.01, 0),
erampKnob("Eramp", 0, 1, 0.01, 0),
erdelayKnob("ErDelay", 0, 1, 0.01, 0),
predelayKnob("PreDelay", 0, 1, 0.01, 0),
highPassKnob("HighPass", 20, 20000, 1, 0),
decayAttach(audioProcessor.treeState, "Reverb", decayKnob),
dampAttach(audioProcessor.treeState, "Damp", dampKnob),
mixAttach(audioProcessor.treeState, "Mix", mixKnob),
erampAttach(audioProcessor.treeState, "Eramp", erampKnob),
erdelayAttach(audioProcessor.treeState, "ErDelay", erdelayKnob),
preDelayAttach(audioProcessor.treeState, "PreDelay", predelayKnob),
highPassAttach(audioProcessor.treeState, "HighpassFreq", highPassKnob),
bypassAttach(audioProcessor.treeState, "Bypass", bypassButton),
prePostAttach(audioProcessor.treeState, "Pre/Post", prepostButton)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1200,600);
    decayKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    decayKnob.setTextValueSuffix(" %");
    decayLabel.setText("Decay", juce::dontSendNotification);
    decayLabel.attachToComponent(&decayKnob, false);
    addAndMakeVisible(&decayKnob);
    
    dampKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    dampKnob.setTextValueSuffix(" %");
    dampLabel.setText("Damp", juce::dontSendNotification);
    dampLabel.attachToComponent(&dampKnob, false);
    addAndMakeVisible(&dampKnob);
    
    mixKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    mixKnob.setTextValueSuffix(" %");
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.attachToComponent(&mixKnob, false);
    addAndMakeVisible(&mixKnob);
    
    erampKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    erampKnob.setTextValueSuffix(" %");
    erampLabel.setText("ErAmp", juce::dontSendNotification);
    erampLabel.attachToComponent(&erampKnob, false);
    addAndMakeVisible(&erampKnob);
    
    
    erdelayKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    erdelayKnob.setTextValueSuffix(" %");
    erdelayLabel.setText("ErDelay", juce::dontSendNotification);
    erdelayLabel.attachToComponent(&erdelayKnob, false);
    addAndMakeVisible(&erdelayKnob);
    
    
    
    predelayKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    predelayKnob.setTextValueSuffix(" %");
    predelayLabel.setText("PreDelay", juce::dontSendNotification);
    predelayLabel.attachToComponent(&predelayKnob, false);
    addAndMakeVisible(&predelayKnob);
    
    
    highPassKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    highPassKnob.setTextValueSuffix(" Hz");
    highPassLabel.setText("HighPass", juce::dontSendNotification);
    highPassLabel.attachToComponent(&highPassKnob, false);
    addAndMakeVisible(&highPassKnob);
    
    bypassButton.setButtonText("Bypass");
    addAndMakeVisible(&bypassButton);
    
    prepostButton.setButtonText("Pre/Post");
    addAndMakeVisible(&prepostButton);
    
}

ReverbZenAudioProcessorEditor::~ReverbZenAudioProcessorEditor()
{
}

//==============================================================================
void ReverbZenAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    
    
}

void ReverbZenAudioProcessorEditor::resized()
{
    dampKnob.setBounds(50, 50, 150, 150);
    predelayKnob.setBounds(250, 50, 150, 150);
    erampKnob.setBounds(450, 50, 150, 150);
    erdelayKnob.setBounds(650, 50, 150, 150);
    decayKnob.setBounds(850, 50, 150, 150);
    mixKnob.setBounds(1050,50,150,150);
    highPassKnob.setBounds(50, 300, 150, 150);
    bypassButton.setBounds(250, 300, 100, 100);
    prepostButton.setBounds(450, 300, 100, 100);
}
