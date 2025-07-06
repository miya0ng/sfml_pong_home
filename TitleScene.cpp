#include "stdafx.h"
#include "TitleScene.h"
#include "SingleGame.h"
#include "MultiGame.h"
#include "TextGo.h"

TitleScene::TitleScene()
	:Scene(SceneIds::Title), triangle(25,3)
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
	titleText.setPosition(windowBounds.width*0.5f+20, 100.f);
	
	buttonY = windowBounds.height - 180.f;

	//1pText
	select1p.setFont(font);
	select1p.setString("1P");
	select1p.setCharacterSize(90);
	sf::FloatRect select1Bounds = select1p.getLocalBounds();
	select1p.setOrigin(select1Bounds.width * 0.5f, select1Bounds.height * 0.5f);
	select1p.setPosition(windowBounds.width * 0.5f-150, buttonY);
	
	//2pText
	select2p.setFont(font);
	select2p.setString("2P");
	select2p.setCharacterSize(90);
	sf::FloatRect select2Bounds = select2p.getLocalBounds();
	select2p.setOrigin(select2Bounds.width * 0.5f, select2Bounds.height * 0.5f);
	select2p.setPosition(windowBounds.width * 0.5f+150, buttonY);

	//choiceUI
	selectButtonX = select1p.getPosition().x;
	sf::FloatRect triangleBounds = select2p.getLocalBounds();
	triangle.setOrigin(triangleBounds.width * 0.5f, triangleBounds.height * 0.5f);
	triangle.setPosition(selectButtonX, buttonY-80.f);
	triangle.setRotation(180);

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
	window.draw(triangle);
}
