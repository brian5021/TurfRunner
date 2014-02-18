#ifndef __roadTurf_H__
#define __roadTurf_H__
#include "Turf.h"

using namespace cocos2d;

class roadTurf : public Turf {
public:
	static roadTurf* gameSpriteWithFile(const char* fileName, Point loc);
	static roadTurf* create(Point start);

};

#endif // __roadTurf_H__