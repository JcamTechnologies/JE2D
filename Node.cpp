#include "Node.h"

using namespace JE2D;

Node::Node()
{
	child = NULL;
	parent = NULL;
}

Node::~Node()
{
	if(parent)
	{
		if(child)
		{
			child->parent = parent;
			parent->child = child;
		}else
		{
			parent->child = NULL;
		}
	}else
	{
		if(child)
		{
			child->parent = NULL;
		}
	}
}

void Node::attach(Node* node)
{
	parent = node->getLastChild();
	node->getLastChild()->child = this;
}

void Node::detach()
{
	parent->child = NULL;
	parent = NULL;
}

void Node::addSibling(Node* node)
{
}

Node* Node::getChild()
{
	if(child)
	{
		return child;
	}
	return NULL;
}

Node* Node::getParent()
{
	if(parent)
	{
		return parent;
	}
	return NULL;
}

Node* Node::getNext()
{
	if(nextNode)
	{
		return nextNode;
	}
	return NULL;
}

Node* Node::getPrev()
{
	if(prevNode)
	{
		return prevNode;
	}
	return NULL;
}

Node* Node::getLastChild()
{
	if(child)
	{
		return child->getLastChild();
	}
	else
	{
		return this;
	}
}

Node* Node::getFirstParent()
{
	if(parent)
	{
		return parent->getFirstParent();
	}else
	{
		return this;
	}
}


