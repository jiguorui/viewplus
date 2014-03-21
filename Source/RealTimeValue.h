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
	RealTimeValue(DocumentView* doc);
	~RealTimeValue();
	void paint(Graphics& g) override;

	Array<PropertyComponent*> createPropertyComponents() override;
	void valueChanged(Value &val) override;

private:
	int fontSize;
	int numDecimal;
	Colour fontColour;

	Value fontSizeValue;
	Value fontColourValue;
	Value numDecimalValue;
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RealTimeValue)

};

#endif  // REALTIMEVALUE_H_INCLUDED
