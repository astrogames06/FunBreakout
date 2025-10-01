#ifndef MENU_H
#define MENU_H

#include "../Scene/Scene.hpp"
#include "../Game/Game.hpp"

#include "../Player/Player.hpp"

#include <iostream>

class Game;
extern Game game;

class Menu : public Scene
{
    void Init() override
    {
        background_color = BLACK;
    }

    void Update() override
    {
    }

    void Draw() override
    {
        DrawText("Menu Scene!", 10, 10, 20, WHITE);
    }
};

#endif