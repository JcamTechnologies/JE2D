#include "Entity.h"
using namespace JE2D;
Entity::Entity()
{
	
}
Entity::~Entity()
{
}
void Entity::Init()
{
	x = 0;
	dir = 0;
	y = 0;
	onInit();
}

void Entity::Update()
{
	onUpdate();
	if(getChild())
	{
		((Entity*)getChild())->Update();
	}
}

void Entity::Render()
{
	onRender();
	if(getChild())
	{
		((Entity*)getChild())->Render();
	}
}
