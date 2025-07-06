#include "stdafx.h"
#include "Ball.h"
#include "Bat.h"
#include "MultiGame.h"
#include "SingleGame.h"

Ball::Ball(const std::string& name)
	: GameObject(name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Ball::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Ball::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Ball::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(shape, preset);
	}
}

void Ball::Init()
{
	shape.setRadius(10.f);
	shape.setFillColor(sf::Color::White);
	SetOrigin(Origins::BC);
}

void Ball::Release()
{
}

void Ball::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	SetPosition({ bounds.width * 0.5f, bounds.height - 20.f });

	float radius = shape.getRadius();
	minX = bounds.left + radius;
	maxX = (bounds.left + bounds.width) - radius;

	minY = bounds.top - 200.f;
	maxY = bounds.top + bounds.height + 200.f;

	direction = { 0.f, 0.f };
	speed = 0.f;
}

void Ball::Update(float dt)
{
	sf::Vector2f pos = GetPosition() + direction * speed * dt;

	if (pos.x < minX)
	{
		pos.x = minX;
		direction.x *= -1.f;
	}
	else if (pos.x > maxX)
	{
		pos.x = maxX;
		direction.x *= -1.f;
	}

	if (pos.y < minY)
	{
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::MultiGame)
		{
			MultiGame* scene = (MultiGame*)SCENE_MGR.GetCurrentScene();
			if (scene != nullptr)
			{
				scene->SetGameOver();
			}
		}
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::SingleGame)
		{
			SingleGame* singlescene = (SingleGame*)SCENE_MGR.GetCurrentScene();
			if (singlescene != nullptr)
			{
				singlescene->AddScore(10); // 10점 추가
			}
		}
	}
	else if (pos.y > maxY)
	{
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::MultiGame)
		{
			MultiGame* scene = (MultiGame*)SCENE_MGR.GetCurrentScene();
			if (scene)
			{
				scene->SetGameOver();
			}
		}
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::SingleGame)
		{
			SingleGame* singlescene = (SingleGame*)SCENE_MGR.GetCurrentScene();
			if (singlescene != nullptr)
			{
				singlescene->SetGameOver();
			}
		}
	}


	//collision with bat

	if (bat != nullptr)
	{
		if (bat->GetName() == "Bat")
		{
			const sf::FloatRect& batBounds = bat->GetGlobalBounds();
			if (shape.getGlobalBounds().intersects(batBounds))
			{
				pos.y = batBounds.top;
				direction.y *= -1.f;
				std::cout << "아야야" << std::endl;
			}
		}
	}

	if (bat2 != nullptr)
	{
		if (bat2->GetName() == "Bat2")
		{
			const sf::FloatRect& batBounds = bat2->GetGlobalBounds();
			if (shape.getGlobalBounds().intersects(batBounds))
			{
				//pos.y = batBounds.height + batBounds.top; /////////////@
				pos.y = batBounds.top + batBounds.height + shape.getRadius() * 2.f;
				direction.y *= -1.f;
				std::cout << "아야" << std::endl;
			}
		}
	}
	SetPosition(pos);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::Fire(const sf::Vector2f& d, float s)
{
	direction = d;
	speed = s;
}
