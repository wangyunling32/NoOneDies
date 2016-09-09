#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameControll.h"
class HelloWorld : public cocos2d::LayerColor
{
private:
	cocos2d::Vector<GameControll*> gcs;
	Label* timeLable;
	Size visiableSize;
	float time;
	char buf[10];
public:
	int degree;//сно╥дя╤х
	static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float dt);
    void menuCloseCallback(cocos2d::Ref* pSender);
	virtual void updateTimerLabel(int time);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
