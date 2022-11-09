/*
  ==============================================================================

    Rectangle.h
    Created: 7 Nov 2022 7:50:58pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
class Rect: public juce::Component
{
public:
    Rect() {};
    ~Rect() {};
    
    
    
    void paint(juce::Graphics& g )override
    {
        g.setColour(juce::Colours::white);
        g.drawRect(0,0,getParentWidth(),getParentHeight());
    }
    
    
};
