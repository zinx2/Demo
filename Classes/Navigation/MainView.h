#pragma once
#include "ViewBase.h"
#include "LayoutBase.h"

class MainView : public ViewBase
{
private:
	LayoutBase* _layout1;
	LayoutBase* _layout2;

	void injectRef();

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
