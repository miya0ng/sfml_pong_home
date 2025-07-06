#include "stdafx.h"
#include "UiHud.h"

UiHud::UiHud()
{
}

UiHud::~UiHud()
{

}

void UiHud::SetMsg(const std::string& msg)
{
}

void UiHud::Init()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	fontId = "fonts/DS-DIGIT.ttf";
	
	/*textScore.setString("score:");
	textScore.setCharacterSize(200);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(FRAMEWORK.GetWindowSize().x * 0.5f, FRAMEWORK.GetWindowSize().y *0.5f - 50.f);

	textGameOver.setString("GameOver");
	textGameOver.setCharacterSize(300);
	textGameOver.setFillColor(sf::Color::White);
	textGameOver.setPosition(FRAMEWORK.GetWindowSize().x * 0.5f, FRAMEWORK.GetWindowSize().y * 0.5f - 50.f);*/
}

void UiHud::Release()
{

}

void UiHud::Reset()
{
	textScore.setFont(FONT_MGR.Get(fontId));
}

void UiHud::Update(float dt)
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	if (isShowMsg)
	{
		window.draw(textScore);
		window.draw(textGameOver);
	}
}
