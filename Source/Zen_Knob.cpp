/*
  ==============================================================================

    Zen_Knob.cpp
    Created: 22 Feb 2022 1:58:10pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#include "Zen_Knob.h"
namespace juce {
Zen_Knob::Zen_Knob(String suffix,
                   double rangeStart,
                   double rangeEnd,
                   double intervalValue,
                   double returnValue)
{
    initProps(suffix, rangeStart, rangeEnd, intervalValue, returnValue);
}

Zen_Knob::~Zen_Knob()
{
    setLookAndFeel(nullptr);
}


void Zen_Knob::initProps(String suffix,
               double rangeStart,
               double rangeEnd,
               double intervalValue,
               double returnValue)
{
    setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    setTextBoxStyle(TextBoxBelow, false, 100, 50);
    
    
}

void Zen_Knob::setStyles(ZenStyles styles)
{
    switch (styles) {
        case ZenStyles::greenknob:
            
                setLookAndFeel(&GreenStyle);
            
            break;
            
        case ZenStyles::redknob:
            
                setLookAndFeel(&RedStyle);
            
            break;
            
        case ZenStyles::blueknob:
            
            setLookAndFeel(&BlueStyle);
            break;
        
        case ZenStyles::whiteknob:
            
            setLookAndFeel(&WhiteStyle);
            break;
            
        case ZenStyles::brownknob:
            setLookAndFeel(&BrownStyle);
            break;
            
        case ZenStyles::lightblueknob:
            setLookAndFeel(&LightBlueStyle);
            break;
        case ZenStyles::blackknob:
            setLookAndFeel(&BlackStyle);
            break;
            
    }
    
    
}
void Zen_Knob::mouseEnter(const MouseEvent& event)
{
    setColour(ColourIds::textBoxTextColourId, findColour(Slider::ColourIds::textBoxTextColourId).withAlpha(1.0f));
    
    
}
void Zen_Knob::mouseExit(const MouseEvent& event)
{
    setColour(ColourIds::textBoxTextColourId, findColour(Slider::ColourIds::textBoxTextColourId).withAlpha(0.5f));
}

}


