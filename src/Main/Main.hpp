#ifndef MAIN_H
#define MAIN_H

#include "../Scene/Scene.hpp"
#include "../Game/Game.hpp"
#include "../Menu/Menu.hpp"

#include "../Player/Player.hpp"
#include "../Ball/Ball.hpp"

#include "../BrickSystem/BrickSystem.hpp"

#include <iostream>

extern Game game;
namespace Scenes
{
    extern std::unique_ptr<Menu> menu_scene;
};

class Main : public Scene
{
public:
    int score = 0;
    int level = 0;

private:
    void Init() override
    {
        background_color = BLACK;

        std::unique_ptr<Player> player = std::make_unique<Player>();
        game.AddEntity(std::move(player));

        std::unique_ptr<Ball> ball = std::make_unique<Ball>();
        game.AddEntity(std::move(ball));

        BrickLoadSystem(game_levels[level]);
    }

    void Update() override
    {
        if (game.GetEntitiesOfType<Brick>().size() == 0)
        {
            level = (level + 1) % game_levels.size();
            BrickLoadSystem(game_levels[level]);
        }
    }

    void Draw() override
    {
        std::string score_str = "Score: " + std::to_string(score);
        DrawText(score_str.c_str(), 10, 10, 20, WHITE);

        std::string level_str = "Level: " + std::to_string(level);
        DrawText(level_str.c_str(), 10, 30, 20, WHITE);
    }
};

#endif