/*
  ==============================================================================

    ViewDoc.h
    Created: 6 Mar 2014 1:36:36pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef VIEWDOC_H_INCLUDED
#define VIEWDOC_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "SelectedComponentSet.h"

class DocumentView: public Component, public FileBasedDocument, public SelectedComponentSet,private ValueListener
{
public:
    DocumentView(PropertyPanel *);
	DocumentView();
	~DocumentView();
	void paint (Graphics&);
    void resized();

	void mouseDown(const MouseEvent& e);

    void multiSelectedMove(BaseComponent * dragedComponent, int dx, int dy);

	String getDocumentTitle() override
    {
        return getName();
    }

    Result loadDocument (const File& file) override
    {
        //editor.setText (file.loadFileAsString());
        return Result::ok();
    }

    Result saveDocument (const File& file) override
    {
        // attempt to save the contents into the given file
        FileOutputStream os (file);

        //if (os.openedOk())
          //  os.writeText (editor.getText(), false, false);

        return Result::ok();
    }

    File getLastDocumentOpened() override
    {
        // not interested in this for now
        return File::nonexistent;
    }

    void setLastDocumentOpened (const File& /*file*/) override
    {
        // not interested in this for now
    }

	void mouseDoubleClick(const MouseEvent& e);
	void valueChanged(Value &val);

	PropertyPanel * getPropertyPanel() { return propertyPanel; }
private:
	OwnedArray<BaseComponent> compArray;
	//SelectedItems selectedItemSet;
	ScopedPointer<LookAndFeel> 	lookAndFeel;
    PropertyPanel *  propertyPanel;

	Value strHexBackGroundColour ;

private:
    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DocumentView)

};

#endif  // VIEWDOC_H_INCLUDED
