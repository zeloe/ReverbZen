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
    colour1(colour)
    {
        //maybe only call listener on child components
        setInterceptsMouseClicks(true, true);
        points[0].setAlwaysOnTop(true);
        points[0].addMouseListener(this, false);
        
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
        
        pos1.setBounds(points[0].setx(),points[0].sety(),40,40);
        
       
       if(event.getEventRelativeTo(&points[0]).eventComponent->getBounds().contains(event.getPosition()))
        {
            points[0].entered(colour1);
        } else {
            //not sure about this
            points[0].exit();
        }
        
    }
    void mouseExit(const juce::MouseEvent &event) override
    {
        
    }
    void mouseDrag (const juce::MouseEvent &event) override
    {
        if(event.getEventRelativeTo(&points[0]).eventComponent->getBounds().contains(event.getPosition()))
         {
             //not really working
             points[0].mousePos(event.getPosition().getX(), event.getPosition().getY());
             
         }
            
         
    }
    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::white);
        g.drawRect(0,0,getWidth(),getHeight());
        points[0].setBounds(points[0].setx(),points[0].sety(),20 ,20);
        points[0].paint(g);
    }
    
    std::array<Points,2> points;
    
private:
    
    Rect rect;
    juce::Colour colour1;
    int x1 = 20;
    int y1 = 20;
    juce::Rectangle<int> pos1;
    
     
};
