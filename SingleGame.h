#pragma once
#include "Scene.h"

class TextGo;
class Bat;
class Ball;

class SingleGame : public Scene
{
protected:
	TextGo* testGo;
	Bat* bat = nullptr;
	Ball* ball = nullptr;

	bool ballActive = false;

public:
	SingleGame();

	void Init() override;
	void Update(float dt) override;
	void Enter() override;
	void SetGameOver();
};

