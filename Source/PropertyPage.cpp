/*
  ==============================================================================

    ShapePropertyDialog.cpp
    Created: 10 Mar 2014 2:33:20pm
    Author:  jiguo_000

  ==============================================================================
*/
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