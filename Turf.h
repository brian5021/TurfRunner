#ifndef __TURF_H__
#define __TURF_H__
#include "cocos2d.h"

using namespace cocos2d;

class Turf : public Sprite {
public:
	Point loc;
	Point endPoint;
	int type;

	static Turf* gameSpriteWithFile(const char* fileName, Point loc);

};

#endif // __Turf_H__

