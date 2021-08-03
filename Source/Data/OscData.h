/*
  ==============================================================================

    OscData.h
    Created: 27 Jul 2021 11:26:16pm
    Author:  香芋派Taro

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay (juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void setWaveFrequency (const int midiNoteNumber);
    void getNextAudioBlock (juce::dsp::AudioBlock<float>& block);
    
private:
    
};

