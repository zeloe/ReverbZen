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
                 const float* setY,
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
            points[i].setOffsetY(setY[i]);
            points[i].addOffsetY(addY[i]);
            points[i].getX(x1.getValue() - 0.01f);
            points[i].getY(y1.getValue() - 0.01f);
            addAndMakeVisible(points[i]);
        }
     
      
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
        
    
        x1.setValueNotifyingHost((float(event.getPosition().getX())) / (float(getLocalBounds().getWidth())));
        y1.setValueNotifyingHost((float(event.getPosition().getY())) / (float(getLocalBounds().getHeight())));
        
        
        attachX1.endGesture();
        attachY1.endGesture();
       
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
        g.drawRect(juce::jlimit(5.f, float(getLocalBounds().getWidth()) - float(xyrect.getWidth() + 5.f), x1.getValue() * (float(getLocalBounds().getWidth()))),
                   juce::jlimit(5.f, float(getLocalBounds().getHeight()) -float(xyrect.getHeight() + 5.f), y1.getValue() * (float(getLocalBounds().getHeight()))),float(getLocalBounds().getWidth() / 10) , float(getLocalBounds().getWidth() / 10));
        for(auto& point : points)
        {
        point.getX(x1.getValue() -0.01f);
        point.getY(y1.getValue() - 0.01f);
        }
    }
    
    void resized() override
    {
        for(auto& point : points)
        {
            point.setBounds((float(x1.getValue()) -0.01f),float(y1.getValue() -0.01f), float(getLocalBounds().getWidth() / 25) ,float(getLocalBounds().getHeight() / 25));
        }
        xyrect.setBounds(juce::jlimit(5.f, float(getLocalBounds().getWidth()) - 35.f, x1.getValue() * (float(getLocalBounds().getWidth()))),
        juce::jlimit(5.f, float(getLocalBounds().getHeight()) - 35.f, y1.getValue() * (float(getLocalBounds().getHeight()))), float(getLocalBounds().getWidth() / 10), float(getLocalBounds().getHeight() / 10));
    }
   
    
    
    std::array<Points,8> points;
    juce::RangedAudioParameter &x1,&y1;
    juce::ParameterAttachment attachX1,attachY1;
private:
    juce::Rectangle <float> xyrect;
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    float x1u;
    float y1u;
    float size = 30;
    
    
};
