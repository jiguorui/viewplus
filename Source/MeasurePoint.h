/*
  ==============================================================================

    MeasurePoint.h
    Created: 10 Feb 2014 2:51:42pm
    Author:  Ji-Guorui,jiguorui@gmail.com

  ==============================================================================
*/
#ifndef MEASUREPOINT_H_INCLUDED
#define MEASUREPOINT_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class MeasurePoint
{
public:
	MeasurePoint();
	~MeasurePoint();

	float getFrom();
	float getTo();
	float getValue();
	float getRatio();

	void setRange(float from, float to);
	void setValue(float fv);
	void setUnit(String str);
	void setLegend(String str);

	String getUnit();
	String getLegend();
private:
	float fromValue;
	float toValue;
	float value;
	String strUnit;
	String strLegend;
private:
	//===========
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeasurePoint)
};

#endif  // MEASUREPOINT_H_INCLUDED
