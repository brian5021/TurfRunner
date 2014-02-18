
#include <iostream>
#include "HUD.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "MainMenu.h"

using namespace cocos2d;
using namespace CocosDenshion;

bool HUD::init()
{
    if (!CCLayer::init()) {
        return false;        
    }
    score = 0;
    float padding = 10;
    

    scoreLabel = CCLabelTTF::create("0", CCString::createWithFormat("%s.ttf", "Arial")->getCString(),24);
    scoreLabel->setAnchorPoint(ccp(0,1));
    scoreLabel->setPosition(ccp(400, 250));
    this->addChild(scoreLabel,1);

    return true;
}

void HUD::didScore()
{
	score++;
	int time = score / 60;
	scoreLabel->setString(CCString::createWithFormat("Score: %d",time)->getCString());
}


void HUD::onExit()
{
	CCLayer::onExit();
}
