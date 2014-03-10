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
	addAndMakeVisible(propertiesTable);
	propertiesTable->setBounds(getLocalBounds());
}

PropertyPage::~PropertyPage()
{
}