#ifndef __Water_H__
#define __Water_H__
#include "Vehicle.h"

using namespace cocos2d;

class Water : public Vehicle {
public:
	static Water* gameSpriteWithFile(const char* fileName, Point loc, int lane);
	static Water* create(int i);

};

#endif // __Water_H__