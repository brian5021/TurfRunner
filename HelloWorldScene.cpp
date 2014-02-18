#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h" 


USING_NS_CC;

// Global Variables
Vehicle * v;
Water * w;
Dirt * d;
Road * r;
waterTurf * turfW1;
waterTurf * turfW2;
dirtTurf * turfD1;
dirtTurf * turfD2;
roadTurf * turfR1;
roadTurf * turfR2;
int randLane;
int randCar;
int laps = 0;
int delay = 0;
int delayT = 0;
LabelTTF label;
Sprite *hit1;
Sprite *hit2;
Sprite *hit3;
Sprite *hit4;
Sprite *hit5;
Sprite *hit6;
Sprite *hit7;
Sprite *hit8;
CCArray * hits;
CCArray * turfs;
CCArray * turfLocs;
HUD *h;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

	h = HUD::create();
    scene->addChild(h,1,5);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	// cpp with cocos2d-x
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("rightRound.mp3", true); 

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    // this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("trackF.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);


	this->addHitMarks();
	this->addTurf();

	// Add Vehicle[s]
	srand(time(NULL));
	randLane = (rand() % 2) + 1;

	randCar = (rand() % 3) + 1;
	if (randCar == 1) {
	w = Water::create(randLane);
	w->setPosition(w->loc);
	this->addChild(w);
	w->setRotation(270);
	v = w;
	}
	else if (randCar == 2) {
	d = Dirt::create(randLane);
	d->setPosition(d->loc);
	this->addChild(d);
	d->setRotation(270);
	v = d;
	}
	else {
	r = Road::create(randLane);
	r->setPosition(r->loc);
	this->addChild(r);
	r->setRotation(270);
	v = r;
	}

    
	this->scheduleUpdate();
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld:: addHitMarks() {
		// Hit Points
	Point A1 = ccp(85, 555);
	Point A2 = ccp(815, 555);
	Point A3 = ccp(815, 85);
	Point A4 = ccp(85,85);
	Point B1 = ccp(35, 605);
	Point B2 = ccp(865, 605);
	Point B3 = ccp(865, 35);
	Point B4 = ccp(35,35);

	
	// Hit markers array
	hits = CCArray::create();
	hits->retain();

	//Create Turn Sprites
	hit1 = Sprite::create("hit.png");
	hit1->setPosition(A1);
	hits->addObject(hit1);
	this->addChild(hit1);

	hit2 = Sprite::create("hit.png");
	hit2->setPosition(A2);
	hits->addObject(hit2);
	this->addChild(hit2);

	hit3 = Sprite::create("hit.png");
	hit3->setPosition(A3);
	hits->addObject(hit3);
	this->addChild(hit3);

	hit4 = Sprite::create("hit.png");
	hit4->setPosition(A4);
	hits->addObject(hit4);
	this->addChild(hit4);

	hit5 = Sprite::create("hit.png");
	hit5->setPosition(B1);
	hits->addObject(hit5);
	this->addChild(hit5);

	hit6 = Sprite::create("hit.png");
	hit6->setPosition(B2);
	hits->addObject(hit6);
	this->addChild(hit6);

	hit7 = Sprite::create("hit.png");
	hit7->setPosition(B3);
	hits->addObject(hit7);
	this->addChild(hit7);

	hit8 = Sprite::create("hit.png");
	hit8->setPosition(B4);
	hits->addObject(hit8);
	this->addChild(hit8);
}

void HelloWorld::addTurf() {
	// Turf Locs
	Point p1 = ccp(250, 85);
	Point p2 = ccp(225, 555);
	Point p3 = ccp(815, 400);
	Point p4 = ccp(700, 605);
	Point p5 = ccp(680, 35);
	Point p6 = ccp(35, 280);

	turfLoc * l1 = turfLoc::create(p1, 270);
	turfLoc * l2 = turfLoc::create(p2, 270);
	turfLoc * l3 = turfLoc::create(p3, 0);
	turfLoc * l4 = turfLoc::create(p4, 270);
	turfLoc * l5 = turfLoc::create(p5, 270);
	turfLoc * l6 = turfLoc::create(p6, 0);

	/*turfloc * x1 = l1;
	turfloc * x2 = &l2;
	turfloc * x3 = &l3;
	turfloc * x4 = &l4;
	turfloc * x5 = &l5;
	turfloc * x6 = &l6;*/

	//turfLocs = CCArray::create();
	//turfLocs->retain();
	//turfLocs->addObject(l1);
	//turfLocs->addObject(x2);
	//turfLocs->addObject(x3);
	//turfLocs->addObject(l4);
	//turfLocs->addObject(l5);
	//turfLocs->addObject(l6);

	// Hit markers array
	turfs = CCArray::create();
	turfs->retain();

	// Add Turf
	turfW1 = waterTurf::create(p1);
	turfW1->setPosition(turfW1->loc);
	this->addChild(turfW1);
	turfW1->setRotation(270);
	turfs->addObject(turfW1);

	turfW2 = waterTurf::create(p2);
	turfW2->setPosition(turfW2->loc);
	this->addChild(turfW2);
	turfW2->setRotation(270);
	turfs->addObject(turfW2);

	turfD1 = dirtTurf::create(p3);
	turfD1->setPosition(turfD1->loc);
	this->addChild(turfD1);
	turfD1->setRotation(0);
	turfs->addObject(turfD1);

	turfD2 = dirtTurf::create(p4);
	turfD2->setPosition(turfD2->loc);
	this->addChild(turfD2);
	turfD2->setRotation(270);
	turfs->addObject(turfD2);

	turfR1 = roadTurf::create(p5);
	turfR1->setPosition(turfR1->loc);
	this->addChild(turfR1);
	turfR1->setRotation(270);
	turfs->addObject(turfR1);

	turfR2 = roadTurf::create(p6);
	turfR2->setPosition(turfR2->loc);
	this->addChild(turfR2);
	turfR2->setRotation(0);
	turfs->addObject(turfR2);




}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

		if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
{
	this->unscheduleUpdate();
}
		if (keyCode == EventKeyboard::KeyCode::KEY_D)
{
	if (v->canSwitchR() && !v->effect) {
	v->switchLaneR();
	v->lane = 1;
	}
}
		if (keyCode == EventKeyboard::KeyCode::KEY_A)
{
	if(v->canSwitchL() && !v->effect) {
	v->switchLaneL();
	v->lane = 2;
	}
}
}
void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
			if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
{
	this->scheduleUpdate();
}
	
}


void HelloWorld::update(float dt) {
	
	v->lapCheck();
	if (v->finish()) {
    this->unscheduleUpdate();
	v->stopAllActions();
	CCLabelTTF * label ;
    label = CCLabelTTF::create("Game Over", "Arial.fnt", 32);
    label->setPosition(ccp(450, 550));
    this->addChild(label);
	}

	else if ((delay > 20) && v->canRotate(hits)) {
		v->setRotation(v->getRotation() + 90);
		h->didScore();
		delay = 0;	
	}
	else if (v->getTurf(turfs) != NULL) {
		v->turfMove(v->getTurf(turfs));
		h->didScore();
	}
	 else { 
		v->effect = false;
		v->speed = 3;
		v->move();
		delay++;
		h->didScore();
	 }
}