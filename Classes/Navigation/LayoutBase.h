#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class LayoutBase : public Layout
{
public:
	virtual bool init();
	virtual void initializeView();
	virtual ~LayoutBase() {}
	CREATE_FUNC(LayoutBase);
};