/*
  ==============================================================================

    ReverbVisual.h
    Created: 6 Nov 2022 11:02:41pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "Points.h"
#include "Rectangle.h"
class ReverbVisual: public juce::Component,public juce::Timer
{
public:
    ReverbVisual(juce::Colour colour,const float* setX,const float* addX, const float* addY):
    paintcolour(colour)
    {
        for (int i = 0; i < 8; i++)
        {
            points[i].setOffsetX(setX[i]);
            points[i].addOffsetX(addX[i]);
            points[i].setOffsetY(addY[i]);
            
        }
        setInterceptsMouseClicks(true, true);
        startTimerHz(33);
    }
    ~ReverbVisual()
    {
      
    }
    
    void timerCallback() override
    {
        repaint();
        
    }
   
    void resized() override
    {
      
       
    }
    
    void mouseMove(const juce::MouseEvent &event) override
    {
            
    }
    void mouseExit(const juce::MouseEvent &event) override
    {
        colour1 = juce::Colours::white;
        for(auto& point : points)
        {
            point.exit();
        }
    }
    void mouseDrag (const juce::MouseEvent &event) override
    {
        
        x1 =   juce::jlimit(5, getWidth() - 35, event.getPosition().getX());
        y1 = juce::jlimit(5, getHeight() - 35, event.getPosition().getY());
        for(auto& point : points)
        {
        point.getX(( float(x1) -0.01f) / (float(getWidth()) - 35.f));
            
        }
       
    }
    
    void mouseEnter(const juce::MouseEvent &event) override
    {
        colour1 = paintcolour;
        for(auto& point : points)
        {
            point.entered(colour1);
        }
        
    }
    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::white);
        g.drawRect(0,0,getWidth(),getHeight());
        for(auto& point : points)
        {
            point.paint(g);
        }
        
        
        g.setColour(colour1);
        g.drawRect(x1, y1, 30, 30);
    }
    
    std::array<Points,8> points;
    
private:
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    int x1 = 20;
    int y1 = 20;
};
