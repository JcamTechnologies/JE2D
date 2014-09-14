#include "Animation.h"
using namespace JE2D;
ANIM::ANIM()
{
}

ANIM::~ANIM()
{
}

bool ANIM::load(std::string filename, int frames, int frameW, int frameH, int speed)
{
	anim = al_load_bitmap(filename.c_str());
	if(!anim)
	{
		return false;
	}
	if(al_get_bitmap_width(anim)!=frameW)
	{
		return false;
	}
	this->frames = frames;
	this->speed = speed;
	fW = frameW;
	fH = frameH;
	curFrame = 0;
	return true;
}

void ANIM::render(int x, int y)
{
	if(anim)
	{
		ALLEGRO_BITMAP* tmp = al_create_bitmap(fW, fH);
		al_set_target_bitmap(tmp);
		al_draw_bitmap_region(anim, 0, curFrame*fH, fW, fH, 0, 0, 0);
		al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
		al_draw_bitmap(tmp, x, y, 0);
		if(curUp >= speed)
		{
			curUp = 0;
			curFrame++;
			if(curFrame >= frames)
			{
				curFrame = 0;
			}
		}
		curUp++;
		al_destroy_bitmap(tmp);
	}
}
