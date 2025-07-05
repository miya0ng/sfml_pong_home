#include "stdafx.h"
#include "Bat.h"

Bat::Bat(const std::string& name)
	: GameObject(name)
{
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Bat::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Bat::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Bat::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Bat::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(shape, preset);
	}
}

void Bat::Init()
{
	if(this->GetName() == "Bat")
	{
		shape.setSize({ 100.f, 5.f });
		shape.setFillColor(sf::Color::White);
		SetOrigin(Origins::TC);
	}
	else if (this->GetName() == "Bat2")
	{
		shape.setSize({ 200.f, 5.f });
		shape.setFillColor(sf::Color::Blue);
		SetOrigin(Origins::TC);
	}
	
}

void Bat::Release()
{
}

void Bat::Reset()
{
	if (this->GetName() == "Bat")
	{
		sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
		SetPosition({ bounds.width * 0.5f, bounds.height - 20.f });

		sf::Vector2f size = shape.getSize();
		minX = bounds.left + size.x * 0.5f;
		maxX = (bounds.left + bounds.width) - size.x * 0.5f;
	}

	if (this->GetName() == "Bat2")
	{
		sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
		SetPosition({ bounds.width * 0.5f, 20.f });

		sf::Vector2f size = shape.getSize();
		minX = bounds.left + size.x * 0.5f;
		maxX = (bounds.left + bounds.width) - size.x * 0.5f;
	}
}

void Bat::Update(float dt)
{
	if (this->GetName() == "Bat")
	{
		direction.x = InputMgr::GetAxis(Axis::Horizontal);
		sf::Vector2f pos = GetPosition() + direction * speed * dt;
		pos.x = Utils::Clamp(pos.x, minX, maxX);
		SetPosition(pos);
	}

	if (this->GetName() == "Bat2")
	{
		direction2.x = InputMgr::GetAxis(Axis::Horizontal2);
		sf::Vector2f pos = GetPosition() + direction2 * speed * dt;
		pos.x = Utils::Clamp(pos.x, minX, maxX);
		SetPosition(pos);
	}
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
