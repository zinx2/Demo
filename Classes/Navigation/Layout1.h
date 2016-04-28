#pragma once
#include "ViewBase.h"
#include "LayoutBase.h"

class Layout1 : public LayoutBase
{
private:
	ViewBase* _mainView;
public:
	Layout1(ViewBase* mainView);
	//virtual ~Layout1();

	virtual void initializeView();
	void changeColor();	

};
