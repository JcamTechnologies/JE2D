#include "GUI.h"

using namespace JE2D;

GUI::GUI()
{
	
}

GUI::~GUI()
{
	
}

void GUI::setFont(std::string filename)
{
	font = al_load_ttf_font(filename.c_str(), 24, 0);
}

int GUI::addText(std::string text, int x, int y)
{
	TEXT tmp;
	tmp.txt = text;
	tmp.x=x;
	tmp.y=y;
	tmp.time = -1;
	t.push_back(tmp);
	return t.size()-1;
}
int GUI::addTimedText(std::string text, int x, int y, int time)
{
	TEXT tmp;
	tmp.txt = text;
	tmp.x=x;
	tmp.y=y;
	tmp.time = time;
	t.push_back(tmp);
	return t.size()-1;
}
void GUI::render()
{
	if(font)
	{
		for(std::vector<TEXT>::iterator it = t.begin(); it < t.end(); it++)
		{
			if(it->time == -1)
			{
				al_draw_text(font, al_map_rgb(255,240,255), it->x, it->y, ALLEGRO_ALIGN_LEFT, it->txt.c_str());
			}
			if(it->time > 0)
			{
				it->time--;
				al_draw_text(font, al_map_rgb(255,240,255), it->x, it->y, ALLEGRO_ALIGN_LEFT, it->txt.c_str());
			}
			
		}
	}
}
