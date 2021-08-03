/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"

//==============================================================================
/**
*/
class TaroSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TaroSynthAudioProcessorEditor (TaroSynthAudioProcessor&);
    ~TaroSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    TaroSynthAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TaroSynthAudioProcessorEditor)
};
