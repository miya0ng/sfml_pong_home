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

	//TitleText = new TextGo("fonts/DS-DIGIT.ttf");
	//titleText.SetFontId("fonts/DS-DIGIT.ttf");
	//
	//FONT_MGR.LoadFont("fonts/DS-DIGIT.ttf", "DS-DIGIT.ttf");
	//AddGameObject(titleText);
	
	titleText.setString("Ping-Pong");
	titleText.setCharacterSize(300);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(FRAMEWORK.GetWindowSize().x * 0.5f, FRAMEWORK.GetWindowSize().y *0.5f - 50.f);
}

void UiHud::Release()
{

}

void UiHud::Reset()
{
	titleText.setFont(FONT_MGR.Get(fontId));
}

void UiHud::Update(float dt)
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	if (isShowMsg) window.draw(titleText);
}
