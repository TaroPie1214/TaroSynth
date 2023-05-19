#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"
#include "CustomComponent.h"

//==============================================================================
/*
*/
class MeterComponent  : public CustomComponent
{
public:
    MeterComponent (TapSynthAudioProcessor& p);
    ~MeterComponent() override;

    void paintOverChildren (juce::Graphics& g) override;
    void resized() override;

private:
    TapSynthAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterComponent)
};
