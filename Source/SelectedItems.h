/*
  ==============================================================================

    SelectedItems.h
    Created: 7 Mar 2014 9:25:59pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef SELECTEDITEMS_H_INCLUDED
#define SELECTEDITEMS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
//#include "BaseComponent.h"
class BaseComponent;
class SelectedItems : public SelectedItemSet<BaseComponent *>
{
	void itemSelected(BaseComponent * c);
	void itemDeselected(BaseComponent * c);
};





#endif  // SELECTEDITEMS_H_INCLUDED
