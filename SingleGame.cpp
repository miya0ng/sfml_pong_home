#include "stdafx.h"
#include "SingleGame.h"
#include "Bat.h"
#include "Ball.h"

SingleGame::SingleGame()
	: Scene(SceneIds::SingleGame)
{
}

void SingleGame::Init()
{
	bat = (Bat*)AddGameObject(new Bat("Bat"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));

	ball->SetBat(bat);
	Scene::Init();
}

void SingleGame::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void SingleGame::Update(float dt)
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

void SingleGame::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::SingleGame);
}
