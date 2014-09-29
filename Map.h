#ifndef _MAP_H_
#define _MAP_H_
#define MAPSIZE 200
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
class JMAP
{



	std::vector<std::string> splita(const std::string &s, char delim, std::vector<std::string> &elems) {
	    std::stringstream ss(s);
	    std::string item;
	    while (std::getline(ss, item, delim)) {
	        elems.push_back(item);
	    }
	    return elems;
	}
	std::vector<std::string> split(const std::string &s, char delim) {
	    std::vector<std::string> elems;
	    splita(s, delim, elems);
	    return elems;
	}

	public:
		JMAP();
		~JMAP();
		void init();
		void init(int size);
		int load(const char* filename);
		int save(const char* filename);
		int addTexture(const char* filename);
		int addScript(const char* filename);
		int delScript(int key);
		int debugRender();
		void clearMap();
		ALLEGRO_BITMAP *renderedMap;
		ALLEGRO_BITMAP *topRenderedMap;
		std::vector<ALLEGRO_BITMAP*> tiles;
		std::vector<std::string> tileNames;
		std::vector<std::string> scriptName;
		bool showCollisions;
		int blocks[MAPSIZE][MAPSIZE];
		int topBlocks[MAPSIZE][MAPSIZE];
		int collision[MAPSIZE][MAPSIZE];
		int scripts;
		int textures;
		bool containsString(std::vector<std::string> vec, std::string s);
	private:
};
#endif
