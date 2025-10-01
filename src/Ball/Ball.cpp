#include "Ball.hpp"

#include <raymath.h>

#include "../Player/Player.hpp"

const float BALL_SIZE = 20.f;
const float BALL_SPEED = 200.f;
Vector2 vel;

void Ball::Init()
{
    x = game.WIDTH/2-BALL_SIZE/2;
    y = game.HEIGHT/2-BALL_SIZE/2;

    vel = {
        (float)GetRandomValue(-1, 1),
        (float)GetRandomValue(-1, 1)
    };
}

void Ball::Update()
{
    x += vel.x * BALL_SPEED * GetFrameTime();
    y += vel.y * BALL_SPEED * GetFrameTime();


    // wall bouncing
    if (x < 0)
    {
        x = 0;
        vel.x *= -1;
    }
    if (x+BALL_SIZE > game.WIDTH)
    {
        x = game.WIDTH-BALL_SIZE;
        vel.x *= -1;
    }
    if (y < 0)
    {
        y = 0;
        vel.y *= -1;
    }
    if (y+BALL_SIZE > game.HEIGHT)
    {
        y = game.HEIGHT-BALL_SIZE;
        vel.y *= -1;
    }

    // paddle bouncing
    Player* player = game.GetEntityOfType<Player>();
    
    if (CheckCollisionRecs(
        {(float)x, (float)y, BALL_SIZE, BALL_SIZE},
        {(float)player->x, (float)player->y, (float)player->width, (float)player->height}
    ) && vel.y > 0 && (y + BALL_SIZE <= player->y + 5)) // makes sure it doesnt bounce is the bottom of the ball is below the top of the paddle
    {
        vel.y *= -1;
    }
}

void Ball::Draw()
{
    DrawRectangle(x, y, BALL_SIZE, BALL_SIZE, WHITE);
    DrawCircle(x, y+BALL_SIZE, 2.f, GREEN);
}