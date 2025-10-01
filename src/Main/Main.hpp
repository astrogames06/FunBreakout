#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene/Scene.hpp"
#include "../Game/Game.hpp"
#include "../Player/Player.hpp"
#include "../Menu/Menu.hpp"

#include <iostream>

extern Game game;
namespace Scenes
{
    extern std::unique_ptr<Menu> menu_scene;
};

class Main : public Scene
{
    void Init() override
    {
        background_color = BLACK;

        std::unique_ptr<Player> player = std::make_unique<Player>();
        game.AddEntity(std::move(player));
    }

    void Update() override
    {
    }

    void Draw() override
    {
        DrawText("Game Scene!", 10, 10, 20, WHITE);
    }
};

#endif