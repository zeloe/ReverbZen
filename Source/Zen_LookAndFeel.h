/*
  ==============================================================================

    Zen_LookAndFeel.h
    Created: 22 Feb 2022 7:39:26pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
namespace juce
{
class Zen_GreenKnob : public LookAndFeel_V4
{
public:
    Zen_GreenKnob();
    ~Zen_GreenKnob();
    
   
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};
class Zen_RedKnob : public LookAndFeel_V4
{
public:
    Zen_RedKnob();
    ~Zen_RedKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};

class Zen_BlueKnob : public LookAndFeel_V4
{
public:
    Zen_BlueKnob();
    ~Zen_BlueKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};


class Zen_WhiteKnob : public LookAndFeel_V4
{
public:
    Zen_WhiteKnob();
    ~Zen_WhiteKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};
class Zen_BrownKnob : public LookAndFeel_V4
{
public:
    Zen_BrownKnob();
    ~Zen_BrownKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};

class Zen_LightBlueKnob : public LookAndFeel_V4
{
    
public:
    Zen_LightBlueKnob();
    ~Zen_LightBlueKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};

class Zen_BlackKnob : public LookAndFeel_V4
{
    
public:
    Zen_BlackKnob();
    ~Zen_BlackKnob();
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
};





}
