
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "GameButton.h"

using namespace cocos2d;
using namespace CocosDenshion;

//USING_NS_CC;

CCScene* MainMenu::scene()
{
    CCScene *sc = CCScene::create();
    MainMenu *m = MainMenu::create();
    sc->addChild(m, 0);
    return sc;
}

bool MainMenu::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
    
    s = CCDirector::sharedDirector()->getWinSize();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("rightRound.mp3");
    CCString* file = CCString::create("moles.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(file->getCString());
    
    file = CCString::create("title.png");
    CCSprite *bg = CCSprite::create(file->getCString());
    bg->setPosition(ccp(s.width/2,s.height/2));
    this->addChild(bg,-1);


    // MenuItemSprite *playButton = MenuItemSprite::create(GameButton::buttonWithText("PLAY!",false), NULL, this, SEL_CallFunc(MainMenu::playGame));
    // CCMenu *menu = CCMenu::create(playButton,NULL);
    // menu->setPosition(ccp(s.width/2,s.height/2 - s.height/4.0f));
    //menu->setScale(Utils::getScale());
    // this->addChild(menu,2);

	return true;
}

void MainMenu::playGame()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::createScene());
}

void MainMenu::mainMenu()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
