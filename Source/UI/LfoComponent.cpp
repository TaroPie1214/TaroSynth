#include <JuceHeader.h>
#include "LfoComponent.h"

//==============================================================================
LfoComponent::LfoComponent (juce::AudioProcessorValueTreeState& apvts, juce::String lfoFreqId, juce::String lfoDepthId, juce::Colour colour)
: lfoFreq ("LFO Freq", lfoFreqId, apvts, dialWidth, dialHeight, colour)
, lfoDepth ("LFO Depth", lfoDepthId, apvts, dialWidth, dialHeight, colour)
{
    addAndMakeVisible (lfoFreq);
    addAndMakeVisible (lfoDepth);
}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::resized()
{
    const auto width = 70;
    const auto height = 88;
    const auto startY = 40;
        
    lfoFreq.setBounds (18, startY, width, height);
    lfoDepth.setBounds (90, startY, width, height);
}

