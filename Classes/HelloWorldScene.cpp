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

//�V�[���̏����� on "init" you need to initialize your instance
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

	//�o�b�N�O���E���h
	Sprite*sprb = Sprite::create("background.png");
	//�J�[�r�B�C���X�g�ǂݍ���
	Sprite*spr = Sprite::create("kirby2.png");
	//���h���f�B�C���X�g�ǂݍ���
	Sprite*spr2 = Sprite::create("wad2.png");
	//�z�����݃C���X�g�ǂݍ���
	Sprite*spr3 = Sprite::create("torune-do.png");
	//�f�f�f�C���X�g�ǂݍ���
	Sprite*spr4 = Sprite::create("ddd.png");
	//�X�^�[�C���X�g�ǂݍ���
	Sprite*spr5 = Sprite::create("ster.png");

	this->addChild(sprb);
	this->addChild(spr);
	this->addChild(spr2);
	this->addChild(spr3);
	this->addChild(spr4);
	this->addChild(spr5);

	//�o�b�N�O���E���h�����ʒu
	sprb->setPosition(Vec2(640.0f, 480.0f));
	sprb->setScale(3.0f, 4.0f);
	//�J�[�r�B�����ʒu
	spr->setPosition(Vec2(1300.0f, 400.0f));
	//���h���f�B�����ʒu
	spr2->setPosition(Vec2(-100.0f, 400.0f));
	//�z�����ݏ����ʒu
	spr3->setPosition(Vec2(795.0f, 405.0f));
	//�z�����݊p�x
	spr3->setRotation(270.0f);
	//�z�����݉�k��
	spr3->setScale(0.5f);
	//�f�f�f�����ʒu
	spr4->setPosition(Vec2(-150.0f, 400.0f));
	//�X�^�[�����ʒu
	spr5->setPosition(Vec2(600.0f, 400.0f));
	
	//�J�[�r�B�����ʒu���獶�ֈړ�
	MoveBy*moveBy1 = MoveBy::create(5.0f, Vec2(-300.0f, 0.0f));
	//�ʒu�ɂ����烏�h���f�B���ʒu�ɂ��܂őҋ@
	DelayTime*delayK1 = DelayTime::create(5.0f);
	//�J�[�r�B���̏��3��W�����v
	JumpBy*jumpBy1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 3);
	//�z�����݉悪�o������܂őҋ@
	DelayTime*delayK2 = DelayTime::create(1.0f);
	//�J�[�r�B�A�z�����݉�Ƌ��Ƀ��h���f�B�ɏ����ʒu���߂Â�
	MoveBy*moveK1 = MoveBy::create(5.0f, Vec2(-400.0f, 0.0f));
	//�f�f�f��|���܂őҋ@
	DelayTime*delayK3 = DelayTime::create(12.5f);
	//�f�f�f��|������W�����v
	JumpBy*jumpK1 = JumpBy::create(1.5f, Vec2(0.0f, 0.0f), 100.0f, 1);
	//�f�f�f��|��������]
	RotateBy*rotateK1 = RotateBy::create(1.5f, 360.0f);
	//��L2�̃A�N�V�����𓯎��Ɏ��s
	Spawn*spawnK1 = Spawn::create(jumpK1, rotateK1, nullptr);
	//��L��3��J��Ԃ�
	Repeat*repeatK1 = Repeat::create(spawnK1, 3);
	//�J�[�r�B���ԂɃA�N�V����
	Sequence*seq = Sequence::create(moveBy1,delayK1, jumpBy1,delayK2,moveK1,delayK3,repeatK1,nullptr);
	//���h���f�B�A�J�[�r�B���ʒu�ɂ��܂őҋ@
	DelayTime*delayW1 = DelayTime::create(5.0f);
	//���h���f�B�����ʒu����E�ֈړ�
	MoveBy*moveBy2 = MoveBy::create(5.0f, Vec2(300.0f, 0.0f));
	//���h���f�B�A�J�[�r�B�Ƌz�����݉悪�߂Â��Ă���܂őҋ@
	DelayTime*delayW2 = DelayTime::create(7.5f);
	//���h���f�B�z�����܂�ĉ�]����
	RotateBy*rotateW1 = RotateBy::create(3.0f, 1080.0f);
	//���h���f�B�z�����܂�ď��ł���
	FadeOut*fadeoutW1 = FadeOut::create(2.0f);
	//���h���f�B�z�����܂�Ĉړ�����
	MoveBy*moveW1 = MoveBy::create(3.0f, Vec2(400.0f, 0.0f));
	//��L3�̋z�����܂�A�N�V�����𓯎����s
	Spawn*spawnW1 = Spawn::create(rotateW1,fadeoutW1 , moveW1, nullptr);
	//���h���f�B���ԂɃA�N�V����
	Sequence*seq2 = Sequence::create(delayW1, moveBy2,delayW2,spawnW1, nullptr);
	//�z�����݂��ŏ��͏o���Ȃ�
	Hide*hide1 = Hide::create();
	//�z�����ݑҋ@
	DelayTime*delayT1 = DelayTime::create(12.5f);
	//�z�����ݏo��
	Show*show1 = Show::create();
	//�z�����݉�A�J�[�r�B�Ƌ��Ƀ��h���f�B�ɏ����ʒu���߂Â�
	MoveBy*moveT1 = MoveBy::create(5.0f,Vec2(-400.0f,0.0f));
	//���h���f�B���z�����܂��܂őҋ@
	DelayTime*delayT2 = DelayTime::create(4.0f);
	//�z�����݉���폜
	FadeOut*fadeoutT1 = FadeOut::create(1.0f);
	//�z�����ݏ��ԂɃA�N�V����
	Sequence*seq3 = Sequence::create(hide1,delayT1,show1,moveT1,delayT2,fadeoutT1,nullptr);
	//�f�f�f�o���ҋ@
	DelayTime*delayD1 = DelayTime::create(21.5f);
	//�f�f�f�����ʒu����E�ֈړ�
	MoveBy*moveD1 = MoveBy::create(5.0f, Vec2(300.0f, 0.0f));
	//�f�f�f�U����H�炤�܂őҋ@
	DelayTime*delayD2 = DelayTime::create(1.5f);
	//�f�f�f�U�����󂯂ĉ�]
	RotateBy*rotateD1 = RotateBy::create(2.0f, 1080.0f);
	//�f�f�f�U�����󂯂ĉ�ʊO�ɑޏ�
	MoveBy*moveD2 = MoveBy::create(2.0f, Vec2(-300.0f, 0.0f));
	//�f�f�f��L2�̃A�N�V�����𓯎����s
	Spawn*spawnD1 = Spawn::create(rotateD1, moveD2, nullptr);
	//�f�f�f���ԂɃA�N�V����
	Sequence*seq4 = Sequence::create(delayD1, moveD1,delayD2,spawnD1, nullptr);
	//�f�f�f�o��܂�26.5f
	//�X�^�[���ŏ��o�������Ȃ�
	Hide*hide2 = Hide::create();
	//�X�^�[�o���ҋ@����
	DelayTime*delayS1 = DelayTime::create(26.5f);
	//�X�^�[�o��
	Show*show2 = Show::create();
	//�X�^�[��]
	RotateBy*rotateS1 = RotateBy::create(3.0f, 1080.0f);
	//�X�^�[�ړ�
	MoveBy*moveS1 = MoveBy::create(3.0f, Vec2(-800.0f, 0.0f));
	//��L3�𓯎��ɍs��
	Spawn*spawnS1 = Spawn::create(show2, rotateS1, moveS1, nullptr);
	//�X�^�[�����ԂɃA�N�V����
	Sequence*seq5 = Sequence::create(hide2, delayS1, spawnS1, nullptr);
	

	spr->runAction(seq);
	spr2->runAction(seq2);
	spr3->runAction(seq3);
	spr4->runAction(seq4);
	spr5->runAction(seq5);

	//�T�E���h�Đ� true��t����ƃ��[�v�@
	audioID=experimental::AudioEngine::play2d("testse.mp3",true);

	//update���Ăяo�����悤�ɂ���
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
