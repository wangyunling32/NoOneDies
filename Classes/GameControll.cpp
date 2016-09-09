#include "GameControll.h"


void GameControll::resetFrame()
{
	currentIndexFrame = 0;
	nextIndexCount = rand()% 120 + 60;

}

void GameControll::addBlock()
{
	auto block = Block::create();
	_layer->addChild(block);
	//block->setPositionY(block->getContentSize().height / 2 + _postion);
	block->setPositionY(_postion);
}

bool GameControll::init(Layer * layer, float positionY)
{
	_layer = layer;
	_postion = positionY;
	visiableSize = Director::getInstance()->getVisibleSize();
	//添加边界框

	edge = EdgeBox::create();
	edge->setContentSize(visiableSize);
	edge->setPosition(visiableSize.width / 2, visiableSize.height / 2+ positionY);
	edge->setContentSize(visiableSize);
	layer->addChild(edge);

	//添加人物
	std::string roleName = UserDefault::getInstance()->getStringForKey("HeroRoleName");
	hero = Hero::create();
	hero->setPosition(30, positionY);
	hero->setRoleName(roleName);
	layer->addChild(hero);

	//添加地板
	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0,0));
	ground->setTextureRect(Rect(0, 0, visiableSize.width, 3));
	ground->setPosition(visiableSize.width / 2, 1.5+positionY);
	layer->addChild(ground);

	resetFrame();
	return true;
}

GameControll * GameControll::create(Layer * layout, float position)
{
	auto _ins = new GameControll();
	_ins->init(layout, position);
	_ins->autorelease();
	return _ins;
}

bool GameControll::hitTestPoint(cocos2d::Vec2 point) {
	bool contain = edge->getBoundingBox().containsPoint(point);
	return edge->getBoundingBox().containsPoint(point);
}

void GameControll::onUserTouch() {
	hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}


void GameControll::onUpdate(float dt)
{
	currentIndexFrame++;
	if (currentIndexFrame >= nextIndexCount) {
		resetFrame();
		addBlock();
	}
}
