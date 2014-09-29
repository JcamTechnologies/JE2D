#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "map.h"
#include "Entity.h"
#include "Animation.h"
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

	class Character : public Entity{
		public:
			Character();
			Character(JMAP* curMap);
			~Character();
			void onInit();
			void onUpdate();
			void onRender();
			bool collide(int direction);
			void moveChar(int direction, int pixels);
			int health;
			int attack;
			int defence;
			int speed;
			JMAP *map;
			std::string scriptName;
			int lastDirection;
			bool walk;
			ANIM* idleU;
			ANIM* idleD;
			ANIM* idleL;
			ANIM* idleR;
			ANIM* moveU;
			ANIM* moveD;
			ANIM* moveL;
			ANIM* moveR;
		private:
	};
}
#endif

