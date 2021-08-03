/*
  ==============================================================================

    SynthSound.h
    Created: 13 Jul 2021 1:06:09pm
    Author:  香芋派Taro

  ==============================================================================
*/
////https://docs.juce.com/master/classSynthesiserSound.html

#pragma once

#include <JuceHeader.h>


class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
    
}
;
