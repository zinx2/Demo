#include "Layout2.h"
#include "MainView.h"

Layout2::Layout2(ViewBase* mainView)
{
	_mainView = mainView;
}

//Layout2::~Layout2()
//{
	//if (_mainView != nullptr) delete _mainView;
	//this->autorelease();
//}

void Layout2::initializeView()
{
	LayoutBase::initializeView();
	this->setSize(Size(960, 320));
	this->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	this->setBackGroundColor(Color3B::YELLOW);

	Button* button1 = Button::create();
	button1->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	button1->setPosition(Vec2(0, 0));
	button1->setTitleText("Go To 2 Layout..");
	button1->setTitleFontSize(30);
	button1->setZOrder(1);
	button1->addClickEventListener([&](Ref* ref)
	{
		auto view = static_cast<MainView*> (_mainView);
		//LayoutBase* layout1 = _mainView->getLayout1();
		LayoutBase* layout1 = view->getLayout1();
		view->chaneColorLayout1();
		MoveBy *moveBy = MoveBy::create(2.0, Point(100, 0));
		layout1->runAction(moveBy);
	});

	this->addChild(button1);
}