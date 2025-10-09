#include "PowerUpSystem.hpp"

#include <chrono>

#include "PowerUp.hpp"
#include "../Ball/Ball.hpp"
#include "../Main/Main.hpp"

bool power_upped = false;

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

std::chrono::steady_clock::time_point start_time;
bool set_start_time = false;

void RunPowerUpSystem()
{
    Ball* ball = game.GetEntityOfType<Ball>();    
    
    if (power_upped && ball != nullptr)
    {
        if (!set_start_time)
        {
            start_time = std::chrono::steady_clock::now();
            set_start_time = true;
        }

        switch (current_powerup_type)
        {
        case FIRE:
            ball->bounce = false;
            break;
        case SPEED:
            ball->BALL_SPEED = ball->BALL_SPEED_DEFAULT + 100.f;
            break;
        case SIZE:
            ball->BALL_SIZE = ball->BALL_SIZE_DEFAULT * 1.5;
            break;
        default:
            break;
        }
    }

    // Times ball powerup and resets after 5 seconds
    std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed = current_time - start_time;

    if (elapsed.count() >= 5.f)
    {       
        ball->color = WHITE;
        ball->BALL_SPEED = ball->BALL_SPEED_DEFAULT;
        ball->BALL_SIZE = ball->BALL_SIZE_DEFAULT;
        ball->bounce = true;

        set_start_time = false;
        power_upped = false;
    }
}