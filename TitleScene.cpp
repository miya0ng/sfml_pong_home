#include "stdafx.h"
#include "TitleScene.h"
#include "SingleGame.h"
#include "MultiGame.h"
#include "TextGo.h"

TitleScene::TitleScene()
	:Scene(SceneIds::Title)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	font.loadFromFile("fonts/DS-DIGIT.ttf");
	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();

	titleText.setFont(font);
	//titleText
	titleText.setString("Ping_Pong!");
	titleText.setCharacterSize(120);
	sf::FloatRect titleBounds = titleText.getLocalBounds();
	titleText.setOrigin(titleBounds.width * 0.5f, titleBounds.height * 0.5f);
	titleText.setPosition(windowBounds.width*0.5f, 50.f);

	//1pText
	select1p.setFont(font);
	select1p.setString("1P");
	select1p.setCharacterSize(90);
	sf::FloatRect select1Bounds = select1p.getLocalBounds();
	select1p.setOrigin(select1Bounds.width * 0.5f, select1Bounds.height * 0.5f);
	select1p.setPosition(windowBounds.width * 0.5f-150, 850.f);

	//2pText
	select2p.setFont(font);
	select2p.setString("2P");
	select2p.setCharacterSize(90);
	sf::FloatRect select2Bounds = select2p.getLocalBounds();
	select2p.setOrigin(select2Bounds.width * 0.5f, select2Bounds.height * 0.5f);
	select2p.setPosition(windowBounds.width * 0.5f+150, 850.f);

	Scene::Init();
}

void TitleScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		SCENE_MGR.ChangeScene(SceneIds::SingleGame);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::X))
	{
		SCENE_MGR.ChangeScene(SceneIds::MultiGame);
	}
}

void TitleScene::Enter()
{
}

void TitleScene::SetGameOver()
{

}

void TitleScene::Draw(sf::RenderWindow& window)
{
	window.draw(titleText);
	window.draw(select1p);
	window.draw(select2p);
}
