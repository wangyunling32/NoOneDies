#include "GameOverScene.h"
#include "DegreeChooseScene.h"

bool GameOver::init()
{
	visiableSize = Director::getInstance()->getVisibleSize();
	LayerColor::initWithColor(Color4B::WHITE);

	auto l = Label::create();
	l->setString("Game Over");
	l->setColor(Color3B::BLACK);
	l->setSystemFontSize(40);
	addChild(l);

	auto l2 = Label::create();
	l2->setString("Game Restart");
	l2->setColor(Color3B::RED);
	l2->setSystemFontSize(32);
	addChild(l2);

	l->setPosition(visiableSize.width / 2, visiableSize.height / 5*3);
	l2->setPosition(visiableSize.width / 2, visiableSize.height / 5*2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* t, Event* e) {
		Director::getInstance()->replaceScene(DegressChoose::createScene());
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, l2);
	return true;
}

Scene * GameOver::createScene()
{
	auto s = Scene::create();
	auto l = GameOver::create();
	s->addChild(l);

	return s;
}
