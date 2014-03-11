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

	spliteBar = new StretchableLayoutResizerBar(&mainLayout, 1, true);
	//spliteBar->setSize(8,100);
	addAndMakeVisible(spliteBar);
	mainFrame = new MDIFrame();
	addAndMakeVisible(mainFrame);
	mainFrame->setBackgroundColour (Colours::transparentBlack);
	mainFrame->addDocument(new DocumentView(), Colours::white, true);

	rightFrame = new MDIFrame();
	addAndMakeVisible(rightFrame);
	rightFrame->setBackgroundColour (Colours::transparentBlack);
	rightFrame->addDocument(new PropertyPage(), Colours::whitesmoke, true);
	mainLayout.setItemLayout (0, -0.2, -0.85,-0.85); 
	mainLayout.setItemLayout (1, 8, 8, 8);
	mainLayout.setItemLayout (2,-0.1, -0.8,-0.13); 

}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll(Colours::lightblue);
}

void MainContentComponent::resized() 
{
	Component* comps[] = { mainFrame, spliteBar, rightFrame };
	mainLayout.layOutComponents (comps, 3, 0, 0, getWidth(), getHeight(),false,true);
}

void MainContentComponent::updateLayoutMode()
{
	if(mainFrame) mainFrame->setLayoutMode(MultiDocumentPanel::FloatingWindows);
}