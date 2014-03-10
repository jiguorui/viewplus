/*
  ==============================================================================

    RealTimeValue.cpp
    Created: 10 Mar 2014 12:30:04pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "RealTimeValue.h"
RealTimeValue::RealTimeValue(SelectedItems* selectedItems) : BaseComponent(selectedItems)
{
	setSize(120, 50);
}
RealTimeValue::~RealTimeValue()
{
}
void RealTimeValue::paint(Graphics& g)
{
	g.setColour(Colours::black);
	g.drawText(String(getValue(), 2), getLocalBounds(), Justification::centred, false);
}