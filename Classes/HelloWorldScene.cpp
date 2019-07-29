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
	//チリーイラスト読み込み
	Sprite*spr6 = Sprite::create("tiri.png");
	//アイスイラスト読み込み
	Sprite*spr7 = Sprite::create("ice.png");
	//アイスカービィイラスト読み込み
	Sprite*spr8 = Sprite::create("icekirby.png");

	this->addChild(sprb);
	this->addChild(spr);
	this->addChild(spr2);
	this->addChild(spr3);
	this->addChild(spr4);
	this->addChild(spr5);
	this->addChild(spr6);
	this->addChild(spr7);
	this->addChild(spr8);

	//バックグラウンド初期位置
	sprb->setPosition(Vec2(640.0f, 480.0f));
	sprb->setScale(3.0f, 2.0f);
	//カービィ初期位置
	spr->setPosition(Vec2(1300.0f, 250.0f));
	//ワドルディ初期位置
	spr2->setPosition(Vec2(-100.0f, 250.0f));
	//吸い込み初期位置
	spr3->setPosition(Vec2(795.0f, 255.0f));
	//吸い込み角度
	spr3->setRotation(270.0f);
	//吸い込み画縮小
	spr3->setScale(0.5f);
	//デデデ初期位置
	spr4->setPosition(Vec2(-150.0f, 250.0f));
	//スター初期位置
	spr5->setPosition(Vec2(600.0f, 250.0f));
	//チリー初期位置
	spr6->setPosition(Vec2(-100.0f, 250.0f));
	//アイス初期位置
	spr7->setPosition(Vec2(600.0f, 250.0f));
	//アイスカービィ初期位置
	spr8->setPosition(Vec2(590.0f, 250.0f));
	
	//カービィ初期位置から左へ移動
	MoveBy*moveBy1 = MoveBy::create(3.0f, Vec2(-300.0f, 0.0f));
	//位置についたらワドルディが位置につくまで待機
	DelayTime*delayK1 = DelayTime::create(3.0f);
	//カービィその場で3回ジャンプ
	JumpBy*jumpBy1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 3);
	//吸い込み画が出現するまで待機
	DelayTime*delayK2 = DelayTime::create(1.0f);
	//カービィ、吸い込み画と共にワドルディに初期位置より近づく
	MoveBy*moveK1 = MoveBy::create(3.0f, Vec2(-400.0f, 0.0f));
	//デデデを倒すまで待機
	DelayTime*delayK3 = DelayTime::create(12.5f);
	//デデデを倒した後ジャンプ
	JumpBy*jumpK1 = JumpBy::create(1.5f, Vec2(180.0f, 0.0f), 100.0f, 1);
	//デデデを倒した後一回転
	RotateBy*rotateK1 = RotateBy::create(1.5f, 360.0f);
	//上記2つのアクションを同時に実行
	Spawn*spawnK1 = Spawn::create(jumpK1, rotateK1, nullptr);
	//上記アクション実行時1秒間の間を入れる
	DelayTime*delayK4 = DelayTime::create(0.3f);
	//上記2つを順番に行う
	Sequence*seqK2 = Sequence::create(spawnK1, delayK4, nullptr);
	//上記を3回繰り返し
	Repeat*repeatK1 = Repeat::create(seqK2, 3);
	//チリーが出現するまで待機
	DelayTime*delayK5 = DelayTime::create(3.6f);
	//吸い込み画と共にチリーに詰める
	MoveBy*moveK2 = MoveBy::create(3.0f, Vec2(-550.0f, 0.0f));
    //デデデ登場まで待機
	DelayTime*delayK6 = DelayTime::create(2.0f);
	//アイスカービィに進化するためフェードアウト
	FadeOut*fadeoutK1 = FadeOut::create(1.0f);
	//カービィ順番にアクション
	Sequence*seq = Sequence::create(moveBy1,delayK1, jumpBy1,delayK2,moveK1,delayK3,repeatK1,delayK5,moveK2,delayK6,fadeoutK1,nullptr);
	//ワドルディ、カービィが位置につくまで待機
	DelayTime*delayW1 = DelayTime::create(3.0f);
	//ワドルディ初期位置から右へ移動
	MoveBy*moveBy2 = MoveBy::create(3.0f, Vec2(300.0f, 0.0f));
	//ワドルディ、カービィと吸い込み画が近づいてくるまで待機
	DelayTime*delayW2 = DelayTime::create(5.5f);
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
	DelayTime*delayT1 = DelayTime::create(8.5f);
	//吸い込み出現
	Show*show1 = Show::create();
	//吸い込み画、カービィと共にワドルディに初期位置より近づく
	MoveBy*moveT1 = MoveBy::create(3.0f,Vec2(-400.0f,0.0f));
	//ワドルディが吸い込まれるまで待機
	DelayTime*delayT2 = DelayTime::create(4.0f);
	//吸い込み画を削除
	FadeOut*fadeoutT1 = FadeOut::create(1.0f);
	//吸い込み画を後ろへ戻す
	MoveBy*moveT2 = MoveBy::create(1.0f, Vec2(550.0f, 0.0f));
	//吸い込み画再出現待機
	DelayTime*delayT3 = DelayTime::create(15.5f);
	//吸い込み画出現
	FadeIn*fadeinT1 = FadeIn::create(1.0f);
	//カービィと共にチリーへ詰める
	MoveBy*moveT3 = MoveBy::create(3.0f, Vec2(-550.0f, 0.0f));
	//上記2つを同時実行
	Spawn*spawnT1 = Spawn::create(fadeinT1, moveT3, nullptr);
	//チリー吸い込まれるまで待機
	DelayTime*delayT4 = DelayTime::create(3.0f);
	//吸い込み画再削除
	FadeOut*fadeoutT2 = FadeOut::create(1.0f);
	//吸い込み順番にアクション
	Sequence*seq3 = Sequence::create(hide1,delayT1,show1,moveT1,delayT2,fadeoutT1,moveT2,delayT3,spawnT1,delayT4,fadeoutT2,nullptr);
	//デデデ出現待機
	DelayTime*delayD1 = DelayTime::create(16.5f);
	//デデデ初期位置から右へ移動
	MoveBy*moveD1 = MoveBy::create(3.0f, Vec2(300.0f, 0.0f));
	//デデデ攻撃を食らうまで待機
	DelayTime*delayD2 = DelayTime::create(1.5f);
	//デデデ攻撃を受けて回転
	RotateBy*rotateD1 = RotateBy::create(2.0f, 1080.0f);
	//デデデ攻撃を受けて画面外に退場
	MoveBy*moveD2 = MoveBy::create(2.0f, Vec2(-300.0f, 0.0f));
	//デデデ上記2つのアクションを同時実行
	Spawn*spawnD1 = Spawn::create(rotateD1, moveD2, nullptr);
	//デデデ再出場待機
	DelayTime*delayD3 = DelayTime::create(16.0f);
	//デデデ再出陣
	MoveBy*moveD3 = MoveBy::create(3.0f, Vec2(300.0f, 0.0f));
	//アイス攻撃がくるまで待機
	DelayTime*delayD4 = DelayTime::create(0.65f);
	//デデデアイス攻撃を受けて回転
	RotateBy*rotateD2 = RotateBy::create(2.0f, 1080.0f);
	//デデデ攻撃を受けて画面外に退場
	MoveBy*moveD4 = MoveBy::create(2.0f, Vec2(-300.0f, 0.0f));
	//デデデ上記2つのアクションを同時実行
	Spawn*spawnD2 = Spawn::create(rotateD2, moveD4, nullptr);
	//デデデ順番にアクション
	Sequence*seq4 = Sequence::create(delayD1, moveD1,delayD2,spawnD1, delayD3, moveD3,delayD4,spawnD2, nullptr);
	//スターを最初出現させない
	Hide*hide2 = Hide::create();
	//スター出現待機時間
	DelayTime*delayS1 = DelayTime::create(19.5f);
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
	//チリー出番まで待機
	DelayTime*delayTI1 = DelayTime::create(30.0f);
	//チリー初期位置から右へ移動
	MoveBy*moveTI1 = MoveBy::create(3.0f, Vec2(300.0f, 0.0f));
	//カービィと吸い込み画が詰めてくるまで待機
	DelayTime*delayTI2 = DelayTime::create(3.0f);
	//チリー吸い込まれて回転する
	RotateBy*rotateTI1 = RotateBy::create(3.0f, 1080.0f);
	//チリーィ吸い込まれて消滅する
	FadeOut*fadeoutTI1 = FadeOut::create(2.0f);
	//チリー吸い込まれて移動する
	MoveBy*moveTI2 = MoveBy::create(3.0f, Vec2(400.0f, 0.0f));
	//上記3つの吸い込まれアクションを同時実行
	Spawn*spawnTI1 = Spawn::create(rotateTI1, fadeoutTI1, moveTI1, nullptr);
	//チリー順番にアクション
	Sequence*seq6 = Sequence::create(delayTI1, moveTI1,delayTI2,spawnTI1, nullptr);
	//アイスを最初出現させない
	Hide*hideA1 = Hide::create();
	//アイス出現待機時間
	DelayTime*delayA1 = DelayTime::create(41.0f);
	//アイス出現
	Show*showA1 = Show::create();
	//アイス回転
	RotateBy*rotateA1 = RotateBy::create(3.0f, 1080.0f);
	//アイス移動
	MoveBy*moveA1 = MoveBy::create(3.0f, Vec2(-800.0f, 0.0f));
	//上記3つを同時に行う
	Spawn*spawnA1 = Spawn::create(showA1, rotateA1, moveA1, nullptr);
	//アイスを順番にアクション
	Sequence*seq7 = Sequence::create(hideA1, delayA1, spawnA1, nullptr);
	//39
	//アイスカービィ最初に出現させない
	FadeOut*fadeoutICK1 = FadeOut::create(0.1f);
	//アイスカービィ待機
	DelayTime*delayICK1 = DelayTime::create(39.0f);
	//アイスカービィ出現
	FadeIn*fadeinICK1 = FadeIn::create(1.0f);
	//アイスカービィジャンプ
	JumpBy*jumpICK1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 3);
	//デデデを倒すまで待機
	DelayTime*delayICK2 = DelayTime::create(5.0f);
	//アイスカービィ順番にアクション
	Sequence*seq8 = Sequence::create(fadeoutICK1, delayICK1, fadeinICK1,delayICK2, jumpICK1, nullptr);


	//デデデ再登場前41．0ｆ　登場後44．0f；
	

	spr->runAction(seq);
	spr2->runAction(seq2);
	spr3->runAction(seq3);
	spr4->runAction(seq4);
	spr5->runAction(seq5);
	spr6->runAction(seq6);
	spr7->runAction(seq7);
	spr8->runAction(seq8);

	//サウンド再生 trueを付けるとループ　
	audioID=experimental::AudioEngine::play2d("BGM30.mp3",true);

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
