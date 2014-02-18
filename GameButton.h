
#ifndef GameButton_h
#define GameButton_h

#include "cocos2d.h"

class GameButton : public cocos2d::CCSprite
{
    
    
    public:
    bool initWithText(const char * text, bool isBig);
    static GameButton* buttonWithText(const char * text, bool isBig);
};

#endif
