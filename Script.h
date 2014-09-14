#ifndef _SCRIPT_H_
#define _SCRIPT_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "luawrapper.hpp"
#include "include/lua.hpp"
#include "Player.h"
#include "Object.h"
#include "Node.h"
#include "Entity.h"
#include "Character.h"
#include "Map.h"
#include "Sound.h"
#include "stdafx.h"


namespace JE2D
{
	class Script
	{
		public:
			Script();
			Script(lua_State* L);
			~Script();
			void init();
			lua_State* run(std::string filename);
			lua_State* L;
		private:
			std::string filename;
	
	};
}
#endif
