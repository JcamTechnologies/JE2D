#include "Framework.h"
using namespace JE2D;
int main(int argc, char** argv) {
	
	JFRAMEWORK *framework = new JFRAMEWORK();
	int error = framework->init();
	if(error)
	{
		framework->handle_error(error);
		return 1;
	}
	while(framework->exit == false)
	{
		error = framework->update();
		if(error)
		{
			framework->handle_error(error);
			return 1;
		}
		if(framework->redraw)
		{
			error = framework->render();
			if(error)
			{
				framework->handle_error(error);
				return 1;
			}
			framework->redraw = false;
		}
		
	}
	framework->~JFRAMEWORK();
	return 0;
}
