/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapSynthAudioProcessorEditor::TapSynthAudioProcessorEditor (TapSynthAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc1 (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH", "OSC1FMFREQ", "OSC1FMDEPTH", yellow)
, osc2 (audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH", "OSC2FMFREQ", "OSC2FMDEPTH", yellow)
, filter (audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRESONANCE", green)
, adsr (audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE", green)
, lfo1 (audioProcessor.apvts, "LFO1FREQ", "LFO1DEPTH", green)
, filterAdsr (audioProcessor.apvts, "FILTERATTACK", "FILTERDECAY", "FILTERSUSTAIN", "FILTERRELEASE", green)
, reverb (audioProcessor.apvts, "REVERBSIZE", "REVERBDAMPING", "REVERBWIDTH", "REVERBDRY", "REVERBWET", "REVERBFREEZE", blue)
, meter (audioProcessor)
{
    //auto tapImage = juce::ImageCache::getFromMemory (BinaryData::tapLogo_png, BinaryData::tapLogo_pngSize);
    
    //if (tapImage.isValid())
    //    logo.setImage (tapImage, juce::RectanglePlacement::stretchToFit);
    //else
    //    jassertfalse;
    
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (filter);
    addAndMakeVisible (adsr);
    addAndMakeVisible (lfo1);
    addAndMakeVisible (filterAdsr);
    addAndMakeVisible (reverb);
    addAndMakeVisible (meter);
    addAndMakeVisible (logo);
    
    osc1.setName ("Oscillator 1");
    osc2.setName ("Oscillator 2");
    filter.setName ("Filter");
    lfo1.setName ("Filter LFO");
    filterAdsr.setName ("Filter ADSR");
    adsr.setName ("ADSR");
    meter.setName ("Meter");
    
    auto oscColour = juce::Colour::fromRGB (247, 190, 67);
    auto filterColour = juce::Colour::fromRGB (246, 87, 64);
    
    osc1.setBoundsColour (oscColour);
    osc2.setBoundsColour (oscColour);
    adsr.setBoundsColour (oscColour);
    
    filterAdsr.setBoundsColour (filterColour);
    filter.setBoundsColour (filterColour);
    lfo1.setBoundsColour (filterColour);
        
    reverb.setBoundsColour (blue);
    
    startTimerHz (30);
    setSize (1120, 630);
}

TapSynthAudioProcessorEditor::~TapSynthAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void TapSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(50.0f);
    g.drawSingleLineText("Version beta 0.0.0.0.0.1", 500, 570);
}

void TapSynthAudioProcessorEditor::resized()
{
    const auto oscWidth = 470;
    const auto oscHeight = 120;
    osc1.setBounds (0, 0, oscWidth, oscHeight);
    osc2.setBounds (oscWidth, 0, oscWidth, oscHeight);
    adsr.setBounds (0, osc1.getBottom(), 470, 360);
    filterAdsr.setBounds (adsr.getRight(), osc2.getBottom(), 470, 360);
    filter.setBounds (osc2.getRight(), 0, 180, 200);
    lfo1.setBounds (osc2.getRight(), filter.getBottom(), 180, 160);
    reverb.setBounds (0, adsr.getBottom(), oscWidth, 150);
    //meter.setBounds (reverb.getRight(), osc2.getBottom(), filterAdsr.getWidth() + lfo1.getWidth(), 150);
    //logo.setBounds (meter.getRight(), osc2.getBottom() + 30, 250, 100);
}

void TapSynthAudioProcessorEditor::timerCallback()
{
    repaint();
}
