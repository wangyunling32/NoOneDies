#pragma once
#include <cocos2d.h>
#include <iostream>

USING_NS_CC;

class Block :public Sprite {
public:
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(Block);

};