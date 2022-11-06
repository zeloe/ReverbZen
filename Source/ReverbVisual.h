/*
  ==============================================================================

    ReverbVisual.h
    Created: 6 Nov 2022 11:02:41pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "Points.h"

class ReverbVisual: public juce::AnimatedAppComponent
{
public:
    ReverbVisual(juce::Colour colour):
    colour1(colour),
    point1(colour1),point2(colour1),point3(colour1),
    point4(colour1),point5(colour1),point6(colour1),
    point7(colour1), point8(colour1)
    {
        setFramesPerSecond(30);
        
    }
    
    void update() override
    {
       
        
    }
    
    
    
    
    void paint(juce::Graphics& g )override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::white);
        g.drawRect(0,0,getWidth(),getHeight());
    }

private:
    juce::Colour colour1;
    Points point1,point2,point3,point4,point5,point6,point7,point8;
     
};
