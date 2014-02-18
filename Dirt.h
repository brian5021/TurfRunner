#ifndef __Dirt_H__
#define __Dirt_H__
#include "Vehicle.h"

using namespace cocos2d;

class Dirt : public Vehicle {
public:
	static Dirt* gameSpriteWithFile(const char* fileName, Point loc, int lane);
	static Dirt* create(int i);

};

#endif // __Dirt_H__