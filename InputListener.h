#pragma once
#include "InputMgr.h"
class InputListener 
{

private:
public:
    virtual ~InputListener() = default; // 가상 소멸자
    virtual void onKeyPressed(sf::Keyboard::Key key) = 0;
    virtual void onKeyReleased(sf::Keyboard::Key key) = 0;
    virtual void onMouseButtonPressed(sf::Mouse::Button button) = 0;
    virtual void onMouseButtonReleased(sf::Mouse::Button button) = 0;
};

