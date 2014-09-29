#ifndef _LUA_CLASS_DEF_H_
#define _LUA_CLASS_DEF_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Object.h"
#include "Player.h"
#include "Map.h"
#include "Sound.h"
#include "Entity.h"
#include "Character.h"
#include "scene.h"
#include "Image.h"
#include "GUI.h"
#include "luawrapper.hpp"
#include "include/lua.hpp"
using namespace JE2D;
int System_run(lua_State* L)
{
	std::string filename = luaL_checkstring(L, 1);
	lua_State* tmp = L;
	if(luaL_loadfile(tmp, filename.c_str()))
	{
		std::cout << "Failed to load file:"<<filename<<std::endl;
		std::cout<<lua_tostring(L, -1)<<std::endl;
		return 0;
	}
	if(lua_pcall(tmp, 0, 0xd, 0))
	{
		std::cout << "Failed to run script:" << filename<< std::endl;
		std::cout<<lua_tostring(L, -1)<<std::endl;
		return 0;
	}
	L = tmp;
	return 0;
}

Sound* Sound_new(lua_State* L)
{
	Sound* s = new Sound();
	return s;
}

int Sound_add(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	bool pass = s->add(luaL_checkstring(L,2), luaL_checkstring(L,3));
	lua_pushboolean(L, pass);
	return 1;
}

int Sound_remove(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	s->remove(luaL_checkstring(L, 2));
	return 0;
}
int Sound_removeAll(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	s->removeAll();
	return 0;
}
int Sound_play(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	s->playSound(luaL_checkstring(L, 2), luaL_checknumber(L, 3));
	return 0;
}
int Sound_stop(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	s->stopSound(luaL_checkstring(L, 2));
	return 0;
}
int Sound_stopAll(lua_State* L)
{
	Sound* s = luaW_check<Sound>(L, 1);
	s->stopAll();
	return 0;
}
JPLAYER* Player_new(lua_State* L)
{
	JMAP* m = luaW_check<JMAP>(L, 1);
	JPLAYER* p = new JPLAYER(m);
	return p;
}
int Player_setHealth(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	int h = luaL_checknumber(L,2);
	p->health = h;
	return 0;
}
int Player_getHealth(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	lua_pushnumber(L, p->health);
	return 1;
}
int Player_setSpeed(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	int s = luaL_checknumber(L,2);
	p->speed = s;
	return 0;
}
int Player_getSpeed(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	lua_pushnumber(L, p->speed);
	return 1;
}
int Player_setDefence(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	int d = luaL_checknumber(L,2);
	p->defence = d;
	return 0;
}
int Player_getDefence(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	lua_pushnumber(L, p->defence);
	return 1;
}
int Player_setAttack(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	int a = luaL_checknumber(L,2);
	p->attack = a;
	return 0;
}
int Player_getAttack(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L,1);
	lua_pushnumber(L, p->attack);
	return 1;
}
int Player_setPos(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	int x = luaL_checknumber(L, 2);
	int y = luaL_checknumber(L, 3);
	p->x = x;
	p->y = y;
	return 0;
}
int Player_getX(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	lua_pushnumber(L, p->x);
	return 1;
}
int Player_getY(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	lua_pushnumber(L, p->y);
	return 1;
}
int Player_render(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	p->render();
	return 0;
}
int Player_move(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	int dir = luaL_checknumber(L, 2);
	int pix = luaL_checknumber(L, 3);
	p->movePlayer(dir, pix);
	return 0;
}
int Player_getTileX(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	lua_pushnumber(L,(p->x+10)/20);
	return 1;
}
int Player_getTileY(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	lua_pushnumber(L,(p->y+10)/20);
	return 1;
}
int Player_getDir(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	lua_pushnumber(L, p->dir);
	return 1;
}
int Player_setDir(lua_State* L)
{
	JPLAYER* p = luaW_check<JPLAYER>(L, 1);
	p->dir = luaL_checknumber(L, 2);
	return 0;
}
JMAP* Map_new(lua_State* L)
{
	const char* mapFilename = luaL_checkstring(L, 1);
	JMAP* m = new JMAP();
	m->init();
	m->load(mapFilename);
	return m;
}

int Map_save(lua_State* L)
{
	JMAP* m = luaW_check<JMAP>(L,1);
	std::string file = luaL_checkstring(L,2);
	m->save(file.c_str());
	return 0;
}
int Map_load(lua_State* L)
{
	JMAP* m = luaW_check<JMAP>(L,1);
	std::string file = luaL_checkstring(L, 2);
	m->clearMap();
	m->load(file.c_str());
	return 0;
}

