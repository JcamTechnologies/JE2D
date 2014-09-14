#ifndef _SCENE_H_
#define _SCENE_H_
#include "stdafx.h"
#include "Map.h"
#include "Script.h"
#include "Player.h"
#include "Object.h"
#include "Character.h"
#include "Animation.h"
#include "GUI.h"

namespace JE2D
{
	class Scene
	{
		public:
			Scene();
			~Scene();
			void updateScene();
			void renderScene();
			bool addSound(std::string filename, std::string key);
			bool loadMap(std::string filename);
			ANIM* runLeft;
			ANIM* runRight;
			ANIM* runFront;
			ANIM* runBack;
			ANIM* idleFront;
			ANIM* idleBack;
			ANIM* idleLeft;
			ANIM* idleRight;
			GUI* gui;
			Sound* s;
			JMAP* m;
			JPLAYER* p;
	};
}
#endif //_SCENE_H_
