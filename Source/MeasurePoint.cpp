/*
  ==============================================================================

    MeasurePoint.cpp
    Created: 10 Feb 2014 2:51:42pm
    Author:  Ji-Guorui, jiguorui@gmail.com

  ==============================================================================
*/

#include "MeasurePoint.h"

MeasurePoint::MeasurePoint()
{
	fromValue = 0.0f;
	toValue = 1.0f;
	value = 0.0f;
}

MeasurePoint::~MeasurePoint()
{
}

float MeasurePoint::getFrom()
{
	return fromValue;
}

float MeasurePoint::getTo()
{
	return toValue;
}

float MeasurePoint::getValue()
{
	return value;
}

float MeasurePoint::getRatio()
{
	//? be careful !!! to avoid zero DIV
	if(std::fabs(toValue - fromValue) < 0.000000001f) 
	{
		return 1.0f;
	}
	return ((value - fromValue) / (toValue - fromValue));
}

void MeasurePoint::setRange(float from, float to)
{
	fromValue = from;
	toValue = to;
}

void MeasurePoint::setValue(float fv)
{
	value = fv;
}

void MeasurePoint::setUnit(String str)
{
	strUnit = str;
}

String MeasurePoint::getUnit()
{
	return strUnit;
}

void MeasurePoint::setLegend(String str)
{
	strLegend = str;
}

String MeasurePoint::getLegend()
{
	return strLegend;
}