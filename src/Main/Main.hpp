#ifndef MAIN_H
#define MAIN_H

#include "../Scene/Scene.hpp"
#include "../Game/Game.hpp"
#include "../Menu/Menu.hpp"

#include "../Player/Player.hpp"
#include "../Ball/Ball.hpp"

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

        std::unique_ptr<Ball> ball = std::make_unique<Ball>();
        game.AddEntity(std::move(ball));
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