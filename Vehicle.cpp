#include "Vehicle.h"


Vehicle * Vehicle::gameSpriteWithFile(const char* fileName, Point loc, int lane) {
	Vehicle * sprite = new Vehicle();
	sprite->loc = loc;
	sprite->distance= 0;
	sprite->rotation = sprite->getRotation();
	sprite->speed = 0;
	sprite->lane = lane;
	sprite->effect = false;
	sprite->laps = 0;

	if (sprite && sprite->initWithFile(fileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

void Vehicle::move() {
	int targetX = this->getPositionX();
	int targetY = this->getPositionY();
	int stepX = sin(CC_DEGREES_TO_RADIANS(this->getRotation())) * this->speed;
	int stepY = cos(CC_DEGREES_TO_RADIANS(this->getRotation())) * this->speed;
	Point target = ccp(targetX+stepX, targetY+stepY);
	this->runAction(CCMoveTo::create(0, target));
}
void Vehicle::reverse() {
	int targetX = this->getPositionX();
	int targetY = this->getPositionY();
	int stepX = sin(CC_DEGREES_TO_RADIANS(this->getRotation())) * this->speed;
	int stepY = cos(CC_DEGREES_TO_RADIANS(this->getRotation())) * this->speed;
	Point target = ccp(targetX-stepX, targetY-stepY);
	this->runAction(CCMoveTo::create(0, target));
}

void Vehicle::switchLaneR() {
	int targetX = this->getPositionX();
	int targetY = this->getPositionY();
	int stepX = 0;
	int stepY = 0;
	int dir = sin(CC_DEGREES_TO_RADIANS(this->getRotation()));
	int dirY = cos(CC_DEGREES_TO_RADIANS(this->getRotation()));
	if (dir == 0 && dirY == 1)     stepX = 50;
	else if (dir == -1)   stepY = +50;
	else if (dir == 1)   stepY = -50;
	else                     stepX = -50;

	Point target = ccp(targetX+stepX, targetY+stepY);
	this->runAction(CCMoveTo::create(0, target));
}

void Vehicle::switchLaneL() {
	int targetX = this->getPositionX();
	int targetY = this->getPositionY();
	int stepX = 0;
	int stepY = 0;
	int dir = sin(CC_DEGREES_TO_RADIANS(this->getRotation()));
	int dirY = cos(CC_DEGREES_TO_RADIANS(this->getRotation()));
	if (dir == 0 && dirY == 1)     stepX = -50;
	else if (dir == -1)   stepY = -50;
	else if (dir == 1)   stepY = 50;
	else                     stepX = 50;

	Point target = ccp(targetX+stepX, targetY+stepY);
	this->runAction(CCMoveTo::create(0, target));
}

bool Vehicle::canSwitchR() {
	return this->lane == 2;
}

bool Vehicle::canSwitchL() {
	return this->lane == 1;
}

bool Vehicle::canRotate(Array * c) {
	CCObject * t = NULL;
	bool out = false;
	CCARRAY_FOREACH(c, t) {
		Sprite * target = dynamic_cast<Sprite*>(t);
		if (target->getBoundingBox().containsPoint(this->getPosition())) {
			out = true;
			break;
		}
	}
	return out;
	
}

Turf * Vehicle::getTurf(CCArray * c) {
	CCObject * t = NULL;
	bool out = false;
	Turf * tur;
	CCARRAY_FOREACH(c, t) {
		Turf * target = dynamic_cast<Turf*>(t);
		if (this->getBoundingBox().intersectsRect(target->boundingBox())) {
			tur = target;
			out = true;
			break;
		}
	}
	if(out) {
		return tur;
	}
	else {
		return NULL;
	}
}

void Vehicle::turfMove(Turf * t) {
	int vT = this->type;
	int tT = t->type;
	int strength = vT;
	int weak = (vT % 3) + 1;

	this->effect = false;
	if(tT == strength) {
		this->speed = 6;
	}
	else if(tT == weak) {
		this->speed = 1;
		this->effect = true;
	}
	this->move();
}

void Vehicle:: lapCheck() {
	if (this->getPositionX() >= 555 && this->getPositionX() <= 557 && this->getPositionY() < 200) {
		this->laps = this->laps + 1;
	}
}

bool Vehicle::finish() {
	return (this->laps >= 3);
}