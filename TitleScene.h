#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
protected:
	sf::Text titleText;
	sf::Text select1p;
	sf::Text select2p;
	sf::Text spaceText;
	sf::Font font;
	sf::CircleShape triangle;

	float buttonY;
	float selectButtonX;
public:

	TitleScene();
	~TitleScene();

	void Init() override;
	void Update(float dt) override;
	void Enter() override;
	void SetGameOver();
	void Draw(sf::RenderWindow& window) override;
};