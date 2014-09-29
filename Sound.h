#ifndef _SOUND_H_
#define _SOUND_H_
#include "stdafx.h"
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
namespace JE2D
{
	class Sound
	{
		public:
			Sound();
			~Sound();
			bool add(std::string filename, std::string key);
			void playSound(std::string index, int loop);
			void stopSound(std::string index);
			void stopAll();
			bool exists(std::string index);
			void remove(std::string index);
			void removeAll();
		private:
			std::map<std::string, ALLEGRO_SAMPLE*> samples;
			std::map<std::string, ALLEGRO_SAMPLE_ID*> playing;
	};
}

#endif //_SOUND_H_
