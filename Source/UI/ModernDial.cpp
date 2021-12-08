#include "ModernDial.h"

ModernDial::ModernDial()
{
    setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    setRotaryParameters (juce::MathConstants<float>::pi * 1.25f,
                         juce::MathConstants<float>::pi * 2.75f,
                         true);
    
    setColour (juce::Slider::textBoxTextColourId, blackGrey);
    setColour (juce::Slider::textBoxOutlineColourId, grey);
    //设定好文本框的颜色，并为接下来的focus mark做好准备（focus mark就是把鼠标移到旋钮上四周会出现的那个矩形框的四个角）
    
    setLookAndFeel (&customLookAndFeel);
    //将LookAndFeel应用至旋钮对象，调用此函数
    setVelocityBasedMode (true);
    setVelocityModeParameters (0.5, 1, 0.09, false);
    setRange (0.0, 100.0, 0.01);
    setValue (50.0);
    setDoubleClickReturnValue (true, 50.0); //双击恢复默认值
    
    setWantsKeyboardFocus (true); //Focus Mark，这个函数必须被调用
    
    //setTextValueSuffix (" %");
    onValueChange = [&]() //lambda表达式
    {
        if (getValue() < 10)
            setNumDecimalPlacesToDisplay (2);
        else if (10 <= getValue() && getValue() < 100)
            setNumDecimalPlacesToDisplay (1);
        else
            setNumDecimalPlacesToDisplay (0);
    };
    //当slider的值发生变化的时候会被执行，他确保了slider在任何值时都会被正常显示（宽度不变）
}

ModernDial::~ModernDial()
{
}

void ModernDial::paint (juce::Graphics& g)
{
    juce::Slider::paint (g);

    if (hasKeyboardFocus (false))
    {
        auto bounds = getLocalBounds().toFloat();
        auto h = bounds.getHeight();
        auto w = bounds.getWidth();
        auto len = juce::jmin (h, w) * 0.07f;
        auto thick  = len / 1.8f;
        
        g.setColour (findColour (juce::Slider::textBoxOutlineColourId));
        
        // Left top
        g.drawLine (0.0f, 0.0f, 0.0f, len, thick);
        g.drawLine (0.0f, 0.0f, len, 0.0f, thick);
        
        // Left bottom
        g.drawLine (0.0f, h, 0.0f, h - len, thick);
        g.drawLine (0.0f, h, len, h, thick);
        
        // Right top
        g.drawLine (w, 0.0f, w, len, thick);
        g.drawLine (w, 0.0f, w - len, 0.0f, thick);
        
        // Right bottom
        g.drawLine (w, h, w, h - len, thick);
        g.drawLine (w, h, w - len, h, thick);
    }
}

void ModernDial::mouseDown (const juce::MouseEvent& event)
{
    juce::Slider::mouseDown (event);

    setMouseCursor (juce::MouseCursor::NoCursor);
}
//鼠标点下的瞬间被隐藏

void ModernDial::mouseUp (const juce::MouseEvent& event)
{
    juce::Slider::mouseUp (event);

    juce::Desktop::getInstance().getMainMouseSource().setScreenPosition (event.source.getLastMouseDownPosition());
    
    setMouseCursor (juce::MouseCursor::NormalCursor);
}
//鼠标被释放时还在点击时的位置，位置不受拖动的影响
