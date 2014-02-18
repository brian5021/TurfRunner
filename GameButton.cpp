
#include "GameButton.h"

//#include <string>

using namespace cocos2d;

bool GameButton::initWithText(const char * text, bool isBig)
{
    if (!CCSprite::init()) {
        return false;
    }
    CCString* btnFrame = (isBig) ? CCString::create("button_big.png") : CCString::create("button_small.png");
    int fSize = 18;
    this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(btnFrame->getCString()));
    CCLabelTTF *label = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf","Arial")->getCString(), fSize + isBig * fSize);
    label->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
    this->addChild(label,1);
    
    CCLabelTTF *labelShadow = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf","Arial")->getCString(), fSize + isBig * fSize);
    labelShadow->setPosition(ccp(this->getContentSize().width/2 - (2 + isBig * 2),this->getContentSize().height/2));
    labelShadow->setColor(ccBLACK);
    labelShadow->setOpacity(150);
    this->addChild(labelShadow,0);
    
    //this->setScale(Utils::getScale());

    return true;
}

GameButton* GameButton::buttonWithText(const char * text, bool isBig)
{
    GameButton *btn = new GameButton();
    btn->initWithText(text, isBig);
    btn->autorelease();
    return btn;
}




