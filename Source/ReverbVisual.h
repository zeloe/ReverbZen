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
        x1u = int(x1.getValue() * (300.f -35.f));
        y1u = int(y1.getValue() * (200.f - 35.f)); 
        DBG("INIT");
        DBG(x1u);
        DBG(y1u);
        DBG(x1.getValue());
        DBG(y1.getValue());
        DBG("/////");
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
        
        x1u = juce::jlimit(5.f, float(300.f) - 35.f, float(event.getPosition().getX()));
        y1u =juce::jlimit(5.f, float(200.f) - 35.f, float(event.getPosition().getY()));
        for(auto& point : points)
        {
        point.getX(( float(x1u) -0.01f) / (float(300.f) - 35.f));
            
        }
        x1.setValueNotifyingHost((float(x1u)) / (float(300.f) -35.f));
        y1.setValueNotifyingHost((float(y1u)) / (float(200.f) -35.f));
        attachX1.endGesture();
        attachY1.endGesture();
        DBG("SET");
        DBG(x1u);
        DBG(y1u);
        DBG(x1.getValue());
        DBG(y1.getValue());
        DBG("///////");
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
        g.drawRect(x1u,y1u, size, size);
    }
    
    std::array<Points,8> points;
    juce::RangedAudioParameter &x1,&y1;
    juce::ParameterAttachment attachX1,attachY1;
private:
   
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    float x1u;
    float y1u;
    float size = 30;
};
