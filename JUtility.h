#ifndef _JUTILITY_H_
#define _JUTILITY_H_
#include "stdafx.h"
#include "include/lua.hpp"
#include "luawrapper.hpp"
namespace JE2D
{
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	    std::stringstream ss(s);
	    std::string item;
	    while (std::getline(ss, item, delim)) {
	        elems.push_back(item);
	    }
	    return elems;
	}


	std::vector<std::string> split(const std::string &s, char delim) {
	    std::vector<std::string> elems;
	    split(s, delim, elems);
	    return elems;
	}
	
}
#endif //_JUTILITY_H_
