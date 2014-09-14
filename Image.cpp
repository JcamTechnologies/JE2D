#include "Image.h"
using namespace JE2D;

IMAGE::IMAGE()
{
	
}

IMAGE::~IMAGE()
{
	al_destroy_bitmap(b);
}
