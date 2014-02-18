#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include "cocos2d.h"
#include "Turf.h"

using namespace cocos2d;

class Vehicle : public Sprite {
public:
	Point loc;
	int distance;
	float rotation;
	int type;
	int speed;
	int lane;
	bool effect;
	int laps;

	static Vehicle* gameSpriteWithFile(const char* fileName, Point loc, int lane);
	void move();
	void reverse();
	void switchLaneR();
	void switchLaneL();
	bool canSwitchR();
	bool canSwitchL();
	bool canRotate(CCArray * c);
	Turf * getTurf(CCArray * c);
	void turfMove(Turf * t);
	void lapCheck();
	bool finish();
	
};

#endif // __Vehicle_H__