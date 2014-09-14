#ifndef _MAP_H_
#define _MAP_H_
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
		int load(const char* filename);
		int save(const char* filename);
		int addTexture(const char* filename);
		int debugRender();
		void clearMap();
		ALLEGRO_BITMAP *renderedMap;
		std::vector<ALLEGRO_BITMAP*> tiles;
		std::vector<std::string> tileNames;
		std::vector<std::string> scriptName;
		bool showCollisions;
		int blocks[200][200];
		int collision[200][200];
		int scripts;
		int textures;
};
#endif
