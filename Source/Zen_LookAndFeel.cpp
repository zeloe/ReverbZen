/*
  ==============================================================================

    Zen_LookAndFeel.cpp
    Created: 22 Feb 2022 7:39:26pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#include "Zen_LookAndFeel.h"
namespace juce
{
Zen_GreenKnob::Zen_GreenKnob()
{
}

Zen_GreenKnob::~Zen_GreenKnob()
{
}
void Zen_GreenKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    auto color =  juce::Colours::green;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
    
}
Zen_RedKnob::Zen_RedKnob()
{
}

Zen_RedKnob::~Zen_RedKnob()
{
}
void Zen_RedKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto color =  juce::Colours::red;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
}
Zen_BlueKnob::Zen_BlueKnob()
{
}

Zen_BlueKnob::~Zen_BlueKnob()
{
}
void Zen_BlueKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto color =  juce::Colours::blue;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
}

Zen_WhiteKnob::Zen_WhiteKnob()
{
}

Zen_WhiteKnob::~Zen_WhiteKnob()
{
}
void Zen_WhiteKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    auto color =  juce::Colours::white;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
}


Zen_BrownKnob::Zen_BrownKnob()
{
}

Zen_BrownKnob::~Zen_BrownKnob()
{
}
void Zen_BrownKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto color =  juce::Colours::brown;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
}


Zen_LightBlueKnob::Zen_LightBlueKnob()
{
}

Zen_LightBlueKnob::~Zen_LightBlueKnob()
{
}
void Zen_LightBlueKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    
    auto color =  juce::Colours::lightblue;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);
    
}
juce::Zen_BlackKnob::Zen_BlackKnob()
{
}

juce::Zen_BlackKnob::~Zen_BlackKnob()
{
}
void juce::Zen_BlackKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    
    auto color =  juce::Colours::black;
 

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (color);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (color);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
    }

    auto thumbWidth = lineW * 2.0f;
    Point<float> thumbPoint (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
    Line<float> thumbCenter (bounds.getCentreX()  + 0.8 *arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + 0.8* arcRadius * std::sin (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreX(), bounds.getCentreY());

    g.setColour (color);
    g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    Path sliderInternal;
    sliderInternal.addLineSegment(thumbCenter, lineW);
    g.fillPath(sliderInternal);
    //g.fillPath(sliderInternal,.);
   // g.fillRect(Rectangle<float>(bounds.getCentreX() / 2,bounds.getCentreY() /2).withCentre (thumbPoint));
  //  g.fillRect(thumbPoint.getX(),thumbPoint.getY(), 20,20);

    
    
}
}
