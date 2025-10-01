#ifndef BALL_H
#define BALL_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

class Ball : public Entity
{
public:
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif