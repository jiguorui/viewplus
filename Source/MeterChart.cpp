/*
  ==============================================================================

    MeterChart.cpp
    Created: 7 Feb 2014 7:34:54pm
    Author:  jiguo_000

  ==============================================================================
*/

#include "MeterChart.h"
//#include "WidgetPanel.h"

#define MATH_PI 3.1415926f
#define ZRAD(rad) (rad)-MATH_PI/4*3
MeterChart::MeterChart(SelectedItems *selectedItems) : BaseComponent(selectedItems)
{
	setSize(200, 200);
	setValue(0.5f);
	segLineColour = 0xff00ff00;
	//resizer->setCentrePosition(195, 195);
}
MeterChart::~MeterChart()
{
}

void MeterChart::paint(Graphics &g)
{

	int w, h;
	Line<float> lineTmp;
	Path path;
	float x1 , y1, R;

	w = getWidth();
	h = getHeight();
	R = jmin(w, h) / 2;
	x1 = w / 2;
	y1 = h / 2;
//	drawPanel(g, 0, 0, w, h);
	path.addCentredArc(w / 2, h / 2, R - 10, R - 10, MATH_PI * 0.75f * -1 , 0, MATH_PI * 1.5f, true);
	for(int i = 0; i <= 20; i++)
	{
		float rad;
		rad = i * MATH_PI * 1.5f / 20;
		if(i % 5 == 0)
		{
			getRLine(x1, y1, rad, R - 20, R - 10, lineTmp);
			path.addLineSegment(lineTmp, 1.0f);

			continue;
		}
		getRLine(x1, y1, rad, R - 14, R - 10, lineTmp);
		path.addLineSegment(lineTmp, 0.5f);
	}
	//g.setColour(Colours::dodgerblue);
	g.setColour(Colour(segLineColour));
	PathStrokeType pst(2.0f);
	g.strokePath(path,pst);

	g.setColour(Colours::green);
	g.drawEllipse(w / 2 - 4, h / 2 - 4, 8, 8, 2.0f);
	g.setColour(Colours::red);
	g.fillEllipse(w / 2 - 3, h / 2 - 3, 6, 6);
	//g.setColour(Colours::orange);
	float ratio = getRatio();
	getRLine(x1, y1, ratio * MATH_PI * 1.5, -1 * R / 10, R - 45, lineTmp);
	g.drawLine(lineTmp, 2.0f);
	String str;
	str << String(getValue(),0) << " " << getUnit();
	Font font(String("Times New Roman"), 20, Font::plain);
	g.setFont(font);
	g.setColour(Colours::green);
	g.drawText(str, (int)x1-50, (int)(y1 + R - 80), 100, 22, Justification::centred, true);
	g.setColour(Colours::grey);
	font.setTypefaceName(String(L"ºÚÌå"));
	font.setHeight(15);
	g.setFont(font);
	str = getLegend();
	g.drawText(str, (int)x1-50, (int)(y1 + R - 45), 100, 22, Justification::centred, true);
	g.setColour(Colours::grey);
	Point<float> pos;
	float rad = 0.0f;
	font.setBold(false);
	g.setFont(font);
	for(int i = 1; i <= 2; i++)
	{
		g.drawText(String(i * 0.5f*(getTo() - getFrom()) + getFrom(), 0), x1 - 20, y1-R+25, 40, 20, Justification::centred, true);
		g.addTransform(AffineTransform().rotated(MATH_PI*3/4, x1,y1));
	}
}

void MeterChart::getRPos(float x, float y, float rad, float r, Point<float> &pos)
{
	float dx, dy;
	float zrad = ZRAD(rad);
	dx = r * std::sin(zrad);
	dy = r * std::cos(zrad);
	pos.setXY(x + dx, y - dy);
}


void MeterChart::getRLine(float x, float y, float rad, float r1, float r2, Line<float> &line)
{
	float dx, dy;
	float zrad = ZRAD(rad);
	dx = r1 * std::sin(zrad);
	dy = r1 * std::cos(zrad);
	line.setStart(x + dx, y - dy);
	dx = r2 * std::sin(zrad);
	dy = r2 * std::cos(zrad);
	line.setEnd(x + dx, y - dy);
}
/*
void MeterChart::resized()
{

}
*/
void MeterChart::visibilityChanged()
{
	if (isVisible())
        startTimer (30);
    else
        stopTimer();
}

void MeterChart::timerCallback()
{
	repaint();
}

void MeterChart::setPropertyPage(PropertyPage *pg)
{
	pg->propertyNames.add(new String("segLineColour"));
	Component **c = new Component*();
	*c = new TextEditor();
	((TextEditor*)*c)->setText(String::toHexString(segLineColour));
	pg->propertyComps.add(c);
}

void MeterChart::setProperties(StringArray strs)
{
	segLineColour = strs[0].getHexValue32();
}