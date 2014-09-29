#include "Character.h"
using namespace JE2D;

Character::Character()
{
	lastDirection = 0;
	walk=false;
	idleD = new ANIM();
	idleU = new ANIM();
	idleL = new ANIM();
	idleR = new ANIM();
	moveD = new ANIM();
	moveU = new ANIM();
	moveL = new ANIM();
	moveR = new ANIM();
}

Character::Character(JMAP* curMap)
{
	map = curMap;
	lastDirection = 0;
	walk=false;
}

Character::~Character()
{

}

void Character::onInit()
{
}

void Character::onUpdate()
{
	if(walk)
	{
		walk = false;
	}
}

void Character::onRender()
{
}

bool Character::collide(int direction)
{
	switch(direction)
	{
		case LEFT:
			if(map->collision[(int)((x-1)/20)][(int)(y/20)]==1)
			{
				return true;
			}
			if(map->collision[(int)((x-1)/20)][(int)((y+19)/20)]==1)
			{
				return true;
			}
			break;
		case RIGHT:
			if(map->collision[(int)((x+20)/20)][(int)(y/20)]==1)
			{
				return true;
			}
			if(map->collision[(int)((x+20)/20)][(int)((y+19)/20)]==1)
			{
				return true;
			}
			break;
		case UP:
			if(map->collision[(int)(x/20)][(int)((y-1)/20)]==1)
			{
				return true;
			}
			if(map->collision[(int)((x+19)/20)][(int)((y-1)/20)]==1)
			{
				return true;
			}
			break;
		case DOWN:
			if(map->collision[(int)(x/20)][(int)((y+20)/20)]==1)
			{
				return true;
			}
			if(map->collision[(int)((x+19)/20)][(int)((y+20)/20)]==1)
			{
				return true;
			}
			break;
	}
	return false;
}
void Character::moveChar(int direction, int pixels)
{
	int move = 0;
	lastDirection = direction;
	walk = true;
	while(move < pixels)
	{
		switch(direction)
		{
			case LEFT:
				dir = LEFT;
				if(!collide(LEFT))
				{
					x--;
					move++;
				}else
				{
					move=pixels;
				}
				break;

			case RIGHT:
				dir = RIGHT;
				if(!collide(RIGHT))
				{
					x++;
					move++;
				}else
				{
					move=pixels;
				}
				break;

			case UP:
				dir = UP;
				if(!collide(UP))
				{
					y--;
					move++;
				}else
				{
					move=pixels;
				}
				break;

			case DOWN:
				dir = DOWN;
				if(!collide(DOWN))
				{
					y++;
					move++;
				}else
				{
					move=pixels;
				}
				break;
		}
	}
}
