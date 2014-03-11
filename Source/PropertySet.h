/*
  ==============================================================================

    ComponentProperty.h
    Created: 11 Mar 2014 9:34:08am
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef PROPERTY_SET_H_INCLUDED
#define PROPERTY_SET_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
enum Propertype
{
	str,
	i,
	ui,
	f
};
struct Property
{
	String name;
	enum Propertype t;
	void * datap;
};
class cPropertySet
{
public:
	cPropertySet();
	~cPropertySet();
	void addProperty(String name, enum Propertype, void *p);
	void setPropertyValue(int index, String sval);
	int getNumProperties();
private:
	int numProperties;
	OwnedArray<struct Property> properties;
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cPropertySet)
};

#if 0
class ComponentProperty
{
public:
	String name;
	enum PropertyTypes
	{
		string_type,
		int_type,
		uint_type,
		float_type
	} t;
	ComponentProperty(void *p, enum  PropertyTypes tt)
	{
		ptr = p;
		t = tt;
	}
	void setValue(String sval)
	{
		if(ptr == nullptr) return;
		switch (t)
		{
		case string_type:
			*(String*)ptr = sval; 
			break;
		case int_type:
			*(int *)ptr = sval.getIntValue();
			break;
		case uint_type:
			*(unsigned int *)ptr = (unsigned int)sval.getIntValue();
			break;
		case float_type:
			*(float *)ptr = sval.getFloatValue();
			break;
		}
	}
private:
	void * ptr;
};

class ComponentPropertySet
{
public:
	ComponentPropertySet();
	~ComponentPropertySet();
	void addProperty(String name, void*p);
	bool setProperty(int index, String sval);

private:
	OwnedArray<ComponentProperty> properties;
private:
    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentPropertySet)
};
#endif
#endif  // COMPONENTPROPERTY_H_INCLUDED
