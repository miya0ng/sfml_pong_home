#include "stdafx.h"
#include "SingleGame.h"
#include "Bat.h"
#include "Ball.h"

SingleGame::SingleGame()
	: Scene(SceneIds::SingleGame), triangle(23,3)
{
}

void SingleGame::Init()
{
	bat = (Bat*)AddGameObject(new Bat("Bat"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));

	ball->SetBat(bat);

	font.loadFromFile("fonts/DS-DIGIT.ttf");
	textScore.setFont(font);
	textScore.setString("Score: " + std::to_string(score));
	textScore.setCharacterSize(100);
	textScore.setFillColor(sf::Color::White);
	sf::FloatRect scoreBounds = textScore.getLocalBounds();
	textGameOver.setOrigin(scoreBounds.width * 0.5f, scoreBounds.height * 0.5f);
	textScore.setPosition(30.f, 0.f);

	//choiceUI
	sf::FloatRect triangleBounds = triangle.getLocalBounds();
	triangle.setFillColor(sf::Color::White);
	triangle.setOrigin(triangleBounds.width * 0.5f, triangleBounds.height * 0.5f);
	triangle.setPosition(490, buttonY - 80.f);
	triangle.setRotation(180);
	
	score = 0;
	
	Scene::Init();
}

void SingleGame::Enter()
{
	ballActive = false;
	isGameOver = false;
	Scene::Enter();
}

void SingleGame::Update(float dt)
{
	Scene::Update(dt);
	if (!isGameOver)
	{
		if (ball->GetPosition().y==FRAMEWORK.GetWindowBounds().top)
		{
		    SetGameOver();
		}

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
	else
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			triangle.setPosition(Retry.getPosition().x, buttonY - 80.f);
		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			triangle.setPosition(Exit.getPosition().x, buttonY - 80.f);
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			if (triangle.getPosition().x == Retry.getPosition().x)
			{
				SCENE_MGR.ChangeScene(SceneIds::SingleGame);
			}
			if (triangle.getPosition().x == Exit.getPosition().x)
			{
				SCENE_MGR.ChangeScene(SceneIds::Title);
			}
		}
	}
}

void SingleGame::SetGameOver()
{
	isGameOver = true;
	
	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();

	buttonY = windowBounds.height - 180.f;

	sf::FloatRect GameOverBounds = textGameOver.getLocalBounds();
	textGameOver.setFont(font);
	textGameOver.setString("GameOver");
	textGameOver.setCharacterSize(200);
	textGameOver.setOrigin(GameOverBounds.width * 0.5f, GameOverBounds.height * 0.5f);
	textGameOver.setFillColor(sf::Color::White);
	textGameOver.setPosition(windowBounds.width * 0.5f, windowBounds.height * 0.5f - 100.f);

	sf::FloatRect RetryBounds = Retry.getLocalBounds();
	Retry.setFont(font);
	Retry.setCharacterSize(70);
	Retry.setString("Retry");
	Retry.setFillColor(sf::Color::White);
	Retry.setOrigin(RetryBounds.width * 0.5f, RetryBounds.height * 0.5f);

	Retry.setPosition(windowBounds.width * 0.5f-150, buttonY-50.f);

	sf::FloatRect ExitBounds = Exit.getLocalBounds();
	Exit.setFont(font);
	Exit.setCharacterSize(70);
	Exit.setString("Exit");
	Exit.setFillColor(sf::Color::White);
	Exit.setOrigin(ExitBounds.width * 0.5f, ExitBounds.height * 0.5f);
	Exit.setPosition(windowBounds.width * 0.5f+150, buttonY-50.f);

	sf::FloatRect triangleBounds = triangle.getLocalBounds();
	triangle.setOrigin(triangleBounds.width * 0.5f, triangleBounds.height * 0.5f);
	triangle.setPosition(triangle.getPosition().x, buttonY - 80.f);
	triangle.setRotation(180);
}

void SingleGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(textScore);
	if (isGameOver)
	{
		window.draw(textGameOver);
		window.draw(triangle);
		window.draw(Retry);
		window.draw(Exit);
	}
}

void SingleGame::AddScore(int amount)
{
	score += amount;
	textScore.setString("Score: " + std::to_string(score));
	sf::FloatRect scoreBounds = textScore.getLocalBounds();
	textScore.setOrigin(scoreBounds.width * 0.5f, scoreBounds.height * 0.5f);
}
