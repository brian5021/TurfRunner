#include "Water.h"

Water* Water::gameSpriteWithFile(const char* fileName, Point loc, int lane) {
	Water * sprite = new Water();
	sprite->loc = loc;
	sprite->distance= 0;
	sprite->rotation = 0;
	sprite->speed = 0;
	sprite->lane = lane;
	sprite->type = 1;
	sprite->laps = 0;

	if (sprite && sprite->initWithFile(fileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

Water * Water::create(int i) {
	Point start;
	if (i == 1) {
		start = ccp(455, 85);
	}
	else if (i == 2) {
		start = ccp(435, 35);
	}

	return Water::gameSpriteWithFile("carW.png", start, i);

}