int Map_getTrigger(lua_State* L)
{
	JMAP* m = luaW_check<JMAP>(L,1);
	if(m->collision[(int)luaL_checknumber(L,2)][(int)luaL_checknumber(L, 3)] > 1)
	{
		lua_pushstring(L, m->scriptName[m->collision[(int)luaL_checknumber(L,2)][(int)luaL_checknumber(L, 3)]-2].c_str());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}
int Map_editCollision(lua_State* L)
{
	JMAP* m = luaW_check<JMAP>(L,1);
	m->collision[(int)luaL_checknumber(L,2)][(int)luaL_checknumber(L, 3)]=(int)luaL_checknumber(L, 4);
	return 0;
}
Scene* Scene_new(lua_State* L)
{
	Scene* s = new Scene();
	return s;
}
int Scene_addSound(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	std::string file = luaL_checkstring(L, 2);
	std::string key = luaL_checkstring(L,3);
	s->addSound(file, key);
	return 0;
}
int Scene_loadMap(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	std::string file = luaL_checkstring(L,2);
	s->loadMap(file);
	return 0;
}
int Scene_update(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	s->updateScene();
	return 0;
}
int Scene_render(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	s->renderScene();
	return 0;
}
int Scene_renderGUI(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	s->postRenderScene();
	return 0;
}
int Scene_getPlayer(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	luaW_push<JPLAYER>(L, s->p);
	return 1;
}
int Scene_getMap(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	luaW_push<JMAP>(L, s->m);
	return 1;
}
int Scene_getSound(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	luaW_push<Sound>(L, s->s);
	return 1;
}
int Scene_addPlayerAnim(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	int type = luaL_checknumber(L, 2);
	int dir = luaL_checknumber(L, 3);
	int frames = luaL_checknumber(L, 4);
	int speed = luaL_checknumber(L, 5);
	std::string fname = luaL_checkstring(L, 6);
	std::cout << type <<std::endl;
	if(type == 1)
	{
		switch (dir)
		{
			case LEFT:
				s->runLeft->load(fname, frames, 20, 20, speed);
				break;
			case RIGHT:
				s->runRight->load(fname, frames, 20, 20, speed);
				break;
			case UP:
				s->runBack->load(fname, frames, 20, 20, speed);
				break;
			case DOWN:
				s->runFront->load(fname, frames, 20, 20, speed);
				break;
		}
	}
	if(type == 0)
	{
		switch (dir)
		{
			case LEFT:
				s->idleLeft->load(fname, frames, 20, 20, speed);
				break;
			case RIGHT:
				s->idleRight->load(fname, frames, 20, 20, speed);
				break;
			case UP:
				s->idleBack->load(fname, frames, 20, 20, speed);
				break;
			case DOWN:
				s->idleFront->load(fname, frames, 20, 20, speed);
				break;
		}
	}
	return 0;
}

int Scene_loadFont(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	s->gui->setFont(luaL_checkstring(L, 2));
	return 0;
}
int Scene_setText(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	lua_pushnumber(L, s->gui->addText(luaL_checkstring(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4)));
	return 1;
}
int Scene_setTextC(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	lua_pushnumber(L, s->gui->addText(luaL_checkstring(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), al_map_rgb(luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7))));
	return 1;
}
int Scene_setTimedTextC(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	lua_pushnumber(L, s->gui->addTimedText(luaL_checkstring(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), al_map_rgb(luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7))));
	return 1;
}
int Scene_setTimedText(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L,1);
	lua_pushnumber(L, s->gui->addTimedText(luaL_checkstring(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5)));
	return 1;
}
int Scene_deleteText(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	int key = luaL_checknumber(L, 2);
	s->gui->editText(key, " ");
	return 0;
}
int Scene_editText(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	int key = luaL_checknumber(L, 2);
	s->gui->editText(key, luaL_checkstring(L, 3));
	return 0;
}
int Scene_editTextTime(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	int key = luaL_checknumber(L, 2);
	s->gui->t[key].txt = luaL_checknumber(L, 3);
	return 0;
}
int Scene_addCharacter(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	lua_pushnumber(L, s->addCharacter());
	return 1;
}
int Scene_addEntity(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	lua_pushnumber(L, s->addEntity());
	return 1;
}
int Scene_getCharacter(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	Character* c = s->getCharacter(luaL_checknumber(L, 2));
	luaW_push<Character>(L, c);
	return 1;
}
int Scene_getEntity(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	luaW_push<Entity>(L, s->getEntity(luaL_checknumber(L, 2)));
	return 1;
}
int Scene_deleteCharacter(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	s->deleteCharacter(luaL_checknumber(L, 2));
	return 0;
}
int Scene_deleteEntity(lua_State* L)
{
	Scene* s = luaW_check<Scene>(L, 1);
	s->deleteEntity(luaL_checknumber(L,2));
	return 0;
}
IMAGE* Image_new(lua_State* L)
{
	IMAGE* i = new IMAGE();
	return i;
}

