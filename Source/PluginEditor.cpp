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
prePostAttach(audioProcessor.treeState, "Pre/Post", prepostButton),
rv1(juce::Colours::red),
rv2(juce::Colours::green),
rv3(juce::Colours::blue)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1400,1400);
    startTimerHz(33);
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
    
    addAndMakeVisible(&rv1);
    addAndMakeVisible(&rv2);
    addAndMakeVisible(&rv3);
    initPoints();
    predelayKnob.onValueChange = [this] ()
    {
        rv1.point1.getX(((predelayKnob.getValue() - 0.01f) * 0.51 + 0.1 )  * 200 + 50 ); //510 max min 10
        rv1.point2.getX(((predelayKnob.getValue() - 0.01f) * 0.53 + 0.2 ) * 200 + 50); // 540 max min 20
        rv1.point3.getX(((predelayKnob.getValue() - 0.01f) * 0.56 + 0.3 ) * 200 + 50); // 540 max min 30
        rv1.point4.getX(((predelayKnob.getValue() - 0.01f) * 0.51 + 0.1 ) * 200 + 50); // 510 max min 10
        rv1.point5.getX(((predelayKnob.getValue() - 0.01f) * 0.54 + 0.2 ) * 200 + 50); // 540 max min 20
        rv1.point6.getX(((predelayKnob.getValue() - 0.01f) * 0.61 + 0.2 ) * 200 + 50); // 610 max min 20
        rv1.point7.getX(((predelayKnob.getValue() - 0.01f) * 0.50 + 0.1 ) * 200 + 50); // 520 max min 10
        rv1.point8.getX(((predelayKnob.getValue() - 0.01f) * 0.52 + 0.2 ) * 200 + 50); // 540 max min 20
        
    };
    erdelayKnob.onValueChange = [this] ()
    {
        rv2.point1.getX(((erdelayKnob.getValue() - 0.01f)* .56f +.02 )* 200 + 50);
        rv2.point2.getX(((erdelayKnob.getValue() - 0.01f)* .535f +.05 )* 200 + 50);
        rv2.point3.getX(((erdelayKnob.getValue() - 0.01f)* .548f + .08 )* 200 + 50);
        rv2.point4.getX(((erdelayKnob.getValue() - 0.01f)* .556f + .16 )* 200 + 50);
        rv2.point5.getX(((erdelayKnob.getValue() - 0.01f)* .550f +.20 )* 200 + 50);
        rv2.point6.getX(((erdelayKnob.getValue() - 0.01f)* .57f + .11 )* 200 + 50);
        rv2.point7.getX(((erdelayKnob.getValue() - 0.01f)* .548f + .08 )* 200 + 50);
        rv2.point8.getX(((erdelayKnob.getValue() - 0.01f)* .535f + .1 )* 200 + 50);
    };
    
    
    
    decayKnob.onValueChange = [this]
    {
        rv3.point1.getX(((decayKnob.getValue() - 0.01f)* .132f +.1 )* 200 + 50);
        rv3.point2.getX(((decayKnob.getValue() - 0.01f)* .125f +.05 )* 200 + 50);
        rv3.point3.getX(((decayKnob.getValue() - 0.01f)* .138f + .08 )* 200 + 50);
        rv3.point4.getX(((decayKnob.getValue() - 0.01f)* .146f + .06 )* 200 + 50);
        rv3.point5.getX(((decayKnob.getValue() - 0.01f)* .150f +.20 )* 200 + 50);
        rv3.point6.getX(((decayKnob.getValue() - 0.01f)* .150f + .10 )* 200 + 50);
        rv3.point7.getX(((decayKnob.getValue() - 0.01f)* .138f + .08 )* 200 + 50);
        rv3.point8.getX(((decayKnob.getValue() - 0.01f)* .115f + .04 )* 200 + 50);  
        
    };
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
    
    rv1.setBounds(50, 10, 300, 200);
    rv2.setBounds(470,10 , 300, 200);
    rv3.setBounds(880, 10, 300,200);
    
    
    const int offset =  300;
    dampKnob.setBounds(50, 50 +offset, 150, 150);
    predelayKnob.setBounds(250, 50 +offset, 150, 150);
    erampKnob.setBounds(450, 50 + offset, 150, 150);
    erdelayKnob.setBounds(650, 50 +offset, 150 , 150);
    decayKnob.setBounds(850, 50 +offset, 150 , 150);
    mixKnob.setBounds(1050,50 +offset,150,150);
    highPassKnob.setBounds(50, 300 +offset, 150, 150);
    bypassButton.setBounds(250, 300 +offset, 100, 100);
    prepostButton.setBounds(450, 300 +offset, 100, 100);
}


