/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//シーンの初期化 on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	Sprite*spr = Sprite::create("HelloWorld.png");
	this->addChild(spr);
	spr->setPosition(Vec2(1100.0f, 600.0f));

	MoveBy*moveBy = MoveBy::create(5.0f, Vec2(-900.0f, 0.0f));
	MoveBy*moveBy2 = MoveBy::create(5.0f, Vec2(0.0f, -400.0f));
	MoveBy*moveBy3 = MoveBy::create(5.0f, Vec2(900.0f, 0.0f));
	MoveBy*moveBy4 = MoveBy::create(5.0f, Vec2(0.0f, 400.0f));
	Sequence*seq = Sequence::create(moveBy, moveBy2, moveBy3, moveBy4, nullptr);

	spr->runAction(seq);
	/*FadeOut*fadeout = FadeOut::create(5.0f);
	FadeIn*fadein = FadeIn::create(5.0f);
	Spawn*spn = Spawn::create(moveBy, fadeout, nullptr);
	Spawn*spn2 = Spawn::create(fadein, moveBy2, nullptr);
	Sequence*seq = Sequence::create(spn, spn2,nullptr);
	Repeat*rep = Repeat::create(seq, 5);*/

	//DelayTime*delay = DelayTime::create(1.0f);
	//JumpBy*jumpBy = JumpBy::create(0.5f, Vec2(100.0f, 100.0f),100.0f,1);
	////Repeat*rep= Repeat::create(jumpBy,5);

	//spr->runAction(rep);

	////アクション1の作成
	//MoveTo*moveTo = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));
	////アクション2の作成
	//JumpTo*jumpTo = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);

	//TintTo*tintTo = TintTo::create(1.0f, Color3B(255, 255, 0));
	////同時発動アクションの作成
	//Spawn*spawn = Spawn::create(moveTo,tintTo,nullptr);
	////連続アクションの生成
	//Sequence*seq = Sequence::create(moveTo, spawn, nullptr);
	////連続アクションの実行
	//spr->runAction(seq);

	//updateが呼び出されるようにする
	//this->scheduleUpdate();

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{

}
