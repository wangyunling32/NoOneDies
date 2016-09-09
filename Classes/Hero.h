#pragma once
#include <cocos2d.h>
#include <iostream>

USING_NS_CC;//����cocos2D�������ռ�

			/* ����һ���࣬�̳��Ծ�����*/
class Hero :public Sprite
{
private:
	bool isChoose;
	Action* action;
	std::string _role;
public:
	virtual bool init();
	virtual void setRoleName(std::string roleName);
	void jump(float dt);
	void chooseHero(bool choose);
	bool hitTestPoint(cocos2d::Vec2 point);
	CREATE_FUNC(Hero);
	/*static Hero* create(int role);
	static Hero* create();*/
};

