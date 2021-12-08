#pragma once

#include <JuceHeader.h>
#include "CustomComponent.h"
#include "ModernDial.h"

//==============================================================================
/*
*/
class OscComponent : public CustomComponent
{
public:
    OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmPitchId, juce::String fmFreqId, juce::Colour colour);
    ~OscComponent() override;

    void resized() override;

private:
    juce::ComboBox oscSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    
    SliderWithLabel gain;
    SliderWithLabel pitch;
    SliderWithLabel fmFreq;
    SliderWithLabel fmDepth;
    
//    ModernDial gain;
//    ModernDial pitch;
//    ModernDial fmFreq;
//    ModernDial fmDepth;
    
//    juce::AudioProcessorValueTreeState::SliderAttachment gainSliderAttachment,
//                                                         pitchSliderAttachment,
//                                                         fmFreqSliderAttachment,
//                                                         fmDepthSliderAttachment;
    
    static constexpr int dialWidth = 70;
    static constexpr int dialHeight = 70;
    
    juce::Colour blue = juce::Colour::fromFloatRGBA (0.43f, 0.83f, 1.0f, 1.0f);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
