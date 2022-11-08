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
    Points()
    {
    //   setInterceptsMouseClicks(true, false);
    }
    ~Points()
    {
        
    };
    
    
    void paint(juce::Graphics& g)override
    {
        g.setColour(colour1);
        g.fillEllipse(setx(),sety(),20 ,20);
        g.drawEllipse(setx(),sety(),20 ,20,20);
    }
    
    
    void getX(int x)
    {
        posX = x;
    }
    
    void getY(int y)
    {
        posY = y;
    }
    
    
    float setx()
    {
        return posX;
    }
    float sety()
    {
        return posY;
    }
    
    
    void mousePos(float x, float y)
    {
         getX(x);
         getY(y);
        
    }
   
    
    void entered(const juce::Colour paintcolor)
    {
        colour1 = paintcolor;
    }
    void exit()
    {
        colour1 = juce::Colours::white;
    }
private:
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolor;
    float posX = 80;
    float posY = 80;
    int size = 20;
    
};
