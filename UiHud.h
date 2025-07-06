#pragma once
#include "GameObject.h"


class UiHud :
    public GameObject
{
protected:
    //TextGo* TitleText;

    sf::Text titleText;
    std::string fontId;

    bool isShowMsg = false;

public:
    UiHud();
    ~UiHud();

    void SetMsg(const std::string& msg);
    void SetShowMsg(bool show) { isShowMsg = show; }

    // GameObject��(��) ���� ��ӵ�
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

};

