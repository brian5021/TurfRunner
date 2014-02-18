#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Vehicle.h"
#include "Water.h"
#include "Dirt.h"
#include "Road.h"
#include "Turf.h"
#include "waterTurf.h"
#include "dirtTurf.h"
#include "roadTurf.h"
#include "HUD.h"
#include "turfLoc.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	// Adds hit markers to track
	void addHitMarks();

	// Adds turf to track
	void addTurf();

	// lap count
	void lapCount();

	// Keyboard handler for pressing
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	// Keyboard handler for releasing
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	// Updates World
	void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
