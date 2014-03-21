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
class BaseComponent : public Component, public ChangeListener, public Value::Listener
{
public:
	BaseComponent(DocumentView *doc);
	BaseComponent(SelectedItems* selectedItems);
	~BaseComponent();

	void paint (Graphics& g);
	void resized();
	void changeListenerCallback(ChangeBroadcaster* /*source*/);
	void valueChanged(Value &) {repaint();}

	void multiSelectedMove(int dx, int dy);
	void setSelected(bool sel);
	virtual Array<PropertyComponent*> createPropertyComponents() {Array<PropertyComponent*> comps; return comps;}

	virtual void drawMyself(Graphics& g) {};
private:
	void mouseDown(const MouseEvent& e);
	void mouseUp(const MouseEvent& e);
	void mouseDrag(const MouseEvent& e);
	void mouseDoubleClick(const MouseEvent&/* e*/);

	void drawRectesWhenSelected(Graphics& g);

	bool resultOfMouseDownSelectMethod;
	bool wasDraged;
	bool wasSelected;
	int lastX, lastY;

	ComponentDragger dragger;
	ScopedPointer<ResizableBorderComponent> resizeBorder;
	DocumentView * documentView;
	//Array<PropertyComponent*> propertyComps;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
};

#endif  // BASECOMPONENT_H_INCLUDED
