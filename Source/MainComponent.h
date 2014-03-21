/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
class MDIFrame;
class ComponentSettings;
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component//, public FileDragAndDropTarget
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized() override;
	PropertyPanel * getPropertyPanel();
private:
	ScopedPointer<MDIFrame> mainFrame;
	ScopedPointer<MDIFrame> rightFrame;
    ScopedPointer<ComponentSettings> settingsPanel;
	ScopedPointer<StretchableLayoutResizerBar> spliteBar;

    StretchableLayoutManager layoutManager;    
    Toolbar toolBar;
	
private:
	void mouseDown(const MouseEvent& e);
	void updateLayoutMode();
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
