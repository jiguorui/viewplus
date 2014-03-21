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
#include "ComponentSettings.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

	spliteBar = new StretchableLayoutResizerBar(&layoutManager, 1, true);
	spliteBar->setSize(8,100);
	addAndMakeVisible(spliteBar);

	settingsPanel = new ComponentSettings();
	addAndMakeVisible(settingsPanel);

	mainFrame = new MDIFrame();
	addAndMakeVisible(mainFrame);
	mainFrame->setBackgroundColour (Colours::transparentBlack);
	mainFrame->addDocument(new DocumentView(settingsPanel->getPropertyPanel()), Colours::white, true);
	mainFrame->setBounds(getLocalBounds());

	//rightFrame = new MDIFrame();
	//addAndMakeVisible(rightFrame);
	//rightFrame->setBackgroundColour (Colours::transparentBlack);
//	rightFrame->addDocument(new PropertyPage(), Colours::whitesmoke, true);
	layoutManager.setItemLayout (0, -0.2, -0.85,-0.85); 
	layoutManager.setItemLayout (1, 8, 8, 8);
	layoutManager.setItemLayout (2,-0.1, -0.8,-0.13); 
	updateLayoutMode();
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
	Component* comps[] = { mainFrame, spliteBar, settingsPanel };
	layoutManager.layOutComponents (comps, 3, 0, 0, getWidth(), getHeight(),false,true);
	//if(mainFrame) mainFrame->setBounds(getLocalBounds());
	updateLayoutMode();
}

void MainContentComponent::updateLayoutMode()
{
	if(mainFrame) mainFrame->setLayoutMode(MultiDocumentPanel::FloatingWindows);
}

PropertyPanel * MainContentComponent::getPropertyPanel()
{
	return settingsPanel->getPropertyPanel();
}

void MainContentComponent::mouseDown(const MouseEvent& /*e*/)
{
	if(settingsPanel) settingsPanel->getPropertyPanel()->clear();
}