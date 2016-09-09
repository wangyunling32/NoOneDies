#pragma once
#include "cocos2d.h"

USING_NS_CC;
//游戏结束界面
class GameOver:public LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(GameOver);
	static Scene* createScene();

private:
	Size visiableSize;
};

