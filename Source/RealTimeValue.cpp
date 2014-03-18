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
	fontSize = 18;
	fontColour = 0xff00ff00;
}
RealTimeValue::~RealTimeValue()
{
}
void RealTimeValue::paint(Graphics& g)
{
	g.setColour(Colour(fontColour));
	g.setFont(fontSize);
	g.drawText(String(getValue(), 2), getLocalBounds(), Justification::centred, false);
}
/*
void RealTimeValue::setPropertyPage(PropertyPage *pg)
{
	pg->propertyNames.add(new String("Font size"));
	pg->propertyNames.add(new String("Font colour"));
	Component **c = new Component*();
	*c = new TextEditor();
	((TextEditor*)*c)->setText(String(fontSize));
	pg->propertyComps.add(c);
	c = new Component*();
	*c = new TextEditor();
	((TextEditor*)*c)->setText(String::toHexString(fontColour));
	pg->propertyComps.add(c);
}

void RealTimeValue::setProperties(StringArray strs)
{
	fontSize = strs[0].getIntValue();
	fontColour = strs[1].getHexValue32();
	repaint();
}*/