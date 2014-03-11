/*
  ==============================================================================

    ComponentProperty.cpp
    Created: 11 Mar 2014 9:34:08am
    Author:  jiguo_000

  ==============================================================================
*/

#include "PropertySet.h"
cPropertySet::cPropertySet()
{
	numProperties = 0;
}
cPropertySet::~cPropertySet()
{
}
void cPropertySet::addProperty(String name, enum Propertype tt, void *p)
{
	Property * pr = new Property();
	pr->name = name;
	pr->t = tt;
	pr->datap = p;
	properties.add(pr);
	numProperties ++;
}
void cPropertySet::setPropertyValue(int index, String sval)
{
	jassert(index >= numProperties);
	Property * pr = properties[index];
	switch(pr->t)
	{
	case str:
		*((String *)(pr->datap)) = sval;
		break;
	case i:
		*((int *)(pr->datap)) = sval.getIntValue();
		break;
	case ui:
		*((unsigned int *)(pr->datap)) = (unsigned int)sval.getIntValue();
		break;
	case f:
		*((float *)(pr->datap)) = sval.getFloatValue();
		break;
	}
}
int cPropertySet::getNumProperties()
{
	return numProperties;
}