#ifndef _GUI_H_
#define _GUI_H_

#include "stdafx.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace JE2D
{
	typedef struct
	{
		std::string txt;
		int x, y;
		int time;
	} TEXT;
	class GUI
	{
		public:
			GUI();
			~GUI();
			void render();
			//void update();
			int addText(std::string text, int x, int y);
			int addTimedText(std::string text, int x, int y, int time);
			void setFont(std::string filename);
			std::vector<TEXT> t;
		private:
			
			ALLEGRO_FONT* font;
	};
}
#endif
