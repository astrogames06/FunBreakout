#include "PowerUp.hpp"

#include <raymath.h>
#include <iostream>
#include <array>

#include "../Main/Main.hpp"
#include "../Player/Player.hpp"
#include "../Ball/Ball.hpp"

#include "PowerUpSystem.hpp"

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

std::array<Color, 3> colors_option = {
    RED,
    BLUE,
    GREEN,
};

void PowerUp::Init()
{
    powerup_type = GetRandomValue(0, SIZE);
    color = colors_option[powerup_type];
}

void PowerUp::Update()
{
    y += 100 * GetFrameTime(); // moves down

    Player* player = game.GetEntityOfType<Player>();
    Ball* ball = game.GetEntityOfType<Ball>();
    if (CheckCollisionCircleRec({(float)x, (float)y}, 5.f, 
        {(float)player->x, (float)player->y, (float)player->width, (float)player->height}
    ))
    {
        power_upped = true;
        ball->color = color;
        current_powerup_type = powerup_type;
        
        Delete();
    }
}

void PowerUp::Draw()
{
    DrawCircle(x, y, 5.f, color);
}