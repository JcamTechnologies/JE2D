#ifndef _NODE_H_
#define _NODE_H_
#include "stdafx.h"

namespace JE2D
{
	class Node
	{
		public:
			Node();
			~Node();
			Node* getParent();
			Node* getChild();
			Node* getNext();
			Node* getPrev();
			Node* getLastChild();
			Node* getFirstParent();
			void attach(Node* node);
			void detach();
			void addSibling(Node* node);
		private:
			Node* parent;
			Node* child;
			Node* nextNode;
			Node* prevNode;

	};
}
#endif //_NODE_H_
