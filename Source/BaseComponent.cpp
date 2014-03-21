/*
  ==============================================================================

    BaseComponent.cpp
    Created: 7 Mar 2014 5:23:44pm
    Author:  jiguo_000

  ==============================================================================
*/
#include "BaseComponent.h"

#include "DocumentView.h"
BaseComponent::BaseComponent(DocumentView *doc)
{
	setSize(100, 100);
	wasSelected = false;
	resizeBorder = new ResizableBorderComponent(this, nullptr);
	addChildComponent(resizeBorder);
	resizeBorder->setBounds(getLocalBounds());	
	documentView = doc;
} 
BaseComponent::BaseComponent(SelectedItems* selectedItems)
{
	setSize(100, 100);
	wasSelected = false;
	resizeBorder = new ResizableBorderComponent(this, nullptr);
	addChildComponent(resizeBorder);
	resizeBorder->setBounds(getLocalBounds());
//	selectedItemSet = selectedItems;
}
BaseComponent::~BaseComponent()
{
}
void BaseComponent::paint (Graphics& g)
{
	drawMyself(g);
	drawRectesWhenSelected(g);
}
void BaseComponent::resized()
{
	if(resizeBorder) resizeBorder->setBounds(getLocalBounds());
}

void BaseComponent::changeListenerCallback(ChangeBroadcaster* /*source*/)
{

}
void BaseComponent::setSelected(bool sel)
{
	resizeBorder->setVisible(sel);
	wasSelected = sel;
}
void BaseComponent::mouseDown(const MouseEvent& e)
{
	dragger.startDraggingComponent(this, e);
	resultOfMouseDownSelectMethod = documentView->addToSelectionOnMouseDown(this, e.mods);
	wasDraged = false;
	//remember X, Y
	lastX = getX();
	lastY = getY();

	//property panel
	if(documentView) 
	{
		documentView->getPropertyPanel()->clear();
		documentView->getPropertyPanel()->addSection("Properties", createPropertyComponents());
	}
}
void BaseComponent::mouseUp(const MouseEvent& e)
{
	documentView->addToSelectionOnMouseUp(this, e.mods, wasDraged,  resultOfMouseDownSelectMethod);
	wasDraged = false;
}
void BaseComponent::mouseDrag(const MouseEvent& e)
{
	dragger.dragComponent(this, e, nullptr);
	wasDraged = true;
	
	//drag other selected items
	int dx = getX() - lastX;
	int dy = getY() - lastY;
	documentView->multiSelectedMove(this, dx, dy);
	lastX = getX();
	lastY = getY();
}
void BaseComponent::mouseDoubleClick(const MouseEvent&/* e*/)
{
	/*
	PropertyPage *pg = new PropertyPage(this);
		//DialogWindow dlg = pg->findParentComponentOfClass<DialogWindow>();
		DialogWindow *dlg = new DialogWindow("dlg", Colours::lightgrey, true, false);
		dlg->showModalDialog("property", pg, getParentComponent(), Colours::lightgrey, false); 
		delete pg;
		delete dlg;
		*/
}
void BaseComponent::multiSelectedMove(int dx, int dy)
{
	Rectangle<int> rect = getBounds();
	rect.translate(dx, dy);
	setBounds(rect);
}

void BaseComponent::drawRectesWhenSelected(Graphics& g)
{
	if(wasSelected)
	{
		int w = getWidth();
		int h = getHeight();
		float size = 10.0f;

		g.setColour(Colour(0xcfffffff));
		g.fillRect(0.0f, 0.0f, size, size);
		g.fillRect(0.0f, h - size, size, size);
		g.fillRect(w - size, 0.0f, size, size);
		g.fillRect(w - size, h - size, size, size);

		g.setColour(Colour(0xcf000000));
		g.drawRect(0.0f, 0.0f, size, size, 1.0f);
		g.drawRect(0.0f, h - size, size, size, 1.0f);
		g.drawRect(w - size, 0.0f, size, size, 1.0f);
		g.drawRect(w - size, h - size, size, size, 1.0f);

	}
}