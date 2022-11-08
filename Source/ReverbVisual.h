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
    ReverbVisual(juce::Colour colour,
                 const float* setX,
                 const float* addX,
                 const float* addY,
                 juce::RangedAudioParameter* _x1,
                 juce::RangedAudioParameter* _y1
                ):
    x1(* _x1),
    y1(* _y1),
    attachX1(x1,[this](float){repaint();},nullptr),
    attachY1(y1,[this](float){repaint();},nullptr),
    paintcolour(colour)
    {
        attachX1.sendInitialUpdate();
        attachY1.sendInitialUpdate();
        
        
        setInterceptsMouseClicks(true, true);
        startTimerHz(33);
        for (int i = 0; i < 8; i++)
        {
            points[i].setOffsetX(setX[i]);
            points[i].addOffsetX(addX[i]);
            points[i].getY(addY[i]);
            points[i].getX(x1.getValue() - 0.01f);
        }
        x1u =  juce::jlimit(5, 300 - 35, int(x1.getValue()) * 300);
        y1u =   juce::jlimit(5, 200 - 35, int(y1.getValue() * 200));
        DBG("INIT");
        DBG(x1u);
        DBG(y1u);
        DBG(x1.getValue());
        DBG(y1.getValue());
        
    }
    ~ReverbVisual()
    {
      
    }
    
    void timerCallback() override
    {
        repaint();
        
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
        attachX1.beginGesture();
        attachY1.beginGesture();
        
        x1u = juce::jlimit(5, getWidth() - 35, event.getPosition().getX());
        y1u =juce::jlimit(5, getHeight() - 35, event.getPosition().getY());

        for(auto& point : points)
        {
        point.getX(( float(x1u) -0.01f) / (float(getWidth()) - 35.f));
            
        }
        x1.setValueNotifyingHost((float(x1u)) / (float(getWidth())));
        y1.setValueNotifyingHost((float(y1u)) / (float(getHeight())));
        attachX1.endGesture();
        attachY1.endGesture();
        DBG("////////");
        DBG(x1u);
        DBG(y1u);
        DBG(x1.getValue());
        DBG(y1.getValue());
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
        g.drawRect(x1u,y1u, 30, 30);
    }
    
    std::array<Points,8> points;
    juce::RangedAudioParameter &x1,&y1;
    juce::ParameterAttachment attachX1,attachY1;
private:
   
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    int x1u;
    int y1u;
};
