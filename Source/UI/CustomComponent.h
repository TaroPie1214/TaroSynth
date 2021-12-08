#pragma once

#include <JuceHeader.h>
#include "ModernDial.h"

//==============================================================================
/*
*/

static constexpr float fontHeight { 15.0f };

class SliderWithLabel : public juce::Component
{
public:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using SliderStyle = juce::Slider::SliderStyle;
    
    SliderWithLabel (juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts, const int width, const int height, juce::Colour colour, SliderStyle style = SliderStyle::RotaryHorizontalVerticalDrag);
        
    void resized() override;
    
private:
    static constexpr int textBoxWidth { 48 };
    static constexpr int textBoxHeight { 20 };
    int sliderWidth { 0 };
    int sliderHeight { 0 };
    //juce::Slider slider;
    ModernDial slider;
    juce::Label label;
    std::unique_ptr<SliderAttachment> attachment;
    
    juce::Colour blue      = juce::Colour::fromFloatRGBA (0.43f, 0.83f, 1.0f, 1.0f);
    juce::Colour green     = juce::Colour::fromFloatRGBA (0.34f, 0.74f, 0.66f, 1.0f);
    juce::Colour yellow    = juce::Colour::fromFloatRGBA (1.0f,  0.71f, 0.2f,  1.0f);
    juce::Colour offWhite  = juce::Colour::fromFloatRGBA (0.83f, 0.84f, 0.9f, 1.0f);
    juce::Colour grey      = juce::Colour::fromFloatRGBA (0.42f, 0.42f, 0.42f, 1.0f);
    juce::Colour black     = juce::Colour::fromFloatRGBA (0.08f, 0.08f, 0.08f, 1.0f);
};

class CustomComponent  : public juce::Component
{
public:
    CustomComponent();
    ~CustomComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setName (juce::String n) { name = n; }
    void setBoundsColour (juce::Colour c) { boundsColour = c; }

private:
    juce::String name { "" };
    juce::Colour boundsColour { juce::Colours::white };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomComponent)
};
