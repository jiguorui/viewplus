/*
  ==============================================================================

    MDIPanel.h
    Created: 6 Mar 2014 1:22:28pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef MDIPANEL_H_INCLUDED
#define MDIPANEL_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class MDIFrame    : public MultiDocumentPanel
{
public:
    MDIFrame()
    {
		setSize(200, 100);
    }

    ~MDIFrame()
    {
        closeAllDocuments (true);
    }

    bool tryToCloseDocument (Component* component) override
    {
       #if JUCE_MODAL_LOOPS_PERMITTED
        //if (Note* note = dynamic_cast<Note*> (component))
            //return note->saveIfNeededAndUserAgrees() != FileBasedDocument::failedToWriteToFile;
       #endif

        return true;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MDIFrame);
};


#endif  // MDIPANEL_H_INCLUDED
