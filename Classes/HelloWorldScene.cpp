#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GameControll.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();//������������
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);//��ʾ���Կ�
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	// 2. modify background color
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	setAnchorPoint(Vec2(0, 0));
	degree = UserDefault::getInstance()->getIntegerForKey("GameDegree", 1);

	visiableSize = Director::getInstance()->getVisibleSize();
	int postionY = visiableSize.height / degree;
	for (int i = 0; i < degree; i++)
	{
		gcs.insert(0, GameControll::create(this, postionY*i));
	}
	scheduleUpdate();

	//�����ײ����
	//����䵽����ʲô����
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact&contact) {
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(GameOver::createScene());
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//��Ӵ����¼�
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = [this](Touch * t, Event * e) {
		for (auto it = gcs.begin(); it != gcs.end(); it++) {
			if ((*it)->hitTestPoint(t->getLocation())) {
				(*it)->onUserTouch();
				break;
			}
		}
		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, this);


	//���ʱ���ʱ��
	timeLable = Label::create();
	timeLable->setString("Time:" + 0);
	timeLable->setSystemFontSize(32);
	timeLable->setAnchorPoint(Vec2(0, 0));
	timeLable->setTextColor(Color4B::BLACK);
	timeLable->setPosition(
		visiableSize.width - timeLable->getContentSize().width,
		visiableSize.height - timeLable->getContentSize().height);
	addChild(timeLable);

	return true;
}

//update�Ĳ�����ɶ��˼
void HelloWorld::update(float dt)
{
	time += dt;
	for (auto it = gcs.begin(); it != gcs.end(); it++) {
		(*it)->onUpdate(dt);
	}

	//����ʱ��
	if (timeLable != nullptr){
		sprintf(buf, "Time:%0.1f", time);
		timeLable->setString(buf);
		timeLable->setPosition(
			visiableSize.width - timeLable->getContentSize().width,
			visiableSize.height - timeLable->getContentSize().height);
	}
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
//���ʱ���ʱ��
void HelloWorld::updateTimerLabel(int time)
{

}
