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
#include "AudioEngine.h"

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

    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //if (label == nullptr)
    //{
    //    problemLoading("'fonts/Marker Felt.ttf'");
    //}
    //else
    //{
    //    // position the label on the center of the screen
    //    label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                            origin.y + visibleSize.height - label->getContentSize().height));

    //    // add the label as a child to this layer
    //    this->addChild(label, 1);
    //}

	//バックグラウンド
	Sprite*sprb = Sprite::create("background.png");
	//カービィイラスト読み込み
	Sprite*spr = Sprite::create("kirby2.png");
	//ワドルディイラスト読み込み
	Sprite*spr2 = Sprite::create("wad2.png");
	//吸い込みイラスト読み込み
	Sprite*spr3 = Sprite::create("torune-do.png");
	//デデデイラスト読み込み
	Sprite*spr4 = Sprite::create("ddd.png");
	//スターイラスト読み込み
	Sprite*spr5 = Sprite::create("ster.png");

	this->addChild(sprb);
	this->addChild(spr);
	this->addChild(spr2);
	this->addChild(spr3);
	this->addChild(spr4);
	this->addChild(spr5);

	//バックグラウンド初期位置
	sprb->setPosition(Vec2(640.0f, 480.0f));
	sprb->setScale(3.0f, 4.0f);
	//カービィ初期位置
	spr->setPosition(Vec2(1300.0f, 400.0f));
	//ワドルディ初期位置
	spr2->setPosition(Vec2(-100.0f, 400.0f));
	//吸い込み初期位置
	spr3->setPosition(Vec2(795.0f, 405.0f));
	//吸い込み角度
	spr3->setRotation(270.0f);
	//吸い込み画縮小
	spr3->setScale(0.5f);
	//デデデ初期位置
	spr4->setPosition(Vec2(-150.0f, 400.0f));
	//スター初期位置
	spr5->setPosition(Vec2(600.0f, 400.0f));
	
	//カービィ初期位置から左へ移動
	MoveBy*moveBy1 = MoveBy::create(5.0f, Vec2(-300.0f, 0.0f));
	//位置についたらワドルディが位置につくまで待機
	DelayTime*delayK1 = DelayTime::create(5.0f);
	//カービィその場で3回ジャンプ
	JumpBy*jumpBy1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 3);
	//吸い込み画が出現するまで待機
	DelayTime*delayK2 = DelayTime::create(1.0f);
	//カービィ、吸い込み画と共にワドルディに初期位置より近づく
	MoveBy*moveK1 = MoveBy::create(5.0f, Vec2(-400.0f, 0.0f));
	//デデデを倒すまで待機
	DelayTime*delayK3 = DelayTime::create(12.5f);
	//デデデを倒した後ジャンプ
	JumpBy*jumpK1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 1);
	//デデデを倒した後一回転
	RotateBy*rotateK1 = RotateBy::create(1.5f, 360.0f);
	//上記2つのアクションを同時に実行
	Spawn*spawnK1 = Spawn::create(jumpK1, rotateK1, nullptr);
	//上記を3回繰り返し
	Repeat*repeatK1 = Repeat::create(spawnK1, 3);
	//カービィ順番にアクション
	Sequence*seq = Sequence::create(moveBy1,delayK1, jumpBy1,delayK2,moveK1,delayK3,repeatK1,nullptr);
	//ワドルディ、カービィが位置につくまで待機
	DelayTime*delayW1 = DelayTime::create(5.0f);
	//ワドルディ初期位置から右へ移動
	MoveBy*moveBy2 = MoveBy::create(5.0f, Vec2(300.0f, 0.0f));
	//ワドルディ、カービィと吸い込み画が近づいてくるまで待機
	DelayTime*delayW2 = DelayTime::create(7.5f);
	//ワドルディ吸い込まれて回転する
	RotateBy*rotateW1 = RotateBy::create(3.0f, 1080.0f);
	//ワドルディ吸い込まれて消滅する
	FadeOut*fadeoutW1 = FadeOut::create(2.0f);
	//ワドルディ吸い込まれて移動する
	MoveBy*moveW1 = MoveBy::create(3.0f, Vec2(400.0f, 0.0f));
	//上記3つの吸い込まれアクションを同時実行
	Spawn*spawnW1 = Spawn::create(rotateW1,fadeoutW1 , moveW1, nullptr);
	//ワドルディ順番にアクション
	Sequence*seq2 = Sequence::create(delayW1, moveBy2,delayW2,spawnW1, nullptr);
	//吸い込みを最初は出さない
	Hide*hide1 = Hide::create();
	//吸い込み待機
	DelayTime*delayT1 = DelayTime::create(12.5f);
	//吸い込み出現
	Show*show1 = Show::create();
	//吸い込み画、カービィと共にワドルディに初期位置より近づく
	MoveBy*moveT1 = MoveBy::create(5.0f,Vec2(-400.0f,0.0f));
	//ワドルディが吸い込まれるまで待機
	DelayTime*delayT2 = DelayTime::create(4.0f);
	//吸い込み画を削除
	FadeOut*fadeoutT1 = FadeOut::create(1.0f);
	//吸い込み順番にアクション
	Sequence*seq3 = Sequence::create(hide1,delayT1,show1,moveT1,delayT2,fadeoutT1,nullptr);
	//デデデ出現待機
	DelayTime*delayD1 = DelayTime::create(21.5f);
	//デデデ初期位置から右へ移動
	MoveBy*moveD1 = MoveBy::create(5.0f, Vec2(300.0f, 0.0f));
	//デデデ攻撃を食らうまで待機
	DelayTime*delayD2 = DelayTime::create(1.5f);
	//デデデ攻撃を受けて回転
	RotateBy*rotateD1 = RotateBy::create(2.0f, 1080.0f);
	//デデデ攻撃を受けて画面外に退場
	MoveBy*moveD2 = MoveBy::create(2.0f, Vec2(-300.0f, 0.0f));
	//デデデ上記2つのアクションを同時実行
	Spawn*spawnD1 = Spawn::create(rotateD1, moveD2, nullptr);
	//デデデ順番にアクション
	Sequence*seq4 = Sequence::create(delayD1, moveD1,delayD2,spawnD1, nullptr);
	//デデデ登場まで26.5f
	//スターを最初出現させない
	Hide*hide2 = Hide::create();
	//スター出現待機時間
	DelayTime*delayS1 = DelayTime::create(26.5f);
	//スター出現
	Show*show2 = Show::create();
	//スター回転
	RotateBy*rotateS1 = RotateBy::create(3.0f, 1080.0f);
	//スター移動
	MoveBy*moveS1 = MoveBy::create(3.0f, Vec2(-800.0f, 0.0f));
	//上記3つを同時に行う
	Spawn*spawnS1 = Spawn::create(show2, rotateS1, moveS1, nullptr);
	//スターを順番にアクション
	Sequence*seq5 = Sequence::create(hide2, delayS1, spawnS1, nullptr);
	

	spr->runAction(seq);
	spr2->runAction(seq2);
	spr3->runAction(seq3);
	spr4->runAction(seq4);
	spr5->runAction(seq5);

	//サウンド再生 trueを付けるとループ　
	audioID=experimental::AudioEngine::play2d("testse.mp3",true);

	//updateが呼び出されるようにする
	this->scheduleUpdate();

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
