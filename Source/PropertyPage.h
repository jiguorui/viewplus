/*
  ==============================================================================

    ShapePropertyDialog.h
    Created: 10 Mar 2014 2:33:19pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef SHAPEPROPERTYDIALOG_H_INCLUDED
#define SHAPEPROPERTYDIALOG_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
class BaseComponent;
class PropertyPage : public Component, public TableListBoxModel
{
public:
	PropertyPage();
	~PropertyPage();
	void setBaseComponentToEdit(BaseComponent *){}
	int getNumRows() {return 1;}
	void paintRowBackground (Graphics& g,
                                     int rowNumber,
                                     int width, int height,
                                     bool rowIsSelected)
	{
	}
	void paintCell (Graphics& g,
                            int rowNumber,
                            int columnId,
                            int width, int height,
							bool rowIsSelected){}

private:
	ScopedPointer<TableListBox> propertiesTable;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PropertyPage)
};




#endif  // SHAPEPROPERTYDIALOG_H_INCLUDED
