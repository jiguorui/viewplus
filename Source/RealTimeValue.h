/*
  ==============================================================================

    RealTimeValue.h
    Created: 10 Mar 2014 12:30:03pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef REALTIMEVALUE_H_INCLUDED
#define REALTIMEVALUE_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "MeasurePoint.h"
#include "BaseComponent.h"

class RealTimeValue : public BaseComponent, public MeasurePoint
{
public:
	RealTimeValue(SelectedItems* selectedItems);
	~RealTimeValue();
	void paint(Graphics& g) override;
	void setPropertyPage(PropertyPage *);
	void setProperties(StringArray strs);
private:
	int fontSize;
	int fontColour;
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RealTimeValue)

};

#endif  // REALTIMEVALUE_H_INCLUDED
