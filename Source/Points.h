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
    }
    ~Points()
    {
        
    };
    
    
    void paint(juce::Graphics& g)override
    {
       // setting colors
        g.setColour(colour1);
        // getting offsets and parent sizes. In this way it is possible to resize window.
        g.fillEllipse(((posX * offSetX) + addoffSetX) * float(getParentWidth() - getParentWidth() / 10),(((1.f -posY)* offSetY) + offaddSetY ) *(float(getParentHeight()- getParentHeight() / 10)),float(getParentWidth() / 25) ,float(getParentHeight() / 25));
    }
    
    
    void getX(float x)
    {
        // x position
        posX = x;
    }
    
    void getY(float y)
    {
        // y position
        posY = y;
    }
    
    void setOffsetY(float offsetY)
    {
        // factor to be multiplied with y position
        this->offSetY = offsetY;
    }
    
    void addOffsetY(float offsetY)
    {
        // factor to be added to y position
        this->offaddSetY = offsetY;
    }
    
    void setOffsetX(float offsetX)
    {
        // factor to be multiplied with x position
        this->offSetX = offsetX;
    }
    
    void addOffsetX(float offsetX)
    {
        // factor to be added to x position
        this->addoffSetX = offsetX;
    }
    
    void entered(const juce::Colour paintcolor)
    {
        // color when mouse enters
        colour1 = paintcolor;
    }
    void exit()
    {
        // color when mouse exits
        colour1 = juce::Colours::white;
    }
private:
    juce::Rectangle<float> rect;
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolor;
    float posX;
    float posY;
    float offSetY;
    float offSetX ;
    float addoffSetX;
    float offaddSetY;
    
};