void ReverbZenAudioProcessorEditor::timerCallback()
{
    repaint();
}

void ReverbZenAudioProcessorEditor::initPoints()
{
    rv1.point1.getX(((predelayKnob.getValue() - 0.01f) * 0.51 + 0.1 )  * 200 + 50 ); //510 max min 10
    rv1.point2.getX(((predelayKnob.getValue() - 0.01f) * 0.53 + 0.2 ) * 200 + 50); // 540 max min 20
    rv1.point3.getX(((predelayKnob.getValue() - 0.01f) * 0.55 + 0.3 ) * 200 + 50); // 540 max min 30
    rv1.point4.getX(((predelayKnob.getValue() - 0.01f) * 0.51 + 0.1 ) * 200 + 50); // 510 max min 10
    rv1.point5.getX(((predelayKnob.getValue() - 0.01f) * 0.54 + 0.2 ) * 200 + 50); // 540 max min 20
    rv1.point6.getX(((predelayKnob.getValue() - 0.01f) * 0.61 + 0.2 ) * 200 + 50); // 610 max min 20
    rv1.point7.getX(((predelayKnob.getValue() - 0.01f) * 0.50 + 0.1 ) * 200 + 50); // 520 max min 10
    rv1.point8.getX(((predelayKnob.getValue() - 0.01f) * 0.52 + 0.2 ) * 200 + 50); // 540 max min 20
    
    rv1.point1.getY((10));
    rv1.point2.getY((30));
    rv1.point3.getY((50));
    rv1.point4.getY((70));
    rv1.point5.getY((90));
    rv1.point6.getY((110));
    rv1.point7.getY((130));
    rv1.point8.getY((150));
    
    
    rv2.point1.getX(((erdelayKnob.getValue() - 0.01f)* .56f +.02 )* 200 + 50); //max 560 min 10
    rv2.point2.getX(((erdelayKnob.getValue() - 0.01f)* .535f +.05 )* 200 + 50); //max 535 min 5
    rv2.point3.getX(((erdelayKnob.getValue() - 0.01f)* .548f + .08 )* 200 + 50); //max 548 min 8
    rv2.point4.getX(((erdelayKnob.getValue() - 0.01f)* .556f + .16 )* 200 + 50); //max 566 min 16
    rv2.point5.getX(((erdelayKnob.getValue() - 0.01f)* .550f +.20 )* 200 + 50); //max 550 min 20
    rv2.point6.getX(((erdelayKnob.getValue() - 0.01f)* .57f + .11 )* 200 + 50); //max 570 min 10
    rv2.point7.getX(((erdelayKnob.getValue() - 0.01f)* .548f + .08 )* 200 + 50); //max 548 min 8
    rv2.point8.getX(((erdelayKnob.getValue() - 0.01f)* .535f + .1 )* 200 + 50); //max 535 min 5
    
    
    
    rv2.point1.getY((10));
    rv2.point2.getY((30));
    rv2.point3.getY((50));
    rv2.point4.getY((70));
    rv2.point5.getY((90));
    rv2.point6.getY((110));
    rv2.point7.getY((130));
    rv2.point8.getY((150));
    
    rv3.point1.getX(((decayKnob.getValue() - 0.01f)* .132f +.1 )* 200 + 50);
    rv3.point2.getX(((decayKnob.getValue() - 0.01f)* .125f +.05 )* 200 + 50);
    rv3.point3.getX(((decayKnob.getValue() - 0.01f)* .138f + .08 )* 200 + 50);
    rv3.point4.getX(((decayKnob.getValue() - 0.01f)* .146f + .06 )* 200 + 50);
    rv3.point5.getX(((decayKnob.getValue() - 0.01f)* .150f +.20 )* 200 + 50);
    rv3.point6.getX(((decayKnob.getValue() - 0.01f)* .150f + .10 )* 200 + 50);
    rv3.point7.getX(((decayKnob.getValue() - 0.01f)* .138f + .08 )* 200 + 50);
    rv3.point8.getX(((decayKnob.getValue() - 0.01f)* .115f + .04 )* 200 + 50);
    
    rv3.point1.getY((10));
    rv3.point2.getY((30));
    rv3.point3.getY((50));
    rv3.point4.getY((70));
    rv3.point5.getY((90));
    rv3.point6.getY((110));
    rv3.point7.getY((130));
    rv3.point8.getY((150));
}
