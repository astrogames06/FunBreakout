#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene/Scene.hpp"
#include "../Game/Game.hpp"

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
    }

    void Update() override
    {

        if (IsKeyDown(KEY_A)) 
        {
            game.SetScene(Scenes::menu_scene.get());
        }
    }

    void Draw() override
    {
        DrawText("Game Scene!", 10, 10, 20, WHITE);
    }
};

#endif