#ifndef __turfLoc_H__
#define __turfLoc_H__
#include "cocos2d.h"

using namespace cocos2d;

class turfLoc : Object {
public:
	Point loc;
	int rot;

	turfLoc(Point loc, int rot);
	static turfLoc * create(Point loc, int rot);


};

#endif // __turfLoc_H__