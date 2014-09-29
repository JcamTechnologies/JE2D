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
		int ID;
		bool del=false;
		ALLEGRO_COLOR color;
	} TEXT;
	class GUI
	{
		public:
			GUI();
			~GUI();
			void render();
			//void update();
			int addText(std::string text, int x, int y);
			int addText(std::string text, int x, int y, ALLEGRO_COLOR color);
			int addTimedText(std::string text, int x, int y, int time);
			int addTimedText(std::string text, int x, int y, int time, ALLEGRO_COLOR color);
			void editText(int id, std::string text);
			void setFont(std::string filename);
			std::vector<TEXT> t;
			int currentID;
		private:
			
			ALLEGRO_FONT* font;
	};
}
#endif
