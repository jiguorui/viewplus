/*
  ==============================================================================

    SelectedItems.cpp
    Created: 7 Mar 2014 9:25:59pm
    Author:  jiguo_000

  ==============================================================================
*/

#include "SelectedComponentSet.h"
#include "BaseComponent.h"
void SelectedComponentSet::itemSelected(BaseComponent * c)
{
	c->setSelected(true);
}

void SelectedComponentSet::itemDeselected(BaseComponent *c)
{
	c->setSelected(false);
}