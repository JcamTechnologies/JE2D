#include "Script.h"
#include "LuaClassDef.h"
using namespace JE2D;

Script::Script()
{
}
Script::Script(lua_State* L)
{
	this->L = L;
}

Script::~Script()
{
	lua_close(L);
}

void Script::init()
{
	std::cout << "Creating luastate" << std::endl;
	
	L = luaL_newstate();
	
	std::cout << "Opening libs" << std::endl;
	
	luaL_openlibs(L);
	
	std::cout<<"allocating tables" << std::endl;
	static luaL_Reg Player_metatable[] =
	{
		{"getAttack", Player_getAttack},
		{"setAttack", Player_setAttack},
		{"getDefence", Player_getDefence},
		{"setDefence", Player_setDefence},
		{"getHealth", Player_getHealth},
		{"setHealth", Player_setHealth},
		{"getSpeed", Player_getSpeed},
		{"setSpeed", Player_setSpeed},
		{"setPos", Player_setPos},
		{"getX", Player_getX},
		{"getY", Player_getY},
		{"getTileX", Player_getTileX},
		{"getTileY", Player_getTileY},
		{"render", Player_render},
		{"move", Player_move},
		{NULL, NULL}
	};
	
	static luaL_Reg Map_table[] =
	{
		{NULL, NULL}
	};
	
	static luaL_Reg Map_metatable[] =
	{
		{"save", Map_save},
		{"load", Map_load},
		{"getTrigger", Map_getTrigger},
		{"editCollision", Map_editCollision},
		{NULL, NULL}
	};
	static luaL_Reg Sound_metatable[] =
	{
		{"add",Sound_add},
		{"remove", Sound_remove},
		{"play", Sound_play},
		{"stop", Sound_stop},
		{"stopAll", Sound_stopAll},
		{NULL, NULL}
	};
	static luaL_Reg Scene_metatable[] =
	{
		{"addSound", Scene_addSound},
		{"loadMap", Scene_loadMap},
		{"getPlayer", Scene_getPlayer},
		{"getMap", Scene_getMap},
		{"getSound", Scene_getSound},
		{"setPlayerAnim", Scene_addPlayerAnim},
		{"loadFont", Scene_loadFont},
		{"addText", Scene_setText},
		{"addTimedText", Scene_setTimedText},
		{"deleteText", Scene_deleteText},
		{"editText", Scene_editText},
		{"editTextTime", Scene_editTextTime},
		{"update", Scene_update},
		{"render", Scene_render},
		{NULL, NULL}
	};
	
	static luaL_Reg Image_metatable[] =
	{
		{"load", Image_load},
		{"draw", Image_draw},
		{NULL, NULL}
	};
	
	lua_pushcfunction(L, System_run);
	lua_setglobal(L, "System_run");
	std::cout<<"Registering Sound" << std::endl;
	luaW_register<Sound>(L, "Sound", Map_table, Sound_metatable, Sound_new);
	std::cout<<"Registering Image" << std::endl;
	luaW_register<IMAGE>(L, "Image", Map_table, Image_metatable, Image_new);
	std::cout<<"Registering Map" << std::endl;
	luaW_register<JMAP>(L, "Map", Map_table, Map_metatable, Map_new);
	std::cout<<"Registering Player" << std::endl;
	luaW_register<JPLAYER>(L, "Player", Map_table, Player_metatable, Player_new);
	std::cout<<"Registering Scene" << std::endl;
	luaW_register<Scene>(L, "Scene", Map_table, Scene_metatable, Scene_new);
	
}

lua_State* Script::run(std::string filename)
{
	lua_State* tmp = L;
	this->filename = filename;
	if(luaL_loadfile(tmp, filename.c_str()))
	{
		std::cout << "Failed to load file:"<<filename<<std::endl;
		return NULL;
	}
	if(lua_pcall(tmp, 0, 0, 0))
	{
		std::cout << "Failed to run script:" << filename<< std::endl;
		return NULL;
	}
	L = tmp;
	return L;
}
