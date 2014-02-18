#include "Dirt.h"

Dirt* Dirt::gameSpriteWithFile(const char* fileName, Point loc, int lane) {
	Dirt * sprite = new Dirt();
	sprite->loc = loc;
	sprite->distance= 0;
	sprite->rotation = 0;
	sprite->speed = 0;
	sprite->lane = lane;
	sprite->type = 3;
	sprite->laps = 0;

	if (sprite && sprite->initWithFile(fileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

Dirt * Dirt::create(int i) {
	Point start;
	if (i == 1) {
		start = ccp(455, 85);
	}
	else if (i == 2) {
		start = ccp(435, 35);
	}

	return Dirt::gameSpriteWithFile("carD.png", start, i);

}