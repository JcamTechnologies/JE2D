#include "Sound.h"
using namespace JE2D;
Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::playSound(std::string index, int loop)
{
	if(exists(index))
	{
		if(samples[index])
		{
			ALLEGRO_SAMPLE_ID* id;
			if(loop==1)
			{
				al_play_sample(samples[index], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);
			}else
			{
				al_play_sample(samples[index], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, id);
			}
			playing[index] = id;
		}
	}
	else
	{
		std::cout << "Failed to get sample:" << index << std::endl;
	}
}

bool Sound::exists(std::string index)
{
	if(samples[index])
	{
		return true;
	}
	return false;
}

void Sound::remove(std::string index)
{
	if(exists(index))
	{
		if(playing[index])
		{
			al_stop_sample(playing[index]);
			playing.erase(index);
		}
		al_destroy_sample(samples[index]);
		samples.erase(index);
	}
}

bool Sound::add(std::string filename, std::string key)
{
	ALLEGRO_SAMPLE* tmp = al_load_sample(filename.c_str());
	if(exists(key))
	{
		std::cout << "Exists\n";
		return false;
	}
	if(!tmp)
	{
		std::cout << "Invalid file:" << filename << std::endl;
		return false;
	}
	samples[key] = tmp;
	return true;
}

void Sound::stopSound(std::string index)
{
	if(playing[index])
	{
		al_stop_sample(playing[index]);
		playing.erase(index);
	}
}
void Sound::stopAll()
{
	al_stop_samples();
	playing.clear();
}
