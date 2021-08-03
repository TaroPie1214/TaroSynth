/*
  ==============================================================================

    OscData.cpp
    Created: 27 Jul 2021 11:26:16pm
    Author:  香芋派Taro

  ==============================================================================
*/

#include "OscData.h"
void OscData::prepareToPlay (juce::dsp::ProcessSpec& spec)
{
    prepare (spec);
}

void OscData::setWaveType (const int choice)
{
    switch (choice)
    {
        case 0:
            //Sine
            initialise ([](float x) { return std::sin(x); });
            break;
            
        case 1:
            //Saw Wave
            initialise ([](float x) { return x / juce::MathConstants<float>::pi; });
            break;
            
        case 2:
            //Square Wave
            initialise ([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            jassertfalse;
            break;
    }
}

void OscData::setWaveFrequency (const int midiNoteNumber)
{
    setFrequency (juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber));
}

void OscData::getNextAudioBlock (juce::dsp::AudioBlock<float>& block)
{
    process (juce::dsp::ProcessContextReplacing<float> (block));
}
