#include "Brick.hpp"

#include <raymath.h>
#include <iostream>
#include <array>

#include "../Main/Main.hpp"
#include "../Player/Player.hpp"
#include "../Ball/Ball.hpp"

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

std::array<Color, 6> brick_colors = {
    RED,
    BLUE,
    GREEN,
    ORANGE,
    PURPLE,
    YELLOW
};

void Brick::Init()
{
    color = brick_colors[GetRandomValue(0, brick_colors.size()-1)];
}

void Brick::Update()
{
    Ball* ball = game.GetEntityOfType<Ball>();

    if (CheckCollisionRecs(
        {(float)x, (float)y, (float)BRICK_WIDTH, (float)BRICK_HEIGHT}, 
        {(float)ball->x, (float)ball->y, ball->BALL_SIZE, ball->BALL_SIZE}
    ))
    {
        Delete();
        Scenes::main_scene->score++;
    }
}

void Brick::Draw()
{
    DrawRectangle(x, y, BRICK_WIDTH, BRICK_HEIGHT, color);
}