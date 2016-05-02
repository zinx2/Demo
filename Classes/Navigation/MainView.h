#pragma once
#include "ViewBase.h"
#include "LayoutBase.h"
#include <queue>

class MainView : public ViewBase
{
private:
	LayoutBase* _layout1;
	LayoutBase* _layout2;

	void injectRef();
	void addWidget(Widget* parent, queue<Widget*> widgets);
public:
	//MainView();
	//virtual ~MainView();
	LayoutBase* getLayout1();

	void initializeView();
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void chaneColorLayout1();
	CREATE_FUNC(MainView);
};
