/*
  ==============================================================================

    RealTimeValue.cpp
    Created: 10 Mar 2014 12:30:04pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "RealTimeValue.h"
RealTimeValue::RealTimeValue(DocumentView* doc) : BaseComponent(doc)
{
	setSize(120, 50);
	fontSize = 18;
	fontColour = Colour(0xff00ff00);
	numDecimal = 2;
	fontSizeValue = Value("18");
	fontColourValue = Value("0xff00ff00");
	numDecimalValue = Value("2");
	fontColourValue.addListener(this);
	fontSizeValue.addListener(this);
	numDecimalValue.addListener(this);
}
RealTimeValue::~RealTimeValue()
{
}
void RealTimeValue::paint(Graphics& g)
{
	g.setColour(fontColour);
	g.setFont(fontSize);
	g.drawText(String(getValue(), numDecimal), getLocalBounds(), Justification::centred, false);
}

Array<PropertyComponent*> RealTimeValue::createPropertyComponents()
{
	Array<PropertyComponent*> comps;
	comps.add(new TextPropertyComponent(fontColourValue, "fontColour", 10, false));
	comps.add(new SliderPropertyComponent(fontSizeValue, "fontSize", 0.0,  100.0, 0.5));
	comps.add(new TextPropertyComponent(numDecimalValue, "numDecimal", 3, false));
	return comps;
}

void RealTimeValue::valueChanged(Value &/*val*/)
{
	fontSize = fontSizeValue.toString().getIntValue();
	fontColour = Colour(fontColourValue.toString().getHexValue32());
	numDecimal = numDecimalValue.toString().getIntValue();
	repaint();
}