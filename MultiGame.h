#pragma once
#include "Scene.h"

class Bat;
class Ball;
class TextGo;

class MultiGame : public Scene
{
protected:
	TextGo* testGo;

	Bat* bat = nullptr;
	Bat* bat2 = nullptr;
	Ball* ball = nullptr;

	bool ballActive = false;

public:
	MultiGame();
	~MultiGame() override = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;
	void SetGameOver();
};

