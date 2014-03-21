/*
==============================================================================

BarChart.cpp
Created: 5 Feb 2014 8:12:16pm
Author:  Ji-Guorui,jiguorui@gmail.com

==============================================================================
*/

#include "BarChart.h"
BarChart::BarChart(DocumentView *doc) : BaseComponent(doc)
{
	isVertical = true;
	borderThickness = 1.0f;
	borderColour = Colour(0xffff6400);
	backColour = Colour(0xff989898);
	foreColour = Colour(0xff61CE3C);

	setValue(0.6f);

	setSize(90, 240);

}

BarChart::~BarChart()
{

}

void BarChart::paint(Graphics& g)
{
	int w = getWidth();
	int h = getHeight();
	float ratio = getRatio();
	g.setColour(borderColour);
	g.drawRect(0.0f, 0.0f, (float)w, (float)h, borderThickness);
}
/*{
	int w = getWidth();
	int h = getHeight();
	String tmp;
	float ratio = getRatio();
	if(isVertical)
	{
		int top = 23, bottom = 43;
	
		float rH = ratio * (h - top - bottom);
		if(false) {
			//background
			g.setColour(findColour(BarChart::ColourIds::backgroundColourId));
			g.fillRect(0, 0, w, h);
			//border
			g.setColour(findColour(BarChart::ColourIds::borderColourId));
			g.drawRect(0.0f, 0.0f, (float)w, (float)h, borderThickness);
		}
		//foreground
		g.setColour(findColour(BarChart::ColourIds::foregroundColourId));
		if(rH > 0)
		{
			g.fillRect(30.0f, (float)h - bottom - rH, (float)w-60, rH);
			g.setColour(Colours::green);
			Font font(String("Times New Roman"), 20, Font::plain);  
			g.setFont(font);
			String ss;
			ss << String(getValue(),1);
			g.drawText(ss, 0, h - top - bottom -rH, w, 20,Justification::centred,false);
			if(!getLegend().isEmpty())
			{
				g.setColour(Colours::grey);
				font.setTypefaceName(String(L"ºÚÌå"));
				font.setBold(false);
				font.setHeight(15);
				g.setFont(font);
				g.drawText(getLegend(), 0, h - bottom + 2, w, bottom/2, Justification::centred, true);
			}
		    if(!getUnit().isEmpty())
			{
				font.setTypefaceName(String("Times New Roman"));
				font.setBold(false);
				font.setHeight(13);
				g.setFont(font);
				String ss;
				ss << "(" << getUnit() << ")";
				g.drawText(ss, 0, h - bottom + 24, w, bottom/2, Justification::centred, true);
			}
		}
		else
		{
			g.fillRect(borderThickness, h - 2 * borderThickness, (float)w - 2 * borderThickness, 2.0f);
		}
	}
	else 
	{
		//background
		g.setColour(findColour(BarChart::ColourIds::backgroundColourId));
		g.fillRect(0, 0, w, h/3);
		//border
		g.setColour(findColour(BarChart::ColourIds::borderColourId));
		g.drawRect(0.0f, 0.0f, (float)w, (float)h/3, borderThickness);
		//foreground
		g.setColour(findColour(BarChart::ColourIds::foregroundColourId));

		float rW = ratio * (w - 2 * borderThickness);
		if(rW > 0) 
		{

			g.fillRect(borderThickness, borderThickness, rW, (float)h / 3 - 2 * borderThickness);
		}
		else
		{
			g.fillRect(borderThickness, borderThickness, 2.0f, (float)h / 3 - 2 * borderThickness);
		}
		//text
		g.setColour(Colours::black);

		tmp <<getLegend()<<" "<< String(getValue(), 2) << getUnit();
		g.drawText(tmp, 0, h/3, w, h/3*2, Justification::left, true);

	}

}*/
/*
void BarChart::resized()
{
	repaint();
}*/

void BarChart::timerCallback()
{
	repaint();
}

void BarChart::visibilityChanged()
{
	if(isVisible()) 
	{
		startTimer(30);
	}
	else
	{
		stopTimer();
	}
}