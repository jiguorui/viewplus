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

class ComponentSettings : public Component
{
public:
	ComponentSettings();
	~ComponentSettings();
	void paint(Graphics& g) override;
	void resized();
	PropertyPanel * getPropertyPanel() {return propertyPanel;}
private:
	ScopedPointer<PropertyPanel> propertyPanel;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentSettings)	
};

#if 0
class BaseComponent;
class PropertyPage : public Component, public TableListBoxModel, private Button::Listener
{
public:
	PropertyPage(BaseComponent* component);
	~PropertyPage();
	void resized() override;
	int getNumRows() override;
	void paintRowBackground (Graphics& g, int rowNumber,int width, int height,bool rowIsSelected) override;
	void paintCell (Graphics& g, int rowNumber,int columnId,int width, int height,bool rowIsSelected) override;
	Component* refreshComponentForCell (int rowNumber, int columnId, bool /*isRowSelected*/,
                                        Component* existingComponentToUpdate) override;
	OwnedArray<String> propertyNames;
	OwnedArray<Component *> propertyComps;
private:
	ScopedPointer<TableListBox> tableListBox;
	ScopedPointer<TextButton> applyButton;
	int numRows;
	BaseComponent* componentToEdit;
	ScopedPointer<LookAndFeel> lookAndFeel;

	void buttonClicked(Button * button) override;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PropertyPage)
};
if 0
class PropertyEditor : public TextEditor
{
public:
	PropertyEditor(cPropertySet * s, int indx)
	{
		set = s;
		index = indx;
	}
	~PropertyEditor(){}
	void focusLost(FocusChangeType t) override
	{
		TextEditor::focusLost(t);
		if(set) set->setPropertyValue(index, getText());
	}

private:
	cPropertySet *set;
	int index;
};

class PropertyPage : public Component, public TableListBoxModel
{
public:
	PropertyPage();
	~PropertyPage();
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
		if(columnId == 1)
		{
		g.setColour(Colours::black);
		g.drawText("test", 2, 0, width-4, height, Justification::centred, true);
		g.setColour (Colours::black.withAlpha (0.2f));
        g.fillRect (width - 1, 0, 1, height);
		}
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
			PropertyEditor * c;
			c = (PropertyEditor *)existingComponentToUpdate;
			if(c == nullptr)
				c = new PropertyEditor(propertySet, rowNumber);
			
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
	cPropertySet * propertySet;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PropertyPage)
};
#endif
#endif  // SHAPEPROPERTYDIALOG_H_INCLUDED
