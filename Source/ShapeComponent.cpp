/*
  ==============================================================================

    ShapeComponent.cpp
    Created: 10 Mar 2014 1:02:19pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "ShapeComponent.h"

ShapeComponent::ShapeComponent(DocumentView *doc) : BaseComponent(doc)
{
	setSize(100, 100);
	borderThickness = 2;
	borderColour = 0xffff00ff;
}
ShapeComponent::~ShapeComponent()
{
}
void ShapeComponent::drawMyself(Graphics& g)
{
	g.setColour(Colour(borderColour));
	g.drawEllipse((float)borderThickness, (float)borderThickness, (float)getWidth() - 2 * (float)borderThickness, (float)getHeight() - 2 * (float)borderThickness, (float)borderThickness);
}
/*
void ShapeComponent::setPropertyPage(PropertyPage *pg)
{
	pg->propertyNames.add(new String("borderThickness"));
	pg->propertyNames.add(new String("borderColour"));
	TextEditor *textEditor = new TextEditor();
	textEditor->setText(String(borderThickness));
	Component ** c = new Component*();
	*c = textEditor;
	pg->propertyComps.add((Component **)c);
	textEditor = new TextEditor();
	textEditor->setText(String::toHexString(borderColour));
	c = new Component*();
	*c = textEditor;
	pg->propertyComps.add((Component **)c);
}

void ShapeComponent::setProperties(StringArray strs)
{
	borderThickness = strs[0].getIntValue();
	borderColour = strs[1].getHexValue32();
	repaint();
}*/