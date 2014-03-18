/*
  ==============================================================================

    BaseComponent.cpp
    Created: 7 Mar 2014 5:23:44pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "BaseComponent.h"

void BaseComponent::mouseDown(const MouseEvent& e)
{
	dragger.startDraggingComponent(this, e);
	resultOfMouseDownSelectMethod = selectedItemSet->addToSelectionOnMouseDown(this, e.mods);
	wasDraged = false;
	//remember X, Y
	lastX = getX();
	lastY = getY();
}
