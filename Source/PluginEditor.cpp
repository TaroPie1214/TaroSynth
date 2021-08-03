/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TaroSynthAudioProcessorEditor::TaroSynthAudioProcessorEditor (TaroSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc (audioProcessor.apvts, "OSC1WAVETYPE") , adsr (audioProcessor.apvts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
}
    
TaroSynthAudioProcessorEditor::~TaroSynthAudioProcessorEditor()
{
}

//==============================================================================
void TaroSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void TaroSynthAudioProcessorEditor::resized()
{
    osc.setBounds (10, 10, 100, 30);
    adsr.setBounds (getWidth() / 2, 0, getWidth() / 2, getHeight());
}

