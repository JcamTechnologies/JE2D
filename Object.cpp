#include "Object.h"

using namespace JE2D;

JOBJECT::JOBJECT()
{
	
}

JOBJECT::~JOBJECT()
{
	detach();
}

void JOBJECT::init()
{
	onInit();
}

void JOBJECT::update()
{
	onUpdate();
	/*if(getChild())
	{
		((JOBJECT*)getChild())->update();
	}*/
}

void JOBJECT::render()
{
	onRender();
	if(getChild())
	{
		((JOBJECT*)getChild())->render();
	}
}
