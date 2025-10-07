#include "PowerUpSystem.hpp"

#include "PowerUp.hpp"
#include "../Ball/Ball.hpp"
#include "../Main/Main.hpp"

bool power_upped = false;

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

int before_score;
bool save_before_score = false;

void RunPowerUpSystem()
{
    Ball* ball = game.GetEntityOfType<Ball>();    
    
    if (power_upped && ball != nullptr)
    {
        if (!save_before_score)
        {
            before_score = Scenes::main_scene->score;
            save_before_score = true;
        }

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

    // Resets ball
    if (Scenes::main_scene->score >= (before_score+5))
    {
        ball->color = WHITE;
        ball->BALL_SPEED = ball->BALL_SPEED_DEFAULT;
        ball->BALL_SIZE = ball->BALL_SIZE_DEFAULT;

        save_before_score = false;
    }
}