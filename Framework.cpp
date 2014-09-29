#include "Framework.h"

using namespace JE2D;

JFRAMEWORK::JFRAMEWORK()
{
	exit = false;
}

JFRAMEWORK::~JFRAMEWORK()
{
	if(logfile.is_open())
	{
		logfile.close();
	}
	script->~Script();
}

int JFRAMEWORK::init()
{
	display = NULL;
	event = NULL;
	al_set_new_window_position(10,20);
	if(!al_init())
	{
		return 201;
	}
	timer = al_create_timer(1.0 / 60.0);
	if(!timer)
	{
		return 202;
		al_destroy_timer(timer);
	}
	event = al_create_event_queue();
	if(!event)
	{
		return 203;
	}
	if(!al_install_mouse)
	{
		return 204;
	}
	if(!al_install_keyboard)
	{
		return 205;
	}
	if(!al_install_audio())
	{
		return 206;
	}
	if(!al_init_acodec_addon())
	{
		return 207;
	}
	if(!al_reserve_samples(256))
	{
		return 208;
	}
	al_set_window_title(display, "Jcam Engine 2D v. 2.0");
	al_inhibit_screensaver(true);
	if(!al_install_keyboard())
	{
		return 210;
	}
	if(!al_init_image_addon())
	{
		return 211;
	}
	if(!al_init_native_dialog_addon())
	{
		return 212;
	}
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(800, 600);
	if(!display)
	{
		return 209;
	}
	al_init_font_addon();
	al_init_ttf_addon();
	al_register_event_source(event, al_get_display_event_source(display));
	al_register_event_source(event, al_get_timer_event_source(timer));
	al_register_event_source(event, al_get_keyboard_event_source());
	
	logInit("EngineLog.txt");
	logData("Logfile Initialized");
	logData("Engine Version", 2);
	logData(OS, BUILD);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	ALLEGRO_BITMAP* logo = al_load_bitmap("Resources/logo.png");
	if(!logo)
	{
		return 102;
	}
	Sound* sounds = new Sound();
	if(!sounds->add("Resources/jingle.ogg", "startup"))
	{
		return 103;
	}
	sounds->playSound("startup", 0);
	al_hide_mouse_cursor(display);
	al_draw_scaled_bitmap(logo, 0, 0, 800, 450, 0, 0, al_get_display_width(display), al_get_display_height(display), 0);
	al_flip_display();
	al_rest(1.0);
	sounds->remove("startup");
	al_destroy_bitmap(logo);
	al_start_timer(timer);
	script = new Script(L);
	script->init();
	logData("Running startup script");
	L = script->run("Scripts/startup.lua");
	if(L == NULL)
	{
		return 211;
	}
	lua_pushnumber(L, 0);
	lua_setglobal(L, "EXIT");
	lua_getglobal(L, "DISPX");
	lua_getglobal(L, "DISPY");
	if (!lua_isnumber(L, -2)) {
        return 211;
    }
    if (!lua_isnumber(L, -1))
    {
        return 211;
    }
    if(!al_resize_display(display, (int)lua_tonumber(L, -2), (int)lua_tonumber(L, -1)))
    {
    	return 209;
    }
	logData("ScreenWidth", al_get_display_width(display));
	logData("ScreenHeight", al_get_display_height(display));
	logData("Init Complete");
	logData("---");
	return 0;
}


int JFRAMEWORK::update()
{
	ALLEGRO_EVENT ev;
	al_wait_for_event(event, &ev);
	int lK;
	int kdir = 0;
	if(ev.type == ALLEGRO_EVENT_TIMER)
	{
		redraw = true;
	}
	else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		al_inhibit_screensaver(false);
		logData("Closed successfully");
		return 300;
	}else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		keys[ev.keyboard.keycode] = true;
		lK = ev.keyboard.keycode;
		kdir = 1;
	}else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		keys[ev.keyboard.keycode] = false;
		lK = ev.keyboard.keycode;
		kdir = 2;
	}
	lua_getglobal(L, "update");
	lua_pushnumber(L, lK);
	lua_pushnumber(L, kdir);
	if(lua_pcall(L, 2, 0, 0))
	{
		logData(lua_tostring(L, -1));
		return 301;
	}
	lua_getglobal(L, "EXIT");
	int e = (int)lua_tonumber(L, -1);
	if(e == 1)
	{
		logData("Exited successfully");
		exit = true;
	}
	
	return 0;
}


int JFRAMEWORK::render()
{
	if(redraw)
	{
		al_set_target_bitmap(al_get_backbuffer(display));
		al_clear_to_color(al_map_rgb(0,0,0));
		lua_getglobal(L, "render");
		if(lua_pcall(L, 0, 0, 0))
		{
			logData(lua_tostring(L, -1));
			return 401;
		}
		al_flip_display();
		redraw=false;
	}
	return 0;
}


void JFRAMEWORK::handle_error(int error)
{
	if(error == 300)
	{
		return;
	}
	al_show_mouse_cursor(display);
	char er[10];
	itoa(error, er, 10);
	logData("Encountered Error", error);
	al_show_native_message_box(al_get_current_display(), "JE2D 2.0 Error", "Encountered error:\n", er, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void JFRAMEWORK::logInit(const char *filename)
{
    logfile.open(filename, std::fstream::out);
}


void JFRAMEWORK::logData(const char *data, int variable)
{
    logfile << "["<< al_get_time() << "] - " << data << " : " << variable << std::endl << std::flush;
}


void JFRAMEWORK::logData(const char *data)
{
    logfile << "["<< al_get_time() << "] - " << data << std::endl << std::flush;
}
