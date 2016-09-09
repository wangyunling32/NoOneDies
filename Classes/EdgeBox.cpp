#include "EdgeBox.h"

bool EdgeBox::init() {
	Node::init();

	//����ê��
	Size visiableSize = Director::getInstance()->getVisibleSize();
	setAnchorPoint(cocos2d::Vec2(0.5,0.5));
	setContentSize(visiableSize);
	setPhysicsBody(PhysicsBody::createEdgeBox(visiableSize));
	//���ñ߽��
	return true;
}



