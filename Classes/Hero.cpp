#include "Hero.h"
#include "FlashTool.h"

bool Hero::init() {
	Sprite::init();
	Size herobox = Size(44, 52);

	//���ƿ��
	setContentSize(herobox);
	setPhysicsBody(PhysicsBody::createBox(herobox));

	//����ê��
	setAnchorPoint(Point(0, 0));
	getPhysicsBody()->setRotationEnable(false);

	//�����ײ���
	getPhysicsBody()->setContactTestBitmask(1);

	
	schedule(CC_SCHEDULE_SELECTOR(Hero::jump), 0.5f);
	return true;
}

void Hero::setRoleName(std::string roleName)
{
	action = RepeatForever::create(FlashTool::readJsonSpriteSheet(roleName, 0.2f));
	runAction(action);
	_role = roleName;
}

void Hero::jump(float dt) {
	if (isChoose) {
		getPhysicsBody()->setVelocity(Vec2(0, 400));
	}
}

void Hero::chooseHero(bool choose)
{
	isChoose = choose;
	if (isChoose) {
		schedule(CC_SCHEDULE_SELECTOR(Hero::jump), 0.5f);
		UserDefault::getInstance()->setStringForKey("HeroRoleName", _role);
	}
	else {
		unscheduleUpdate();
	}
}

bool Hero::hitTestPoint(cocos2d::Vec2 point) {
	return this->getBoundingBox().containsPoint(point);
}
