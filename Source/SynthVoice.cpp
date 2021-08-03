/*
  ==============================================================================

    SynthVoice.cpp
    Created: 13 Jul 2021 1:05:37pm
    Author:  香芋派Taro

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound)
//如果可以运行，返回true
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    osc.setWaveFrequency (midiNoteNumber);
    adsr.noteOn();
}

void SynthVoice::stopNote (float velocity, bool allowTailOff)
{
    adsr.noteOff();
    
    if (! allowTailOff || ! adsr.isActive())
        clearCurrentNote();
}

void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue)
{
    
}

void SynthVoice::pitchWheelMoved (int newPitchWheelValue)
{
    
}

void SynthVoice::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    adsr.setSampleRate (sampleRate);
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    
    gain.prepare ( spec );
    
    osc.prepareToPlay (spec);
    gain.setGainLinear (0.01f);
    
    
    isPrepared = true;
}

void SynthVoice::update (const float attack, const float decay, const float sustain, const float release)
{
    adsr.update(attack, decay, sustain, release);
}

void SynthVoice::renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
{
    jassert (isPrepared);
    
    synthBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();
    
    juce::dsp::AudioBlock<float> audioBlock { synthBuffer };
    osc.getNextAudioBlock (audioBlock);
    gain.process(juce::dsp::ProcessContextReplacing<float> (audioBlock));
    
    adsr.applyEnvelopeToBuffer(outputBuffer, 0, synthBuffer.getNumSamples());
    
    for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
    {
        outputBuffer.addFrom (channel, startSample, synthBuffer, channel, 0, numSamples);
        
        if (! adsr.isActive())
            clearCurrentNote();
    }
}
