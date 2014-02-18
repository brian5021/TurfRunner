#ifndef __dirtTurf_H__
#define __dirtTurf_H__
#include "Turf.h"

using namespace cocos2d;

class dirtTurf : public Turf {
public:
	static dirtTurf* gameSpriteWithFile(const char* fileName, Point loc);
	static dirtTurf* create(Point start);

};

#endif // __dirtTurf_H__