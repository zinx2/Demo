#include "MainView.h"

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

	Layout* mainLayout = Layout::create();
	mainLayout->setLayoutType(Layout::Type::VERTICAL);
	mainLayout->setSize(Size(960, 640));
	mainLayout->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	Button* button1 = Button::create();
	button1->setTitleText("Go To 1 Layout..");
	button1->setTitleFontSize(30);

	mainLayout->addChild(button1);
	this->addChild(mainLayout);

	return true;
}
