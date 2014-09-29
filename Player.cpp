#include "Player.h"
using namespace JE2D;

JPLAYER::JPLAYER()
{
	lastDirection = 0;
	walk=false;
}

JPLAYER::JPLAYER(JMAP* curMap)
{
	map = curMap;
	lastDirection = 0;
	walk=false;
}

JPLAYER::~JPLAYER()
{
	
}

void JPLAYER::onInit()
{
}

void JPLAYER::onUpdate()
{
	if(walk)
	{
		walk = false;
	}
}

void JPLAYER::onRender()
{
}

bool JPLAYER::collide(int direction)
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
void JPLAYER::movePlayer(int direction, int pixels)
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
				if(!collide(LEFT) && x > 0)
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
				if(!collide(RIGHT)&& x < 3999)
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
				if(!collide(UP)&& y > 0)
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
				if(!collide(DOWN)&& y < 3999)
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
