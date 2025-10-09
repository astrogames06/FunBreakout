#ifndef BALL_H
#define BALL_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

class Ball : public Entity
{
public:
    Color color;
    Vector2 vel;

    float BALL_SIZE = 20.f;
    const float BALL_SIZE_DEFAULT = 20.f;
    
    float BALL_SPEED = 200.f;
    const float BALL_SPEED_DEFAULT = 200.f;

    bool bounce = true;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif