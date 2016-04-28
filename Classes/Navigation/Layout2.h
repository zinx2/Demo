#pragma once
#include "ViewBase.h"
#include "LayoutBase.h"

class Layout2 : public LayoutBase
{
private:
	ViewBase* _mainView;
public:
	Layout2(ViewBase* mainView);
	//virtual ~Layout2();

	virtual void initializeView();

};
