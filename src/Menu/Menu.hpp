#ifndef MENU_H
#define MENU_H

#include "../Scene/Scene.hpp"

class Menu : public Scene
{
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif