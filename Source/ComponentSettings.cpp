/*
  ==============================================================================

    ShapePropertyDialog.cpp
    Created: 10 Mar 2014 2:33:20pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "ComponentSettings.h"
ComponentSettings::ComponentSettings()
{
	setSize(100, 200);
	propertyPanel = new PropertyPanel();
	addAndMakeVisible(propertyPanel);
}
ComponentSettings::~ComponentSettings()
{
	propertyPanel = nullptr;
}

void ComponentSettings::paint(Graphics& g)
{
	g.setColour(Colours::whitesmoke);
	g.fillAll();
}

void ComponentSettings::resized()
{
	if(propertyPanel) propertyPanel->setBoundsInset(BorderSize<int>(8));
}
#if 0
#include "BaseComponent.h"
PropertyPage::PropertyPage(BaseComponent * c)
{
	setSize(300, 600);
	setLookAndFeel(lookAndFeel = new LookAndFeel_V3());
	componentToEdit = c;
//	c->setPropertyPage(this);
	numRows = propertyNames.size();
	tableListBox = new TableListBox("table", this);
	tableListBox->getHeader().addColumn("Name", 1, 150, 30, 200);
	tableListBox->getHeader().addColumn("Value", 2, 260, 30 , 200);
	addAndMakeVisible(tableListBox);
	tableListBox->setSize(450, numRows * 30 + 30);
	setSize(480, numRows * 30 + 30 + 80);
	//tableListBox->setLookAndFeel(new LookAndFeel_V3());
	applyButton = new TextButton("Apply");
	applyButton->setSize(120, 50);
	applyButton->addListener(this);
	//applyButton->setLookAndFeel(new LookAndFeel_V3());
	addAndMakeVisible(applyButton);
	resized();
}
PropertyPage::~PropertyPage()
{
}
int PropertyPage::getNumRows()
{
	return numRows;
}

void PropertyPage::paintRowBackground (Graphics& g, int rowNumber,int width, 
									   int height,bool rowIsSelected)
{
}
void PropertyPage::paintCell (Graphics& g, int rowNumber,int columnId,
		int width, int height,bool rowIsSelected)
{
	if(columnId == 1)
	{
		g.setColour(Colours::black);
		g.drawText(*propertyNames[rowNumber], 2, 0, width - 4, height, Justification::centredLeft, true);
	}

}

Component* PropertyPage::refreshComponentForCell (int rowNumber, int columnId, bool /*isRowSelected*/,
                                        Component* existingComponentToUpdate)
{
		if(columnId == 2)
		{
			Component * c;
			c = (Component *)existingComponentToUpdate;
			if(c == nullptr)
				c = *propertyComps[rowNumber];
			
			return c;
		}
		else
        {
            // for any other column, just return 0, as we'll be painting these columns directly.
            jassert (existingComponentToUpdate == 0);
            return 0;
        }
	}

void PropertyPage::resized()
{
	if(tableListBox) tableListBox->setCentrePosition(getWidth() / 2, getHeight()/2 - 40); 
	if(applyButton)  applyButton->setCentrePosition(getWidth() / 2, getHeight() - 40);
}
void PropertyPage::buttonClicked(Button * /*button*/)
{
	StringArray strs;
	for(int i = 0; i < numRows; i++)
	{
		String s = ((TextEditor *)(tableListBox->getCellComponent(2, i)))->getText();
		strs.add(s);
	}

//	componentToEdit->setProperties(strs);
	DialogWindow* dw = findParentComponentOfClass<DialogWindow>();
	if (dw != nullptr)
		dw->exitModalState (0);
}
if 0
#include "PropertyPage.h"

PropertyPage::PropertyPage()
{
	setName("Properties");
	propertiesTable = new TableListBox("Property", this);
	propertiesTable->setModel(this);
	propertiesTable->setBoundsInset (BorderSize<int> (8));
	propertiesTable->setColour (ListBox::outlineColourId, Colours::grey);
    propertiesTable->setOutlineThickness (1);
	propertiesTable->getHeader().addColumn("Name", 1, 60, 60);
	propertiesTable->getHeader().addColumn("Value", 2, 60, 60);
	addAndMakeVisible(propertiesTable);
	numRows = 0;
}

PropertyPage::~PropertyPage()
{
}
#endif