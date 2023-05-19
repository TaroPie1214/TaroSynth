#include <JuceHeader.h>
#include "OscComponent.h"

OscComponent::OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmFreqId, juce::String fmDepthId, juce::Colour colour)
: gain ("Gain", gainId, apvts, dialWidth, dialHeight, colour)
, pitch ("Pitch", pitchId, apvts, dialWidth, dialHeight, colour)
, fmFreq ("FM Freq", fmFreqId, apvts, dialWidth, dialHeight, colour)
, fmDepth ("FM Depth", fmDepthId, apvts, dialWidth, dialHeight, colour)
{
    //gain.setColour (juce::Slider::rotarySliderFillColourId, colour);
    
    juce::StringArray oscChoices { "Sine", "Saw", "Square" };
    oscSelector.addItemList (oscChoices, 1);
    oscSelector.setSelectedItemIndex (0);
    addAndMakeVisible (oscSelector);

    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscId, oscSelector);

    addAndMakeVisible (gain);
    addAndMakeVisible (pitch);
    addAndMakeVisible (fmFreq);
    addAndMakeVisible (fmDepth);
    
//    gain.setColour (juce::Slider::rotarySliderFillColourId, blue);
//    pitch.setColour (juce::Slider::rotarySliderFillColourId, blue);
//    fmFreq.setColour (juce::Slider::rotarySliderFillColourId, blue);
//    fmDepth.setColour (juce::Slider::rotarySliderFillColourId, blue);
}

//OscComponent::OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmFreqId, juce::String fmDepthId)
//: gainSliderAttachment (apvts, "Gain", gain)
//, pitchSliderAttachment (apvts, "Pitch", pitch)
//, fmFreqSliderAttachment (apvts, "FM Freq", fmFreq)
//, fmDepthSliderAttachment (apvts, "FM Depth", fmDepth)
//{
//    juce::StringArray oscChoices { "Sine", "Saw", "Square" };
//    oscSelector.addItemList (oscChoices, 1);
//    oscSelector.setSelectedItemIndex (0);
//    addAndMakeVisible (oscSelector);
//
//    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscId, oscSelector);
//
//    addAndMakeVisible (gain);
//    addAndMakeVisible (pitch);
//    addAndMakeVisible (fmFreq);
//    addAndMakeVisible (fmDepth);
//}

OscComponent::~OscComponent()
{
}


void OscComponent::resized()
{
    const auto yStart = 15;
    //const auto width = 70;
    //const auto height = 88;
    
    oscSelector.setBounds (18, 40, 100, 25);
    gain.setBounds (140, yStart, dialWidth, 88);
    pitch.setBounds (220, yStart, dialWidth, 88);
    fmFreq.setBounds (300, yStart, dialWidth, 88);
    fmDepth.setBounds (380, yStart, dialWidth, 88);
}
