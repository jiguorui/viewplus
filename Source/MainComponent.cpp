/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "MDIFrame.h"
#include "DocumentView.h"
#include "MeterChart.h"
#include "BarChart.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
	addAndMakeVisible(toolBar);
	toolBar.setBoundsRelative(0.0f, 0.0f, 0.2f, 1.0f);
	toolBar.setVertical(true);
	toolBar.setColour(Toolbar::ColourIds::backgroundColourId, Colours::grey);
	frame = new MDIFrame();
	addAndMakeVisible(frame);
	frame->setBackgroundColour (Colours::transparentBlack);
	updateLayoutMode();
	frame->addDocument(new DocumentView(), Colours::lightgrey, true);

	Rectangle<int> area = getLocalBounds();
	area.translate(getWidth() * 0.2f, 0);
	frame->setBounds (area);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colours::whitesmoke);
}

void MainContentComponent::resized() 
{
	if(frame)	
	{
		Rectangle<int> area = getLocalBounds();
		area.translate(getWidth() * 0.2f, 0);
		frame->setBounds (area);
	}
	toolBar.setBoundsRelative(0.0f, 0.0f, 0.2f, 1.0f);
}

void MainContentComponent::updateLayoutMode()
{
	frame->setLayoutMode(MultiDocumentPanel::FloatingWindows);
}