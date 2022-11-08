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
    ReverbVisual(juce::Colour colour):
    paintcolour(colour)
    {
        //maybe only call listener on child components
        setInterceptsMouseClicks(true, true);
        
       // points[0].addMouseListener(this, false);
        
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
        points[0].exit();
    }
    void mouseDrag (const juce::MouseEvent &event) override
    { //juce::jmap(<#Type sourceValue#>, <#Type sourceRangeMin#>, <#Type sourceRangeMax#>, <#Type targetRangeMin#>, <#Type targetRangeMax#>)
        x1 =   juce::jlimit(5, getWidth() - 35, event.getPosition().getX());
        y1 = juce::jlimit(5, getHeight() - 35, event.getPosition().getY());
        points[0].getX(( float(x1) -0.01f) / (float(getWidth()) - 35.f));
        //DBG( float(x1) / float(getWidth() - 35.f));
    }
    
    void mouseEnter(const juce::MouseEvent &event) override
    {
        colour1 = paintcolour;
        points[0].entered(colour1);
        
    }
    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::white);
        g.drawRect(0,0,getWidth(),getHeight());
        points[0].paint(g);
        g.setColour(colour1);
        g.drawRect(x1, y1, 30, 30);
    }
    
    std::array<Points,2> points;
    
private:
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    int x1 = 20;
    int y1 = 20;
};
