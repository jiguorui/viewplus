/*
  ==============================================================================

    MeterChart.h
    Created: 7 Feb 2014 7:34:53pm
    Author:  Ji-Guorui,jiguorui@gmail.com

  ==============================================================================
*/

#ifndef METERCHART_H_INCLUDED
#define METERCHART_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "MeasurePoint.h"
#include "BaseComponent.h"
class DocumentView;
class MeterChart : public BaseComponent, public MeasurePoint, private Timer
{
public:
	MeterChart(DocumentView* doc);
	~MeterChart();
	
	void drawMyself (Graphics&) override;
	Array<PropertyComponent*> createPropertyComponents() override;
	void valueChanged(Value &val) override;
protected:
	void visibilityChanged() override;

private:
	void getRLine(float x, float y, float rad, float r1, float r2, Line<float> &line); 
	void getRPos(float x, float y, float rad, float r, Point<float> &pos);

	void timerCallback() override;

	Value dialColourValue;
	Colour dialColour;
	Value pointerColourValue;
	Colour pointerColour;
	Value fontColourValue;
	Colour fontColour;
	Value fontSizeValue;
	int fontSize;

    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterChart)

};



#endif  // METERCHART_H_INCLUDED
