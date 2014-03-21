/*
  ==============================================================================

    ShapeComponent.h
    Created: 10 Mar 2014 1:02:19pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef SHAPECOMPONENT_H_INCLUDED
#define SHAPECOMPONENT_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "MeasurePoint.h"
#include "BaseComponent.h"

class ShapeComponent : public BaseComponent, public MeasurePoint
{
public:
	ShapeComponent(DocumentView * doc);
	~ShapeComponent();
	void drawMyself(Graphics& g) override;

//	void setPropertyPage(PropertyPage *);
//	void setProperties(StringArray strs);
private:
	int borderThickness;
	int borderColour;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShapeComponent)

};

#endif  // SHAPECOMPONENT_H_INCLUDED