int Image_load(lua_State* L)
{
	IMAGE* i = luaW_check<IMAGE>(L,1);
	i->b = al_load_bitmap(luaL_checkstring(L, 2));
	if(!i->b)
	{
		lua_pushnumber(L, 0);
	}
	else
	{
		lua_pushnumber(L, 1);
	}
	return 1;
}

int Image_draw(lua_State* L)
{
	IMAGE* i = luaW_check<IMAGE>(L,1);
	if(i->b)
	{
		al_draw_bitmap(i->b, luaL_checknumber(L, 2), luaL_checknumber(L, 3), 0);
	}
	return 0;
}
int Image_drawRotR(lua_State* L)
{
	IMAGE* i = luaW_check<IMAGE>(L,1);
	if(i->b)
	{
		al_draw_rotated_bitmap(i->b, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), 0);
	}
}
int Image_drawRotD(lua_State* L)
{
	IMAGE* i = luaW_check<IMAGE>(L,1);
	if(i->b)
	{
		al_draw_rotated_bitmap(i->b, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), (luaL_checknumber(L, 6))*(ALLEGRO_PI/180), 0);
	}
}
Entity* Entity_new(lua_State* L)
{
	Entity* e = new Entity();
	e->Init();
	return e;
}
int Entity_getX(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	lua_pushnumber(L, e->x);
	return 1;
}
int Entity_getY(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	lua_pushnumber(L, e->y);
	return 1;
}
int Entity_setPos(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	e->x = luaL_checknumber(L, 2);
	e->y = luaL_checknumber(L, 3);
	return 0;
}
int Entity_setMeta(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	e->meta[luaL_checkstring(L, 2)]=luaL_checkstring(L, 3);
	return 0;
}
int Entity_getMeta(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	lua_pushstring(L, e->meta[(std::string)luaL_checkstring(L, 2)].c_str());
	return 1;
}
int Entity_getDir(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	lua_pushnumber(L, e->dir);
	return 1;
}
int Entity_setDir(lua_State* L)
{
	Entity* e = luaW_check<Entity>(L, 1);
	e->dir = luaL_checknumber(L, 2);
	return 0;
}

Character* Character_new(lua_State* L)
{
	Character* c = new Character();
	c->Init();
	return c;
}
int Character_getX(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	lua_pushnumber(L, c->x);
	return 1;
}
int Character_getY(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	lua_pushnumber(L, c->y);
	return 1;
}
int Character_setPos(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	c->x = luaL_checknumber(L, 2);
	c->y = luaL_checknumber(L, 3);
	return 0;
}
int Character_setMeta(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	c->meta[luaL_checkstring(L, 2)]=luaL_checkstring(L, 3);
	return 0;
}
int Character_getMeta(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	lua_pushstring(L, c->meta[(std::string)luaL_checkstring(L, 2)].c_str());
	return 1;
}
int Character_getDir(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	lua_pushnumber(L, c->dir);
	return 1;
}
int Character_setDir(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	c->dir = luaL_checknumber(L, 2);
	return 0;
}
int Character_addAnim(lua_State* L)
{
	Character* c = luaW_check<Character>(L, 1);
	int type = luaL_checknumber(L, 2);
	int dir = luaL_checknumber(L, 3);
	int frames = luaL_checknumber(L, 4);
	int speed = luaL_checknumber(L, 5);
	std::string fname = luaL_checkstring(L, 6);
	bool error = true;
	if(type == 1)
	{
		switch (dir)
		{
			case LEFT:
				error=c->moveL->load(fname, frames, 20, 20, speed);
				break;
			case RIGHT:
				error=c->moveR->load(fname, frames, 20, 20, speed);
				break;
			case UP:
				error=c->moveU->load(fname, frames, 20, 20, speed);
				break;
			case DOWN:
				error=c->moveD->load(fname, frames, 20, 20, speed);
				break;
		}
	}
	if(type == 0)
	{
		switch (dir)
		{
			case LEFT:
				error=c->idleL->load(fname, frames, 20, 20, speed);
				break;
			case RIGHT:
				error=c->idleR->load(fname, frames, 20, 20, speed);
				break;
			case UP:
				error=c->idleU->load(fname, frames, 20, 20, speed);
				break;
			case DOWN:
				error=c->idleD->load(fname, frames, 20, 20, speed);
				break;
		}
	}
	if(error==false)
	{
		lua_pushnumber(L, 1);
	}else
	{
		lua_pushnumber(L, 0);
	}
	return 1;
}
#endif
