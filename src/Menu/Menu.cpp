#include "Menu.hpp"

#include <iostream>
#include <raygui.h>

#include "../Game/Game.hpp"
#include "../Main/Main.hpp"
#include "../Player/Player.hpp"

class Game;
extern Game game;

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

void Menu::Init()
{
    background_color = BLACK;
}

void Menu::Update()
{

}

void Menu::Draw()
{
    DrawText("Menu Scene!", 10, 10, 20, WHITE);

    if (GuiButton({(float)game.WIDTH/2-100/2, 250, 100, 80}, "Play!"))
    {
        game.SetScene(Scenes::main_scene.get());
    }
}