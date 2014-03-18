/*
  ==============================================================================

    BarChart.h
    Created: 5 Feb 2014 8:12:16pm
    Author:  Ji-Guorui,jiguorui@gmail.com

  ==============================================================================
*/

#ifndef BARCHART_H_INCLUDED
#define BARCHART_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "MeasurePoint.h"
#include "BaseComponent.h"
class BarChart : public BaseComponent, public MeasurePoint, private Timer 
{
public:
	BarChart(DocumentView *doc);
	BarChart(SelectedItems* selectedItems);
	BarChart(SelectedItems* selectedItems, float from, float to, bool vertical);
	~BarChart();

	void paint(Graphics&) override;
	//void resized();
	
public:
	void setVertical(bool);
	void setBorderThickness(float);

	enum ColourIds
    {
        backgroundColourId              = 0x2001900,    
        foregroundColourId              = 0x2001a00,    
		borderColourId                  = 0x2001b00,
    };
//	void setPropertyPage(PropertyPage *) {}
//	void setProperties(StringArray strs){}
private:
	bool isVertical;
	float borderThickness;

protected:
	void visibilityChanged() override;

private:
	
	void timerCallback() override;
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BarChart)
};

#endif  // BARCHART_H_INCLUDED