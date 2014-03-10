/*
  ==============================================================================

    ViewDoc.cpp
    Created: 6 Mar 2014 1:36:36pm
    Author:  jiguo_000

  ==============================================================================
*/

#include "DocumentView.h"
#include "BaseComponent.h"
#include "MeterChart.h"
#include "BarChart.h"
#include "RealTimeValue.h"
#include "ShapeComponent.h"

DocumentView::DocumentView():FileBasedDocument (".jnote", "*.jnote",
                             "Browse for note to load",
							 "Choose file to save note to")
{
	setSize(500, 250);
	setName("child");
	BaseComponent * c = new MeterChart(&selectedItemSet);
	compArray.add(c);
	selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new BarChart(&selectedItemSet, 0, 20, true);
	compArray.add(c);
	selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new RealTimeValue(&selectedItemSet);
	compArray.add(c);
	selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new ShapeComponent(&selectedItemSet);
	compArray.add(c);
	selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);

}
void DocumentView::mouseDown(const MouseEvent& e)
{
	selectedItemSet.deselectAll();
}
DocumentView::~DocumentView()
{
}

void DocumentView::paint(Graphics& g)
{
}

void DocumentView::resized()
{
}