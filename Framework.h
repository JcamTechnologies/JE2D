#ifndef _JFRAMEWORK_H_
#define _JFRAMEWORK_H_
#ifdef __APPLE__
	#define OS "MAC"
#else
	#define OS "WINDOWS"
#endif
#define BUILD 1
#include "Script.h"
#include "Player.h"
#include "Character.h"
#include "Sound.h"
#include "stdafx.h"
#include "include/lua.hpp"
#include "luawrapper.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//TODO: comment all codebase
namespace JE2D
{
	class JFRAMEWORK
	{
			int screenWidth, screenHeight;
			std::fstream logfile;
			ALLEGRO_DISPLAY *display;
			ALLEGRO_EVENT_QUEUE *event;
			ALLEGRO_TIMER *timer;
			lua_State* L;
			Script* script;
			ALLEGRO_SHADER* shader;
		public:
			JFRAMEWORK();
			~JFRAMEWORK();
			int init();
			int update();
			int render();
			void logInit(const char *filename);
	        void logData(const char *data, int variable);
	        void logData(const char *data);
			void handle_error(int error);
			bool redraw;
			bool keys[ALLEGRO_KEY_MAX];
			bool exit;
		protected:
			// Protected Declarations
	};
}

#endif

