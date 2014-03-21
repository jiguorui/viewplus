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
	resizeBorder = new ResizableBorderComponent(this, nullptr);
	addChildComponent(resizeBorder);
	resizeBorder->setBounds(getLocalBounds());	
	documentView = doc;
} 
BaseComponent::BaseComponent(SelectedItems* selectedItems)
{
	setSize(100, 100);
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
	g.drawRect(getLocalBounds(), 1);
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