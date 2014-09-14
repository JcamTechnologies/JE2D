#include "scene.h"

using namespace JE2D;

Scene::Scene()
{
	s = new Sound();
	runRight = new ANIM();
	runLeft = new ANIM();
	runFront = new ANIM();
	runBack = new ANIM();
	idleRight = new ANIM();
	idleLeft = new ANIM();
	idleBack = new ANIM();//those of you with OCD will HATE me for these lines...
	idleFront = new ANIM();//if you don't have OCD, you have no idea what I'm talking about.
	m = new JMAP();
	m->init();
	p = new JPLAYER();
	p->init();
	gui = new GUI();
}

Scene::~Scene()
{
	s->~Sound();
}

void Scene::updateScene()
{
	p->update();
}

void Scene::renderScene()
{
	int tX = al_get_display_width(al_get_current_display())/2;
	int tY = al_get_display_height(al_get_current_display())/2;
	if(m->renderedMap)
	{
		al_draw_bitmap(m->renderedMap, (-p->x)+tX, (-p->y)+tY, 0);
	}
	if(p->walk)
	{
		switch (p->lastDirection)
		{
			case LEFT:
				runLeft->render(tX, tY);
				break;
			case RIGHT:
				runRight->render(tX, tY);
				break;
			case UP:
				runBack->render(tX, tY);
				break;
			case DOWN:
				runFront->render(tX, tY);
				break;
		}
	}else
	{
		switch (p->lastDirection)
		{
			case LEFT:
				idleLeft->render(tX, tY);
				break;
			case RIGHT:
				idleRight->render(tX, tY);
				break;
			case UP:
				idleBack->render(tX, tY);
				break;
			case DOWN:
				idleFront->render(tX, tY);
				break;
		}
	}
	gui->render();
}

bool Scene::addSound(std::string filename, std::string key)
{
	return s->add(filename, key);
}

bool Scene::loadMap(std::string filename)
{
	m->clearMap();
	if(m->load(filename.c_str()))
	{
		return false;
	}
	p->map = m;
	return true;
}
