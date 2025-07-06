#pragma once
#include "GameObject.h"


class UiHud :
    public GameObject
{
protected:
    //TextGo* TitleText;

    sf::Text textScore;
    sf::Text textScore2;
    sf::Text textGameOver;
    std::string fontId;

    bool isShowMsg = false;

public:
    UiHud();
    ~UiHud();

    void SetMsg(const std::string& msg);
    void SetShowMsg(bool show) { isShowMsg = show; }

    // GameObject을(를) 통해 상속됨
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

};

