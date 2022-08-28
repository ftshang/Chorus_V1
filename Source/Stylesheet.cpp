/*
  ==============================================================================

    Stylesheet.cpp
    Created: 27 Aug 2022 3:38:11pm
    Author:  tatao

  ==============================================================================
*/

#include "Stylesheet.h"

CustomDial::CustomDial()
{

}

void CustomDial::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
    auto diameter = juce::jmin(width, height) * 0.74f;
    auto radius = diameter * 0.5f;
    auto centerX = x + width * 0.5f;
    auto centerY = y + height * 0.5f;
    auto rectangleX = centerX - radius;
    auto rectangleY = centerY - radius;
    auto angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));

    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = juce::jmin(8.0f, radius * 0.5f);
    auto arcRadius = radius - lineW * 0.5f;

    auto outline = slider.findColour(juce::Slider::rotarySliderOutlineColourId);
    auto fill = slider.findColour(juce::Slider::rotarySliderFillColourId);
    auto bounds = juce::Rectangle<int>(x, y, width, height).toFloat();

    juce::Rectangle<float> dialArea(rectangleX, rectangleY, diameter, diameter);
    // Center
    g.setColour(juce::Colours::black.brighter(0.4f));
    g.fillEllipse(dialArea);

    // Outline
    g.setColour(juce::Colours::black.withAlpha(0.1f));
    g.drawEllipse(rectangleX, rectangleY, diameter, diameter, 10.0f);

    juce::Path dialTick;
    g.setColour(juce::Colours::whitesmoke.darker(0.5f));
    dialTick.addRoundedRectangle(0, -radius + 6, 5.88f, radius * 0.6, 5.f, 5.f, true, true, true, true);
    g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(centerX, centerY));

    shadowProperties.radius = 24;
    shadowProperties.offset = juce::Point<int>(-1, 4);
    shadowProperties.colour = juce::Colours::black.withAlpha(0.9f);
    dialShadow.setShadowProperties(shadowProperties);
    slider.setComponentEffect(&dialShadow);
}
