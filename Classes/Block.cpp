#include "Block.h"

static int speed =4;

bool Block::init()
{
	Sprite::init();
	//����ê��
	setAnchorPoint(Point(0, 0));
	
	//���ÿ�ߴ�С
		    Size s = Size((rand()%20)+5, (rand()%30)+10);

	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));


	//���ú�ɫ��������
	setTextureRect(Rect(0, 0, s.width, s.height));
	setColor(Color3B(0, 0, 0));

	//���ò��Ƕ�̬���壬��������Ӱ��
	getPhysicsBody()->setDynamic(false);

	//���ó��ֵ�λ�������ұ�
	Size visiableSize = Director::getInstance()->getVisibleSize();
	setPositionX(visiableSize.width);

	getPhysicsBody()->setContactTestBitmask(1);

	//����һ����ʱ��
	scheduleUpdate();
	return true;
}

void Block::update(float dt)
{
	this->setPositionX(getPositionX() -speed);
	if (getPositionX() < 0) {
		//С��0��ʱ��
		unscheduleUpdate();
		removeFromParent();
	}
	
}
