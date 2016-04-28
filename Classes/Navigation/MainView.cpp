#include "MainView.h"
#include "Layout1.h"
#include "Layout2.h"

//MainView::MainView()
//{
//
//}
//
//MainView::~MainView()
//{
//}
void MainView::injectRef()
{
	_layout1 = new Layout1(this);
	_layout2 = new Layout2(this);
}
Scene* MainView::createScene()
{
	auto scene = Scene::create();
	auto layer = MainView::create();
	scene->addChild(layer);
	return scene;
}

bool MainView::init()
{
	if (!Layer::init())
	{
		return false;
	}
	injectRef();
	initializeView();
	return true;
}

void MainView::initializeView()
{


	Layout* mainLayout = Layout::create();
	mainLayout->setSize(Size(960, 640));
	mainLayout->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	mainLayout->setPosition(Vec2(0, 0));

	
	mainLayout->addChild(_layout1);

	
	_layout2->initializeView();
	_layout2->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	_layout2->setPosition(Vec2(0, 320));
	_layout2->setZOrder(0);
	mainLayout->addChild(_layout2);

	Button* button1 = Button::create();
	button1->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	button1->setPosition(Vec2(0, 0));
	button1->setTitleText("Go To 1 Layout..");
	button1->setTitleFontSize(30);
	button1->setZOrder(1);
	button1->addClickEventListener([&](Ref* ref)
	{
		//if (_layout1 == nullptr)
		//{	
		_layout1->initializeView();
		_layout1->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
		_layout1->setPosition(Vec2(0, 0));
		_layout1->setZOrder(0);
		//}

	});

	mainLayout->addChild(button1);
	this->addChild(mainLayout);
}
//
void MainView::chaneColorLayout1()
{
	ViewBase::chaneColorLayout1();
	_layout1->setBackGroundColor(Color3B::RED);

	MoveBy *moveBy = MoveBy::create(2.0, Point(100, 0));
	this->runAction(moveBy);
}

LayoutBase* MainView::getLayout1()
{
	return _layout1;
}