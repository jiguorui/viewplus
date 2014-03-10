/*
  ==============================================================================

    SelectedItems.cpp
    Created: 7 Mar 2014 9:25:59pm
    Author:  jiguo_000

  ==============================================================================
*/

#include "SelectedItems.h"
#include "BaseComponent.h"
void SelectedItems::itemSelected(BaseComponent * c)
{
	c->setSelected(true);
}

void SelectedItems::itemDeselected(BaseComponent *c)
{
	c->setSelected(false);
}