#include "PowerUpSystem.hpp"

#include "PowerUp.hpp"
#include "../Ball/Ball.hpp"

bool power_upped = false;

void RunPowerUpSystem()
{
    Ball* ball = game.GetEntityOfType<Ball>();    
    
    if (power_upped && ball != nullptr)
    {
        switch (current_powerup_type)
        {
        case FIRE:
            ball->BALL_SPEED = ball->BALL_SPEED_DEFAULT - 50.f;
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
}