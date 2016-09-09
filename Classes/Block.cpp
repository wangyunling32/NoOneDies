#include "Block.h"

static int speed =4;

bool Block::init()
{
	Sprite::init();
	//设置锚点
	setAnchorPoint(Point(0, 0));
	
	//设置宽高大小
		    Size s = Size((rand()%20)+5, (rand()%30)+10);

	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));


	//设置黑色方块区域
	setTextureRect(Rect(0, 0, s.width, s.height));
	setColor(Color3B(0, 0, 0));

	//设置不是动态物体，不受重力影响
	getPhysicsBody()->setDynamic(false);

	//设置出现的位置是最右边
	Size visiableSize = Director::getInstance()->getVisibleSize();
	setPositionX(visiableSize.width);

	getPhysicsBody()->setContactTestBitmask(1);

	//启动一个定时器
	scheduleUpdate();
	return true;
}

void Block::update(float dt)
{
	this->setPositionX(getPositionX() -speed);
	if (getPositionX() < 0) {
		//小于0的时候
		unscheduleUpdate();
		removeFromParent();
	}
	
}
