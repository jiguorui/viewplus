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
	setLookAndFeel(lookAndFeel = new LookAndFeel_V3());

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
	g.setColour(Colour(0xff4a4a4a));
	g.fillAll();
}

void DocumentView::resized()
{
}

void DocumentView::mouseDoubleClick(const MouseEvent& /*e*/)
{
	Array<PropertyComponent *> pps; 
	PropertyPanel *pp = new PropertyPanel();
	String str = "back";
	Value v;
	
	TextPropertyComponent * tpc = new TextPropertyComponent(v, str, 10, false);
	pps.add(tpc);
	pp->addProperties(pps);
	pp->setSize(200,100);
	//pp->add
	DialogWindow *dlg = new DialogWindow("dlg", Colours::lightgrey, true, false);
	dlg->showModalDialog("property", pp, getParentComponent(), Colours::lightgrey, false); 
		delete pp;
		delete dlg;

}