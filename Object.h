#ifndef _JOBJECT_H_
#define _JOBJECT_H_
#include "stdafx.h"
#include "Node.h"
namespace JE2D
{
	class JOBJECT : public Node
	{
		public:
			JOBJECT();
			~JOBJECT();
			virtual void onInit(){};
			virtual void onUpdate(){};
			virtual void onRender(){};
			void init();
			void update();
			void render();
			int x, y;
			int dir;
	};
}
#endif //_JOBJECT_H_
