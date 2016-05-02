#include "MainView.h"
#include "Layout1.h"
#include "Layout2.h"

#define CREATE_WIDGET(TYPE, CHILD) TYPE* CHILD = TYPE::create();

#define TO(PARENT) PARENT->
#define OF(WIDGET) WIDGET->
#define SET 
#define SIZE(x, y) setSize(Size(x, y));
#define ANCHOR(anchor) AnchorPoint(Point::anchor);
#define POSITION(x, y) Position(Vec2(x, y));


#define ADD(CHILD) addChild(CHILD);
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

	CREATE_WIDGET(Layout, mainLayout)
	TO(this) ADD(mainLayout)
	TO(mainLayout) ADD(_layout1)
		//TO(mainLayout)

	OF(mainLayout) SET SIZE(960, 640)
	//OF(mainLayout) SET ANCHOR(ANCHOR_BOTTOM_LEFT)
	//OF(mainLayout) SET POSITION(0, 0)

	
	//mainLayout->addChild(_layout1);

	
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

	//mainLayout->addChild(button1);
	//addWidget(mainLayout)
	//this->addChild(mainLayout);
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

void MainView::addWidget(Widget* parent, queue<Widget*> widgets)
{
	while (widgets.size() != 0)
	{
		parent->addChild(widgets.front());
		widgets.pop();
	}
}