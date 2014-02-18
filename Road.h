#ifndef __Road_H__
#define __Road_H__
#include "Vehicle.h"

using namespace cocos2d;

class Road : public Vehicle {
public:
	static Road* gameSpriteWithFile(const char* fileName, Point loc, int lane);
	static Road* create(int i);

};

#endif // __Road_H__