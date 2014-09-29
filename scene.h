#ifndef _SCENE_H_
#define _SCENE_H_
#include "stdafx.h"
#include "Map.h"
#include "Script.h"
#include "Player.h"
#include "Object.h"
#include "Entity.h"
#include "Animation.h"
#include "GUI.h"
#include "Character.h"
namespace JE2D
{
	class Scene
	{
		public:
			Scene();
			~Scene();
			void updateScene();
			void renderScene();
			void postRenderScene();
			bool addSound(std::string filename, std::string key);
			bool loadMap(std::string filename);
			int addEntity();
			int addCharacter();
			Character* getCharacter(int id);
			Entity* getEntity(int id);
			void deleteCharacter(int id);
			void deleteEntity(int id);
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
			
			std::vector<Character *> c;
			std::vector<Entity *> e;
			JMAP* m;
			JPLAYER* p;
			int entities;
			int characters;
	};
}
#endif //_SCENE_H_
