#pragma once
#include <cocos2d.h>
#include <iostream>

#include "EdgeBox.h"
#include "Block.h"
#include "Hero.h"
USING_NS_CC;

class GameControll:public Ref
{
private:
	float _postion;
	Layer * _layer;
	Size visiableSize;
	int currentIndexFrame;//当前帧数
	int nextIndexCount;//下一个要触发这个事件的帧数
	 EdgeBox* edge;
	 Hero* hero;
private:
	void resetFrame();
	void addBlock();
public:
	//虚函数
	virtual bool init(Layer * layout,float positionY);
	static GameControll* create(Layer* layout,float position);
	 bool hitTestPoint(Vec2 vector);//是否与触摸点碰撞
	 void onUserTouch();
	 void onUpdate(float dt);
};

