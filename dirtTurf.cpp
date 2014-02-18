#include "dirtTurf.h"

dirtTurf* dirtTurf::gameSpriteWithFile(const char* fileName, Point loc) {
	dirtTurf * sprite = new dirtTurf();
	sprite->loc = loc;
	sprite->type = 3;
	int targetX = loc.x;
	int targetY = loc.y;
	int stepX = 0;
	int stepY = 0;
	int dir = sin(CC_DEGREES_TO_RADIANS(sprite->getRotation()));
	int dirY = cos(CC_DEGREES_TO_RADIANS(sprite->getRotation()));
	if (dir == 0 && dirY == 1)     stepY = 50;
	else if (dir == -1)   stepX = -50;
	else if (dir == 1)   stepX = 50;
	else                     stepY = -50;

	Point target = ccp(targetX+stepX, targetY+stepY);
	sprite->endPoint = target;

	if (sprite && sprite->initWithFile(fileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

dirtTurf * dirtTurf::create(Point start) {

	return dirtTurf::gameSpriteWithFile("turfD.png", start);

}