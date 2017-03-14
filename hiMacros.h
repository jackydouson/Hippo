/********************************************************************************
Name: hiMacros.h
Desc: Global Defines
Auth: Jacky Dawson
Mail: 497436362@qq.com
Date: 20170303
Last: 20170303
Copyright (c) 2017 Hippo Inc.
********************************************************************************/

#ifndef __HI_MACROS_H__
#define __HI_MACROS_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <thread>
#include <mutex>

namespace hippo 
{

// singleton
#define SINGLETON(c) \
static c* getInstance() \
{ \
	static c* ret = nullptr; \
	if (!ret) ret = new c(); \
	return ret; \
}

// member variable
#define MEMBER_VARIABLE(t, n, f) \
{ \
public: \
	set##f(t p){ n = p; } \
	get##f(){ return n; } \
private: \
	t n; \
} \

// check
#define CHECK_RETURN_VOID(p) {if(!(p))return;}
#define CHECK_RETURN_NULL(p) {if(!(p))return nullptr;}
#define CHECK_RETURN_TRUE(p) {if(!(p))return true;}
#define CHECK_RETURN_FALSE(p) {if(!(p))return false;}
#define DELETE_AND_NULL(p) {if((p)){delete (p); (p) = nullptr;}}

// typedefs
typedef std::vector<int> VecInt;
typedef std::vector<float> VecFloat;
typedef std::vector<std::string> VecStr;

};

#endif