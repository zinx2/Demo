#include "Layout1.h"
#include "MainView.h"

Layout1::Layout1(ViewBase* mainView)
{
	_mainView = mainView;
}

//Layout1::~Layout1()
//{
//}

void Layout1::initializeView()
{
	LayoutBase::initializeView();
	this->setSize(Size(960, 320));
	this->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	this->setBackGroundColor(Color3B::BLUE);
}

void Layout1::changeColor()
{
	this->setBackGroundColor(Color3B::RED);
}