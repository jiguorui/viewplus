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
	
	void paint (Graphics&) override;
	//void resized();
//	void setPropertyPage(PropertyPage *);
//	void setProperties(StringArray strs);
protected:
	void visibilityChanged() override;
	/*
	void mouseDown(const MouseEvent& e)
	{
		dragger.startDraggingComponent(this, e);
		
	}
	void mouseDrag(const MouseEvent& e)
	{
		dragger.dragComponent(this, e, nullptr);
	}*/
private:
	int segLineColour;
	//void drawPanel(Graphics &, int , int);
	void getRLine(float x, float y, float rad, float r1, float r2, Line<float> &line); 
	void getRPos(float x, float y, float rad, float r, Point<float> &pos);
	//ComponentDragger dragger;
	//ScopedPointer<ResizableBorderComponent>  resizeBorder;
private:
	void timerCallback() override;

    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterChart)

};



#endif  // METERCHART_H_INCLUDED
