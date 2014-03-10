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
#include "PropertyPage.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
	//addAndMakeVisible(toolBar);
	/*
	toolBar.setBoundsRelative(0.0f, 0.0f, 0.2f, 1.0f);
	toolBar.setVertical(true);
	toolBar.setColour(Toolbar::ColourIds::backgroundColourId, Colours::grey);*/
	mainFrame = new MDIFrame();
	addAndMakeVisible(mainFrame);
	mainFrame->setBackgroundColour (Colours::transparentBlack);
	mainFrame->addDocument(new DocumentView(), Colours::white, true);
	updateLayoutMode();

	rightFrame = new MDIFrame();
	addAndMakeVisible(rightFrame);
	rightFrame->setBackgroundColour (Colours::transparentBlack);
	rightFrame->addDocument(new PropertyPage(), Colours::lightgrey, true);

	Rectangle<int> area = getLocalBounds();
	area.setWidth(getWidth() * 0.76f);
	mainFrame->setBounds (area);
	area.setWidth(getWidth() * 0.23f);
	area.translate(getWidth() * 0.77f, 0);
	rightFrame->setBounds(area);
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
	if(mainFrame)	
	{
		Rectangle<int> area = getLocalBounds();
		area.setWidth(getWidth() * 0.76f);
		mainFrame->setBounds (area);
	}
	if(rightFrame)
	{
		Rectangle<int> area = getLocalBounds();
		area.setWidth(getWidth() * 0.24f - 3);
		area.translate(getWidth() * 0.76f + 3, 0);
		rightFrame->setBounds(area);
	}
	//toolBar.setBoundsRelative(0.0f, 0.0f, 0.2f, 1.0f);
}

void MainContentComponent::updateLayoutMode()
{
	mainFrame->setLayoutMode(MultiDocumentPanel::MaximisedWindowsWithTabs);
}