/*
  ==============================================================================

    Points.h
    Created: 6 Nov 2022 11:02:49pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
class Points:
public juce::Component
{
public:
    Points(juce::Colour colour)
    {
        colour1 = colour;
    }
    ~Points(){};
    
    
    void paint(juce::Graphics& g)override
    {
        g.setColour(colour1);
        g.fillEllipse(posX,posY,size,size);
    }
    
    
    void getX(int x)
    {
        posX = x;
    }
    
    void getY(int y)
    {
        posY = y;
    }
    
private:
    juce::Colour colour1;
    int posX = 0;
    int posY = 0;
    int size = 10;
    
};
