#pragma once
#include <cocos2d.h>
#include <iostream>

USING_NS_CC;

class DegressChoose :public LayerColor
{
public:
	virtual bool init();
	void addLabel(const std::string label,int degree);
	void addLabelEvent(Label* label, int degree);
	virtual void formatPostion();
	static Scene* createScene();
	CREATE_FUNC(DegressChoose);

private:
	Size _visiableSize;
	cocos2d::Vector<cocos2d::Label*> labels;
};
