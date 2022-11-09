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
        g.setColour(colour1);
        g.fillEllipse(((posX * offSetX) + addoffSetX) * float(getParentWidth() - getParentWidth() / 10),(((1.f -posY)* offSetY) + offaddSetY ) *(float(getParentHeight()- getParentHeight() / 10)),float(getParentWidth() / 25) ,float(getParentHeight() / 25));
    }
    
    
    void getX(float x)
    {
        posX = x;
    }
    
    void getY(float y)
    {
        posY = y;
    }
    
    void setOffsetY(float offsetY)
    {
        this->offSetY = offsetY;
    }
    
    void addOffsetY(float offsetY)
    {
        this->offaddSetY = offsetY;
    }
    
    void setOffsetX(float offsetX)
    {
        this->offSetX = offsetX;
    }
    
    void addOffsetX(float offsetX)
    {
        this->addoffSetX = offsetX;
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
    juce::Rectangle<float> rect;
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolor;
    float posX;
    float posY;
    float size = 20;
    float offSetY;
    float offSetX ;
    float addoffSetX;
    float offaddSetY;
    
};
