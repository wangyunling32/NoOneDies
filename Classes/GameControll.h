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
	int currentIndexFrame;//��ǰ֡��
	int nextIndexCount;//��һ��Ҫ��������¼���֡��
	 EdgeBox* edge;
	 Hero* hero;
private:
	void resetFrame();
	void addBlock();
public:
	//�麯��
	virtual bool init(Layer * layout,float positionY);
	static GameControll* create(Layer* layout,float position);
	 bool hitTestPoint(Vec2 vector);//�Ƿ��봥������ײ
	 void onUserTouch();
	 void onUpdate(float dt);
};

