#include "turfLoc.h"

turfLoc::turfLoc(Point loc, int rot) {
	this->loc = loc;
	this->rot = rot;
}

turfLoc* turfLoc::create(Point loc, int rot) {
	turfLoc * object = new turfLoc(loc, rot);

	return object;
}