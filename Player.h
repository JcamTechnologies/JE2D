#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "map.h"
#include "Object.h"
#include "Script.h"
#include "include/lua.hpp"
#include "luawrapper.hpp"
#include "stdafx.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

namespace JE2D
{
	typedef struct
	{
			int type;
			std::map<std::string, int> metadata;
	}JITEM;
	typedef struct
	{
			int quantity;
			JITEM item;
	}JSTACK;
	
	class JPLAYER : public JOBJECT{
		public:
			JPLAYER();
			JPLAYER(JMAP* curMap);
			~JPLAYER();
			void onInit();
			void onUpdate();
			void onRender();
			bool collide(int direction);
			void movePlayer(int direction, int pixels);
			//bool addItemToInv(JITEM i);
			int health;
			int attack;
			int defence;
			int speed;
			JMAP *map;
			int lastDirection;
			bool walk;
		private:
			
			JSTACK inventory[5][5];
			JITEM hand;
	};
}
#endif

