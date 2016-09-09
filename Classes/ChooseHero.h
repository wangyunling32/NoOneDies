#pragma once
#include <cocos2d.h>
#include <iostream>
#include "Hero.h"

class ChooseHero:public LayerColor
{
public:
	virtual bool init();
	static Scene* createScene();
	void addNextLevel();
	void addHero(float positionY,int num);
	virtual std::string getRoleName(int role);
	CREATE_FUNC(ChooseHero);
private:
	cocos2d::Vector<Hero*> heros;
};
