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
// init params
decayKnob("Decay", 0, 1, 0.01, 0),
mixKnob("Mix", 0, 1, 0.01, 0),
widthKnob("Eramp", 0, 1, 0.01, 0),
highPassKnob("HighPass", 20, 20000, 1, 0),
decayAttach(audioProcessor.treeState, sReverb, decayKnob),
mixAttach(audioProcessor.treeState, sMix, mixKnob),
widthAttach(audioProcessor.treeState, sWidth, widthKnob),
highPassAttach(audioProcessor.treeState, sHighPassFreq, highPassKnob),
bypassAttach(audioProcessor.treeState, sBypass, bypassButton),
prePostAttach(audioProcessor.treeState, sPrePost, prepostButton),
// long constructor I maybe I change this
rv1(juce::Colours::red,rv1SetOffsetX,rv1AddOffsetX,rv1offsetY,rv1AddOffsetY,audioProcessor.treeState.getParameter(sPreDelay),audioProcessor.treeState.getParameter(sLowpass)),
rv2(juce::Colours::green,rv2SetOffsetX,rv2AddOffsetX,rv2offsetY,rv2AddOffsetY,audioProcessor.treeState.getParameter(sErDelay),audioProcessor.treeState.getParameter(sDamp))
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700,700);
    setResizable(true, true);
    setResizeLimits(700, 700,900,900);
    getConstrainer()->setFixedAspectRatio(1.2);
    startTimerHz(33);
    decayKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    decayKnob.setTextValueSuffix(" %");
    decayLabel.setText("Decay", juce::dontSendNotification);
    decayLabel.attachToComponent(&decayKnob, false);
    addAndMakeVisible(&decayKnob);
    
    
    mixKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    mixKnob.setTextValueSuffix(" %");
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.attachToComponent(&mixKnob, false);
    addAndMakeVisible(&mixKnob);
    
    widthKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    widthKnob.setTextValueSuffix(" %");
    widthLabel.setText("Width", juce::dontSendNotification);
    widthLabel.attachToComponent(&widthKnob, false);
    addAndMakeVisible(&widthKnob);
    
    
    
    
   
   
    
    highPassKnob.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    highPassKnob.setTextValueSuffix(" Hz");
    highPassLabel.setText("HighPass", juce::dontSendNotification);
    highPassLabel.attachToComponent(&highPassKnob, false);
    addAndMakeVisible(&highPassKnob);
    
    bypassButton.setButtonText("Bypass");
    addAndMakeVisible(&bypassButton);
    
    prepostButton.setButtonText("Pre/Post");
    addAndMakeVisible(&prepostButton);
    
    preDelayLabel.setText("PreDelay", juce::dontSendNotification);
    preDelayLabel.attachToComponent(&rv1, true);
    lowpassLabel.setText("LowPassFrequency", juce::dontSendNotification);
    lowpassLabel.attachToComponent(&rv1, false);
    
    addAndMakeVisible(&rv1);
    
    dampLabel.setText("Damp", juce::dontSendNotification);
    dampLabel.attachToComponent(&rv2, false);
    earlyDelayLabel.setText("EarlyReflectionsDelay", juce::dontSendNotification);
    earlyDelayLabel.attachToComponent(&rv2, true);
    addAndMakeVisible(&rv2);
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
    // get bounds and scale them to resize window and keep aspect ratio
    const int offsetW = getLocalBounds().getWidth();
    const int offsetH3 =  getLocalBounds().getHeight() / 10;
    const int offsetW3 = offsetW / 10;
    const int offsetKnobs = getLocalBounds().getWidth() / 5;
    rv1.setBounds(offsetW3, offsetH3, offsetW3 * 3, offsetW3 * 3);
    rv2.setBounds(offsetW3 * 2 * 3,offsetH3 , offsetW3 * 3,offsetW3 * 3);
    
    widthKnob.setBounds(offsetKnobs , offsetH3 +offsetW3 *4, offsetKnobs, offsetKnobs);
    mixKnob.setBounds(offsetKnobs * 0.25 , offsetH3 +offsetW3 * 4,offsetKnobs,offsetKnobs);
    highPassKnob.setBounds(offsetKnobs * 2.1 + offsetKnobs * 0.75, offsetH3 +offsetW3 * 4, offsetKnobs, offsetKnobs);
    bypassButton.setBounds(offsetKnobs  * 2.1,  offsetH3 +offsetW3 * 4, offsetKnobs * 0.5, offsetKnobs* 0.5 );
    prepostButton.setBounds(offsetKnobs * 2.1,  offsetH3 +offsetW3 * 4.8, offsetKnobs* 0.5 , offsetKnobs* 0.5 );
    decayKnob.setBounds(offsetKnobs * 3.75, offsetH3 + offsetW3 * 4, offsetKnobs, offsetKnobs);
}


void ReverbZenAudioProcessorEditor::timerCallback()
{
    repaint();
}
