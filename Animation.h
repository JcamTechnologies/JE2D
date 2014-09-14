#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include "stdafx.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <math.h>
namespace JE2D
{
	class ANIM
	{
		public:
			ANIM();
			~ANIM();
			bool load(std::string filename, int frames, int frameW, int frameH, int speed);
			void render(int x, int y);
		private:
			int frames, fW, fH;
			int curFrame;
			int speed;
			int curUp;
			ALLEGRO_BITMAP* anim;
	};
}
#endif // _ANIMATION_H_
