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
	int getNumRows() override {return numRows;}
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
							bool rowIsSelected) override
	{
		g.setColour(Colours::black);
		g.drawText("test", 2, 0, width-4, height, Justification::centred, true);
		g.setColour (Colours::black.withAlpha (0.2f));
        g.fillRect (width - 1, 0, 1, height);

	}
	void resized() override
	{
		propertiesTable->setBoundsInset (BorderSize<int> (8));
	}
	Component* refreshComponentForCell (int rowNumber, int columnId, bool /*isRowSelected*/,
                                        Component* existingComponentToUpdate) override
    {
		if(columnId == 2)
		{
			TextEditor * c;
			c = (TextEditor *)existingComponentToUpdate;
			if(c == nullptr)
				c = new TextEditor();
			return c;
		}
		else
        {
            // for any other column, just return 0, as we'll be painting these columns directly.
            jassert (existingComponentToUpdate == 0);
            return 0;
        }
	}
private:
	int numRows;
	ScopedPointer<TableListBox> propertiesTable;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PropertyPage)
};




#endif  // SHAPEPROPERTYDIALOG_H_INCLUDED
