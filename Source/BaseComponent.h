/*
  ==============================================================================

    BaseComponent.h
    Created: 7 Mar 2014 5:23:44pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef BASECOMPONENT_H_INCLUDED
#define BASECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
class SelectedItems;
class DocumentView;
//#include "PropertyPage.h"
//class PropertyPage;
class BaseComponent : public Component, public ChangeListener
{
public:
	BaseComponent(DocumentView *doc);
	BaseComponent(SelectedItems* selectedItems);
	~BaseComponent();

	void paint (Graphics& g);
	void resized();
	void changeListenerCallback(ChangeBroadcaster* /*source*/);

	void multiSelectedMove(int dx, int dy);
	void setSelected(bool sel);
private:
	void mouseDown(const MouseEvent& e);
	void mouseUp(const MouseEvent& e);
	void mouseDrag(const MouseEvent& e);
	void mouseDoubleClick(const MouseEvent&/* e*/);

	bool resultOfMouseDownSelectMethod;
	bool wasDraged;
	int lastX, lastY;

	ComponentDragger dragger;
	ScopedPointer<ResizableBorderComponent> resizeBorder;
	DocumentView * documentView;
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
};

#endif  // BASECOMPONENT_H_INCLUDED
