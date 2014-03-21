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
#include "MainComponent.h"
DocumentView::DocumentView(PropertyPanel * panel):FileBasedDocument (".jnote", "*.jnote",
                             "Browse for note to load",
							 "Choose file to save note to")
{
	setName("child");
	strHexBackGroundColour = Value("0xff0c1021");
	propertyPanel = panel;
	setLookAndFeel(lookAndFeel = new LookAndFeel_V3());
	BaseComponent * c = new MeterChart(this);
	//((MeasurePoint*)c)->setLegend("Temp.");
	compArray.add(c);
	//addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new RealTimeValue(this);
	compArray.add(c);
	//selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new BarChart(this);
	compArray.add(c);
	//selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);

	setSize(500, 250);


}  
DocumentView::DocumentView():FileBasedDocument (".jnote", "*.jnote",
                             "Browse for note to load",
							 "Choose file to save note to")
{
	setSize(500, 250);
	setName("child");
	propertyPanel = nullptr;
	setLookAndFeel(lookAndFeel = new LookAndFeel_V3());
	BaseComponent * c = new MeterChart(this);
	compArray.add(c);
	//addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);
	c = new BarChart(this);
	compArray.add(c);
	//selectedItemSet.addChangeListener((ChangeListener*)c);
	addAndMakeVisible(c);

/*
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
	addAndMakeVisible(c);*/

}
void DocumentView::mouseDown(const MouseEvent& e)
{
	if(propertyPanel)
	{
		Array<PropertyComponent*> comps;
		//strHexBackGroundColour = Value("0xff6a6a6a");
		strHexBackGroundColour.addListener(this);
		comps.add (new TextPropertyComponent (strHexBackGroundColour, 
    	"Backcolour", 200, false));
		propertyPanel->clear();
    	propertyPanel->addSection("View", comps);
	}

	deselectAll();
}

void DocumentView::multiSelectedMove(BaseComponent * dragedComponent, int dx, int dy)
{
	int cnt = getNumSelected();
	for(int i = 0; i < cnt; i++)
	{
		BaseComponent *c = getSelectedItem(i);
		if(dragedComponent != c)
		{
			c->multiSelectedMove(dx, dy);
		}
	}
}
DocumentView::~DocumentView()
{
}

void DocumentView::paint(Graphics& g)
{
	int c = strHexBackGroundColour.toString().getHexValue32();
	g.setColour(Colour(c));
	g.fillAll();
}

void DocumentView::resized()
{
}

void DocumentView::mouseDoubleClick(const MouseEvent& /*e*/)
{
	/*
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
*/
}

void DocumentView::valueChanged(Value&)
{
	repaint();
}