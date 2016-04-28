#include "LayoutBase.h"

bool LayoutBase::init()
{
	if (!Layout::init())
	{
		return false;
	}

	return true;
}

void LayoutBase::initializeView()
{

}