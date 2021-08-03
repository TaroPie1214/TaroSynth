/*
  ==============================================================================

    AdsrData.h
    Created: 20 Jul 2021 11:42:51pm
    Author:  香芋派Taro

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void update (const float attack, const float decay, const float sustain, const float release);
    
private:
    juce::ADSR::Parameters adsrParams;
};
