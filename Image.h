#ifndef _IMAGE_H_
#define _IMAGE_H_
#include "stdafx.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
namespace JE2D
{
	class IMAGE
	{
		public:
			IMAGE();
			~IMAGE();
			ALLEGRO_BITMAP* b;
	};
}
#endif // _IMAGE_H_
