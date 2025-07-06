#pragma once
#include "Scene.h"

class TextGo;
class Bat;
class Ball;

class SingleGame : public Scene
{
protected:

	Bat* bat = nullptr;
	Ball* ball = nullptr;

	sf::CircleShape triangle;

	sf::Text textScore;
	sf::Text textGameOver;
	sf::Text Exit;
	sf::Text Retry;
	sf::Font font;

	float buttonY;

	bool ballActive = false;
	bool isGameOver = false;

public:
	SingleGame();

	void Init() override;
	void Update(float dt) override;
	void Enter() override;
	void SetGameOver();
	void Draw(sf::RenderWindow& window) override;
};

