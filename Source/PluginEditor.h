/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/AdsrComponent.h"
#include "UI/LfoComponent.h"
#include "UI/ReverbComponent.h"
#include "UI/MeterComponent.h"
#include "UI/Assets.h"

//==============================================================================
/**
*/
class TapSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
, public juce::Timer
{
public:
    TapSynthAudioProcessorEditor (TapSynthAudioProcessor&);
    ~TapSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;
    
    juce::Colour blue      = juce::Colour::fromFloatRGBA (0.43f, 0.83f, 1.0f, 1.0f);
    juce::Colour green     = juce::Colour::fromFloatRGBA (0.34f, 0.74f, 0.66f, 1.0f);
    juce::Colour yellow    = juce::Colour::fromFloatRGBA (1.0f,  0.71f, 0.2f,  1.0f);
    juce::Colour offWhite  = juce::Colour::fromFloatRGBA (0.83f, 0.84f, 0.9f, 1.0f);
    juce::Colour grey      = juce::Colour::fromFloatRGBA (0.42f, 0.42f, 0.42f, 1.0f);
    juce::Colour black     = juce::Colour::fromFloatRGBA (0.08f, 0.08f, 0.08f, 1.0f);
private:
    TapSynthAudioProcessor& audioProcessor;
    OscComponent osc1;
    OscComponent osc2;
    FilterComponent filter;
    AdsrComponent adsr;
    LfoComponent lfo1;
    AdsrComponent filterAdsr;
    ReverbComponent reverb;
    MeterComponent meter;
    juce::ImageComponent logo;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapSynthAudioProcessorEditor)
};
