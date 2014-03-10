/*
==============================================================================

BarChart.cpp
Created: 5 Feb 2014 8:12:16pm
Author:  Ji-Guorui,jiguorui@gmail.com

==============================================================================
*/

#include "BarChart.h"
//#include "ComponentUtils.h"
BarChart::BarChart(SelectedItems* selectedItems, float from, float to, bool vertical) : BaseComponent(selectedItems)
{
	isVertical = vertical;

	setRange(from, to);

	borderThickness = 1.0f;
	//default size
	if(isVertical) setSize(110, 160);
	else setSize(139, 21);
	//default colours
	setColour(BarChart::ColourIds::backgroundColourId, Colour(0xfff3f3f3));
	setColour(BarChart::ColourIds::foregroundColourId, Colours::green);
	setColour(BarChart::ColourIds::borderColourId, Colours::grey);

}
BarChart::BarChart(SelectedItems* selectedItems):BaseComponent(selectedItems)
{
	isVertical = false;

	borderThickness = 1.0f;
	//default size
	setSize(139, 21);
	//default colours
	setColour(BarChart::ColourIds::backgroundColourId, Colour(0xfff3f3f3));
	setColour(BarChart::ColourIds::foregroundColourId, Colours::green);
	setColour(BarChart::ColourIds::borderColourId, Colours::grey);
//	setColour(BarChart::ColourIds::valueColourId, Colours::grey);
//	setColour(BarChart::ColourIds::legendColourId, Colours::black);
}
BarChart::~BarChart()
{
}

void BarChart::paint(Graphics& g)
{
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

}
/*
void BarChart::resized()
{
	repaint();
}*/

void BarChart::setVertical(bool val)
{
	isVertical = val;
	repaint();
}
void BarChart::setBorderThickness(float val)
{
	float v = jmin(getWidth(), getHeight());
	borderThickness = jlimit(0.0f, v/2-2.0f, val);  //check and set the thickness
	repaint();
}

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