/*
  ==============================================================================

    Zen_Knob.h
    Created: 21 Feb 2022 1:47:37pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Zen_LookAndFeel.h"
namespace juce {

class Zen_Knob : public Slider
{
public:
    Zen_Knob(String suffix,
             double rangeStart,
             double rangeEnd,
             double intervalValue,
             double returnValue);
    ~Zen_Knob() override;
    enum class ZenStyles
    {
      greenknob,
      redknob,
      blueknob,
      whiteknob,
      brownknob,
      lightblueknob,
      blackknob
    };
    void setStyles(ZenStyles styles);
private:
    
    void mouseEnter(const MouseEvent& event) override;
    void mouseExit(const MouseEvent& event) override;
    void initProps(String suffix,
                   double rangeStart,
                   double rangeEnd,
                   double intervalValue,
                   double returnValue);
    Zen_GreenKnob GreenStyle;
    Zen_RedKnob RedStyle;
    Zen_BlueKnob BlueStyle;
    Zen_WhiteKnob WhiteStyle;
    Zen_BrownKnob BrownStyle;
    Zen_LightBlueKnob LightBlueStyle;
    Zen_BlackKnob  BlackStyle;
};
}

