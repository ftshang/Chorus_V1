/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Stylesheet.h"

//==============================================================================
/**
*/
class Chorus_V1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Chorus_V1AudioProcessorEditor (Chorus_V1AudioProcessor&);
    ~Chorus_V1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider rateDial;
    juce::Slider depthDial;
    juce::Slider centreDelayDial;
    juce::Slider feedbackDial;
    juce::Slider mixDial;

    juce::Label rateLabel;
    juce::Label depthLabel;
    juce::Label centreDelayLabel;
    juce::Label feedbackLabel;
    juce::Label mixLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Chorus_V1AudioProcessor& audioProcessor;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rateDialAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> depthDialAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> centreDelayDialAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackDialAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixDialAttachment;

    CustomDial customLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Chorus_V1AudioProcessorEditor)
};
