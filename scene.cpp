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
	characters = 0;
	entities = 0;
}

Scene::~Scene()
{
	s->~Sound();
}

void Scene::updateScene()
{
	for(std::vector<Character *>::iterator it = c.begin(); it < c.end(); it++)
	{
		(*it)->Update();
	}
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
	for(std::vector<Character *>::iterator it = c.begin(); it < c.end(); it++)
	{
		if((*it)->walk)
		{
			switch ((*it)->lastDirection)
			{
				case LEFT:
					(*it)->moveL->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case RIGHT:
					(*it)->moveR->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case UP:
					(*it)->moveU->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case DOWN:
					(*it)->moveD->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
			}
		}else
		{
			switch ((*it)->lastDirection)
			{
				case LEFT:
					(*it)->idleL->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case RIGHT:
					(*it)->idleR->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case UP:
					(*it)->idleU->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
				case DOWN:
					(*it)->idleD->render((-p->x)+tX+(*it)->x, (-p->y)+tY+(*it)->y);
					break;
			}
		}
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
	if(m->topRenderedMap)
	{
		if(m->topBlocks[(p->x+10)/20][(p->y+10)/20]!= -1)
		{
			al_draw_tinted_bitmap(m->topRenderedMap, al_map_rgba_f(0.5, 0.5, 0.5, 0.7), (-p->x)+tX, (-p->y)+tY, 0);
		}
		else
		{
			al_draw_bitmap(m->topRenderedMap, (-p->x)+tX, (-p->y)+tY, 0);
		}
		
	}
}
void Scene::postRenderScene()
{
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

int Scene::addCharacter()
{
	Character* tmp = new Character(m);
	tmp->Init();
	tmp->id = characters;
	c.push_back(tmp);
	characters++;
	return tmp->id;
}

int Scene::addEntity()
{
	Entity* tmp = new Entity();
	
	tmp->Init();
	tmp->id = entities;
	e.push_back(tmp);
	entities++;
	return tmp->id;
}

void Scene::deleteCharacter(int id)
{
	for(std::vector<Character *>::iterator it = c.begin(); it < c.end(); it++)
	{
		if((*it)->id == id)
		{
			it = c.erase(it);
			it--;
		}
	}
}
void Scene::deleteEntity(int id)
{
	for(std::vector<Entity *>::iterator it = e.begin(); it < e.end(); it++)
	{
		if((*it)->id == id)
		{
			it = e.erase(it);
			it--;
		}
	}
}

Character* Scene::getCharacter(int id)
{
	for(std::vector<Character *>::iterator it = c.begin(); it < c.end(); it++)
	{
		if((*it)->id == id)
		{
			std::cout<<"Found id:"<<(*it)->id<<std::endl;
			return (*it);
		}
	}
	std::cout << "ID "<<id<<" not found"<<std::endl;
}

Entity* Scene::getEntity(int id)
{
	for(std::vector<Entity *>::iterator it = e.begin(); it < e.end(); it++)
	{
		if((*it)->id == id)
		{
			return (*it);
		}
	}
}
