#include "DegreeChooseScene.h"
#include "HelloWorldScene.h"
#include "ChooseHero.h"
bool DegressChoose::init()
{

	_visiableSize = Director::getInstance()->getVisibleSize();
	LayerColor::initWithColor(Color4B::WHITE);

	addLabel("Simple Mode",1);
	addLabel("Complex Mode",2);
	addLabel("Hell Mode",4);

	formatPostion();
	return true;
}

//添加标签
void DegressChoose::addLabel(const std::string label,int degree)
{
	auto l = Label::create();
	l->setString(label);
	l->setColor(Color3B::BLACK);
	l->setSystemFontSize(40);
	l->setAnchorPoint(Vec2(0.5, 0.5));
	addChild(l);
	labels.insert(0, l);
	addLabelEvent(l, degree);
}

//添加点击事件
void DegressChoose::addLabelEvent(Label* label, int degree)
{
	auto labelListener = EventListenerTouchOneByOne::create();
	labelListener->onTouchBegan = [label, degree](Touch * touch, Event* event) {
		if (label->getBoundingBox().containsPoint(touch->getLocation())) {
			UserDefault::getInstance()->setIntegerForKey("GameDegree", degree);
			Director::getInstance()->replaceScene(ChooseHero::createScene());
		};
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(labelListener, label);
}

void DegressChoose::formatPostion()
{
	int positionY = _visiableSize.height / labels.size();
	int positionX = _visiableSize.width / 2;
	int index = 0;
	for (auto it = labels.begin(); it != labels.end(); it++)
	{
		(*it)->setPosition(positionX, positionY*index + positionY / 2);
		index++;
	}
}

Scene * DegressChoose::createScene()
{
	//添加场景
	auto s = Scene::create();
	auto l = DegressChoose::create();
	s->addChild(l);
	return s;
}
