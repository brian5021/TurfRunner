#ifndef __waterTurf_H__
#define __waterTurf_H__
#include "Turf.h"

using namespace cocos2d;

class waterTurf : public Turf {
public:
	static waterTurf* gameSpriteWithFile(const char* fileName, Point loc);
	static waterTurf* create(Point start);

};

#endif // __waterTurf_H__