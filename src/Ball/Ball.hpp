#ifndef BALL_H
#define BALL_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

class Ball : public Entity
{
public:
    const float BALL_SIZE = 20.f;
    const float BALL_SPEED = 200.f;
    Vector2 vel;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif