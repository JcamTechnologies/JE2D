#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "Node.h"
#include "stdafx.h"
#include <map>
namespace JE2D
{
	class Entity : public Node
	{
		public:
			Entity();
			~Entity();
			virtual void onInit(){};
			virtual void onUpdate(){};
			virtual void onRender(){};
			void Init();
			void Update();
			void Render();
			int x,y;
			int dir;
			int id;
			std::map<std::string, std::string> meta;
		private:
			
	};
}
#endif//_ENTITY_H_
