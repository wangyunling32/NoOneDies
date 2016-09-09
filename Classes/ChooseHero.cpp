#include "ChooseHero.h"
#include "EdgeBox.h"
#include "HelloWorldScene.h"

bool ChooseHero::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	Size visiableSize = Director::getInstance()->getVisibleSize();

	int postionY = (visiableSize.height - 150) / 4;
	addHero(postionY * 0 + 150,0);
	addHero(postionY * 1 + 150, 1);
	addHero(postionY * 2 + 150, 2);
	addHero(postionY * 3 + 150, 3);
	addNextLevel();
	return true;
}

Scene * ChooseHero::createScene()
{
	auto scene = Scene::createWithPhysics();;
	auto l = ChooseHero::create();
	scene->getPhysicsWorld()->setGravity(Vec2(0, -2000));
	scene->addChild(l);
	return scene;
}

void ChooseHero::addNextLevel() {
	//添加按钮
	Size size = Director::getInstance()->getVisibleSize();
	auto l = Label::create();
	l->setString("Game Start");
	l->setSystemFontSize(32);
	l->setColor(Color3B::BLACK);
	l->setPosition(size.width / 2, l->getContentSize().height+10);
	addChild(l);

	//添加点击监听事件
	auto llistener = EventListenerTouchOneByOne::create();
	llistener->onTouchBegan = [l](Touch *touch, Event * e) {
		if (l->getBoundingBox().containsPoint(touch->getLocation()))
		{
			Director::getInstance()->replaceScene(HelloWorld::createScene());
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(llistener, l);
}


void ChooseHero::addHero(float positionY,int num)
{
	Size visiableSize = Director::getInstance()->getVisibleSize();

	auto edge = EdgeBox::create();
	edge->setContentSize(visiableSize);
	edge->setPosition(visiableSize.width / 2, visiableSize.height / 2 + positionY);
	edge->setContentSize(visiableSize);
	addChild(edge);

	//添加人物
	auto hero = Hero::create();
	hero->setPosition(30, positionY);
	hero->setRoleName(getRoleName(num * 2));
	addChild(hero);

	auto hero2 = Hero::create();
	hero2->setPosition(visiableSize.width - hero2->getContentSize().width - 30, positionY);
	hero2->setRoleName(getRoleName(num * 2+1));
	addChild(hero2);

	heros.insert(0, hero);
	heros.insert(0, hero2);

	//添加地板
	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, visiableSize.width, 3));
	ground->setPosition(visiableSize.width / 2, 1.5 + positionY);
	addChild(ground);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch * t, Event * e) {
		for (auto it = heros.begin(); it != heros.end(); it++) {
			(*it)->chooseHero(false);
			if ((*it)->hitTestPoint(t->getLocation())) {
				(*it)->chooseHero(true);
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

std::string ChooseHero::getRoleName(int role)
{
	switch (role)
	{
	case 0:
		return std::string("Hero.json");
	case 1:
		return std::string("Hero_blue.json");
	case 2:
		return std::string("Hero_green.json");
	case 3:
		return std::string("Hero_orange.json");
	case 4:
		return std::string("Hero_pink.json");
	case 5:
		return std::string("Hero_purper.json");
	case 6:
		return std::string("Hero_yellow.json");
	case 7:
		return std::string("Hero_auto.json");
	default:
		return std::string("Hero.json");
	}
}

