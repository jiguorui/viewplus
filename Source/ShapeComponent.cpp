/*
  ==============================================================================

    ShapeComponent.cpp
    Created: 10 Mar 2014 1:02:19pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "ShapeComponent.h"

ShapeComponent::ShapeComponent(SelectedItems *selectedItems) : BaseComponent(selectedItems)
{
	setSize(100, 100);
}
ShapeComponent::~ShapeComponent()
{
}
void ShapeComponent::paint(Graphics& g)
{
	g.setColour(Colours::black);
	g.drawEllipse(1.0f, 1.0f, (float)getWidth() - 2, (float)getHeight() - 2, 1.0f);
}

void ShapeComponent::mouseDoubleClick(const MouseEvent& e)
{
//	ShapePropertyDialog dlg;
//	dlg.Show();
}