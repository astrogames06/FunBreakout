#include "Player.hpp"

#include <raymath.h>

void Player::Init()
{
    x = game.WIDTH/2-100/2;
    y = game.HEIGHT-100;
}

void Player::Update()
{
    x = Clamp(x, 0, game.WIDTH-100);
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        x -= 500 * GetFrameTime();
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        x += 500 * GetFrameTime();
    }
}

void Player::Draw()
{
    DrawRectangle(x, y, 100, 20, RED);
}