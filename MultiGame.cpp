#include "stdafx.h"
#include "MultiGame.h"
#include "Bat.h"
#include "Ball.h"

MultiGame::MultiGame() : Scene(SceneIds::MultiGame)
{
}

void MultiGame::Init()
{
	//fontIds.push_back("fonts/DS-DIGIT.ttf");
	//TextGo* go = new TextGo("fonts/DS-DIGIT.ttf");
	//go->SetString("Dev 1");
	//go->SetCharacterSize(30);
	//go->SetFillColor(sf::Color::White);
	//AddGameObject(go);

	bat = (Bat*)AddGameObject(new Bat("Bat"));
	bat2 = (Bat*)AddGameObject(new Bat("Bat2"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));

	ball->SetBat(bat);
	ball->SetBat2(bat2);
	Scene::Init();
}

void MultiGame::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void MultiGame::Update(float dt)
{
	Scene::Update(dt);
	if (!ballActive)
	{
		ball->SetPosition(bat->GetPosition());

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;

			sf::Vector2f dir(1.f, -1.f);
			Utils::Nomalize(dir);
			ball->Fire(dir, 500.f);
		}
	}
}

void MultiGame::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::MultiGame);
}
