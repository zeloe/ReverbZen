/*
  ==============================================================================

    ReverbVisual.h
    Created: 6 Nov 2022 11:02:41pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "Points.h"
class ReverbVisual: public juce::Component,public juce::Timer
{
public:
    ReverbVisual(
                 //color for painting
                 juce::Colour colour,
                 // constants of arrays for each position see GuiDefines.h
                 const float* setX,
                 const float* addX,
                 const float* setY,
                 const float* addY,
                 // parameters from audioprocessorvaluetreestate = (treeState)
                 juce::RangedAudioParameter* _x1,
                 juce::RangedAudioParameter* _y1
                ):
    // initialise private ranged audio parameters
    x1(* _x1),
    y1(* _y1),
    // get the attachment and repaint
    attachX1(x1,[this](float){repaint();},nullptr),
    attachY1(y1,[this](float){repaint();},nullptr),
    paintcolour(colour)
    {
        // send update when gui is construced
        attachX1.sendInitialUpdate();
        attachY1.sendInitialUpdate();
        // to be sure that parent and child components get mouse information
        setInterceptsMouseClicks(true, true);
        // save some cpu
        startTimerHz(33);
        // initialise each point with offsets
        for (int i = 0; i < 8; i++)
        {
            // offset to be multiplied with x position
            points[i].setOffsetX(setX[i]);
            // offset to be added to x position
            points[i].addOffsetX(addX[i]);
            // offset to be multiplied with y position
            points[i].setOffsetY(setY[i]);
            // offset to be added to y position
            points[i].addOffsetY(addY[i]);
            // scale and set x position
            points[i].getX(x1.getValue() - 0.01f);
            // scale and set y position
            points[i].getY(y1.getValue() - 0.01f);
            // add points to be visible
            addAndMakeVisible(points[i]);
        }
     
      
    }
    ~ReverbVisual()
    {
    }
    
    void timerCallback() override
    {
        // gets repainted every 33  Hz as set in  startTimerHz(33);
        repaint();
        
    }
    // mouse listener function when mouse exits this component
    void mouseExit(const juce::MouseEvent &event) override
    {
        // set colour to white when you are outside of this component
        colour1 = juce::Colours::white;
        // apply exit function to every point (paint them white)
        for(auto& point : points)
        {
            point.exit();
        }
        
    }
    void mouseDrag (const juce::MouseEvent &event) override
    {
        // begin gesture of moving and saving parameter
        attachX1.beginGesture();
        attachY1.beginGesture();
        
        // set value x
        x1.setValueNotifyingHost((float(event.getPosition().getX())) / (float(getLocalBounds().getWidth())));
        // set value y
        y1.setValueNotifyingHost((float(event.getPosition().getY())) / (float(getLocalBounds().getHeight())));
        
        // end gesture of moving
        attachX1.endGesture();
        attachY1.endGesture();
       
    }
    
    void mouseEnter(const juce::MouseEvent &event) override
    {
        // paint this component when mouse enters
        colour1 = paintcolour;
        // apply exit function to every point (paint them to color set inside constructor)
        for(auto& point : points)
        {
            point.entered(colour1);
        }
        
    }
    void paint(juce::Graphics& g) override
    {
        // fill all black
        g.fillAll(juce::Colours::black);
        // set colour to white
        g.setColour(juce::Colours::white);
        // draw a rectangle with white color and get this component width and height
        g.drawRect(0,0,getWidth(),getHeight());
        // paint points
        for(auto& point : points)
        {
            point.paint(g);
        }
        
        // set colour
        g.setColour(colour1);
        // get x value and y value of ranged audio parameter and scale them to size of component
        
        g.drawRect(juce::jlimit(5.f /* to not exit bounds   */, float(getLocalBounds().getWidth()) - float(xyrect.getWidth() + 5.f) /* get size of rectangle plus 5 pixel to not exit bounds  */, x1.getValue() * (float(getLocalBounds().getWidth()))),
                   // same for y
                   juce::jlimit(5.f, float(getLocalBounds().getHeight()) -float(xyrect.getHeight() + 5.f), y1.getValue() * (float(getLocalBounds().getHeight()))),float(getLocalBounds().getWidth() / 10) , float(getLocalBounds().getWidth() / 10));
        // set x and y values for all points
        for(auto& point : points)
        {
        point.getX(x1.getValue() -0.01f);
        point.getY(y1.getValue() - 0.01f);
        }
    }
    
    void resized() override
    {
        // window can be resized and points are in relationship with main plugin window
        for(auto& point : points)
        {
            point.setBounds((float(x1.getValue()) -0.01f),float(y1.getValue() -0.01f), float(getLocalBounds().getWidth() / 25) ,float(getLocalBounds().getHeight() / 25));
        }
        // window can be resized and rectangle are in relationship with main plugin window
        xyrect.setBounds(juce::jlimit(5.f, float(getLocalBounds().getWidth()) - 35.f, x1.getValue() * (float(getLocalBounds().getWidth()))),
        juce::jlimit(5.f, float(getLocalBounds().getHeight()) - 35.f, y1.getValue() * (float(getLocalBounds().getHeight()))), float(getLocalBounds().getWidth() / 10), float(getLocalBounds().getHeight() / 10));
    }
   
    
    // points
    std::array<Points,8> points;
    // parameters
    juce::RangedAudioParameter &x1,&y1;
    // attachments
    juce::ParameterAttachment attachX1,attachY1;
private:
    juce::Rectangle <float> xyrect;
    juce::Colour colour1 = juce::Colours::white;
    juce::Colour paintcolour;
    float x1u;
    float y1u;
    float size = 30;
    
    
};
