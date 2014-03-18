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
#include "SelectedItems.h"
#include "PropertyPage.h"
//class PropertyPage;
class BaseComponent : public Component, public ChangeListener
{
public:
	BaseComponent(SelectedItems* selectedItems)
	{
		setSize(100, 100);
		resizeBorder = new ResizableBorderComponent(this, nullptr);
		addChildComponent(resizeBorder);
		resizeBorder->setBounds(getLocalBounds());
		selectedItemSet = selectedItems;
	}
	~BaseComponent()
	{
	}
	virtual void setPropertyPage(PropertyPage *) = 0;
	virtual void setProperties(StringArray strs) = 0;
public:
	void paint (Graphics& g)
	{
		//g.drawRect(getLocalBounds(), 1);
	}
	void resized()
	{
		if(resizeBorder) resizeBorder->setBounds(getLocalBounds());
	}

	void changeListenerCallback(ChangeBroadcaster* /*source*/)
	{
		
	}
	void setSelected(bool sel)
	{
		resizeBorder->setVisible(sel);
	}
private:
	bool resultOfMouseDownSelectMethod;
	bool wasDraged;
	int lastX, lastY;
	void mouseDown(const MouseEvent& e);
	void mouseUp(const MouseEvent& e)
	{
		dragger.startDraggingComponent(this, e);
		selectedItemSet->addToSelectionOnMouseUp(this, e.mods, wasDraged,  resultOfMouseDownSelectMethod);
		wasDraged = false;
	}
	void mouseDrag(const MouseEvent& e)
	{
		//drage me
		dragger.dragComponent(this, e, nullptr);
		wasDraged = true;
		//drag other selected items
		int dx = getX() - lastX;
		int dy = getY() - lastY;
		int cnt = selectedItemSet->getNumSelected();
		for(int i = 0; i < cnt; i++)
		{
			BaseComponent *c = selectedItemSet->getSelectedItem(i);
			if(this != c)
			{
				c->move(dx, dy);
			}
		}
		//do not forget here
		lastX = getX();
		lastY = getY();
	}
	void mouseDoubleClick(const MouseEvent&/* e*/)
	{
		PropertyPage *pg = new PropertyPage(this);
		//DialogWindow dlg = pg->findParentComponentOfClass<DialogWindow>();
		DialogWindow *dlg = new DialogWindow("dlg", Colours::lightgrey, true, false);
		dlg->showModalDialog("property", pg, getParentComponent(), Colours::lightgrey, false); 
		delete pg;
		delete dlg;
	}
	void move(int dx, int dy)
	{
		Rectangle<int> rect = getBounds();
		rect.translate(dx, dy);
		setBounds(rect);
	}

private:
	SelectedItems *selectedItemSet;
	ComponentDragger dragger;
	ScopedPointer<ResizableBorderComponent> resizeBorder;
//	OwnedArray<String> propertyNames;
//	OwnedArray<Component *> propertyEditors;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
};

#endif  // BASECOMPONENT_H_INCLUDED
