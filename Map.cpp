#include "Map.h"

JMAP::JMAP()
{
}

JMAP::~JMAP()
{
	al_destroy_bitmap(renderedMap);
	for(std::vector<ALLEGRO_BITMAP*>::iterator it = tiles.begin(); it < tiles.end(); it++)
	{
		al_destroy_bitmap(*it);
	}
	tileNames.clear();
	scriptName.clear();
	tiles.clear();
}
void JMAP::init()
{
	renderedMap = al_create_bitmap(4000, 4000);
	textures=0;
	scripts = 0;
	for(int x = 0; x < 200; x++)
	{
		for(int y = 0; y < 200; y++)
		{
			blocks[x][y]=0;
		}
	}
	showCollisions = false;
}
int JMAP::load(const char* filename)
{
	int version;
	std::ifstream file(filename);
	if(!file)
	{
		return 402;
	}
	std::string line;
	std::getline(file, line);
	if(line != "JMAP 2.0"  &&  line != "JMAP 2.0.1" && line != "JMAP 2.0.2" && line != "JMAP 2.0.3")
	{
		return 409;
	}
	if(line == "JMAP 2.0")
	{
		version = 1;
	}else if(line == "JMAP 2.0.1")
	{
		version = 2;
	}
	else if(line == "JMAP 2.0.2")
	{
		version = 3;
	}
	else if(line == "JMAP 2.0.3")
	{
		version = 4;
	}
	std::getline(file, line);
	int textures = atoi(line.c_str());
	for(int i = 0; i < textures; i++)
	{

		std::getline(file, line);
		if(version < 3)
		{
			ALLEGRO_BITMAP* tbmp = al_load_bitmap(line.c_str());
			std::string fname = line;
			std::string tmps = "Resources/Tiles/";
			const size_t last_slash_idx = fname.find_last_of("\\/");

			if (std::string::npos != last_slash_idx)
			{
			    fname.erase(0, last_slash_idx + 1);
			}
			tmps.append(fname);
			al_save_bitmap(tmps.c_str(), tbmp);
			al_destroy_bitmap(tbmp);
			tileNames.push_back(tmps.c_str());
		}else
		{
			tileNames.push_back(line);
		}
	}
	std::getline(file, line);
	if(version >= 4)
	{
		int scripts = atoi(line.c_str());
		for(int i = 0; i < scripts; i++)
		{
			std::getline(file, line);
			scriptName.push_back(line);
		}
		std::getline(file, line);
	}

	if(line != "MAP DATA:")
	{
		return 409;
	}
	for(int y = 0; y < 200; y++)
	{
		std::getline(file, line);
		std::vector<std::string> tmp = split(line, ',');
		for(int x = 0; x < 200; x++)
		{
			blocks[x][y]=atoi(tmp[x].c_str());
		}
	}
	if(version >= 2)
	{
		std::getline(file, line);
		if(line != "COLLISION DATA:")
		{
			return 409;
		}
		for(int y = 0; y < 200; y++)
		{
			std::getline(file, line);
			std::vector<std::string> tmp = split(line, ',');
			for(int x = 0; x < 200; x++)
			{
				collision[x][y]=atoi(tmp[x].c_str());
			}
		}
	}
	file.close();
	for(std::vector<std::string>::iterator it = tileNames.begin(); it < tileNames.end(); it++)
	{
		ALLEGRO_BITMAP* tbmp = NULL;

		const char* fname = it->c_str();
		tbmp = al_load_bitmap(fname);
		if(!tbmp)
		{
			return 402;
		}
		tiles.push_back(al_load_bitmap(fname));
		al_destroy_bitmap(tbmp);
	}
	debugRender();
	return 0;
}

int JMAP::save(const char* filename)
{
	std::ofstream file;
	std::stringstream str;
	str << filename;
	std::string temp = str.str();
	file.open(filename);
	file << "JMAP 2.0.3" << std::endl;
	file<<tileNames.size()<<std::endl;
	for(std::vector<std::string>::iterator it = tileNames.begin(); it < tileNames.end(); it++)
	{
		file<<*it<<std::endl;
	}
	file<<scripts<<std::endl;
	for(std::vector<std::string>::iterator it = scriptName.begin(); it < scriptName.end(); it++)
	{
		file<<*it<<std::endl;
	}
	file << "MAP DATA:" << std::endl;
	for(int y = 0; y < 200; y++)
	{
		for(int x = 0; x < 200; x++)
		{
			file << blocks[x][y];
			if(x < 199)
			{
				file << ',';
			}
		}
		file<<std::endl;
	}
	file << "COLLISION DATA:" << std::endl;
	for(int y = 0; y < 200; y++)
	{
		for(int x = 0;  x < 200; x++)
		{
			file<<collision[x][y];
			if(x < 199)
			{
				file << ',';
			}
		}
		file<<std::endl;
	}
	file.close();
	return 0;
}
int JMAP::addTexture(const char* filename)
{
	ALLEGRO_BITMAP *tbmp;
	tbmp = al_load_bitmap(filename);
	if(!tbmp)
	{
		return 402;
	}
	tileNames.push_back(filename);
	tiles.push_back(al_load_bitmap(filename));
	al_destroy_bitmap(tbmp);
	textures++;
	return 0;
}
void JMAP::clearMap()
{
	al_destroy_bitmap(renderedMap);
	renderedMap = al_create_bitmap(4000, 4000);
	textures=0;
	for(int x = 0; x < 200; x++)
	{
		for(int y = 0; y < 200; y++)
		{
			blocks[x][y]=0;
			collision[x][y]=0;
		}
	}
	for(std::vector<ALLEGRO_BITMAP*>::iterator it = tiles.begin(); it < tiles.end(); it++)
	{
		al_destroy_bitmap(*it);
	}
	tileNames.clear();
	scriptName.clear();
	tiles.clear();
}
int JMAP::debugRender()
{
	al_set_target_bitmap(renderedMap);
	for(int x = 0; x < 200; x++)
	{
		for(int y = 0; y < 200; y++)
		{
			if(tiles.at(blocks[x][y]))
				al_draw_bitmap(tiles.at(blocks[x][y]), x*20, y*20, 0);
			if(showCollisions)
			{
				if(collision[x][y] == 1)
				{
					al_draw_rectangle(x*20, y*20, (x*20)+20, (y*20)+20, al_map_rgb(0, 255, 0), 3);
				}
				if(collision[x][y] > 1)
				{
					al_draw_rectangle(x*20, y*20, (x*20)+20, (y*20)+20, al_map_rgb(255, 255, 255), 3);
				}
			}
		}
	}
	return 0;
}
