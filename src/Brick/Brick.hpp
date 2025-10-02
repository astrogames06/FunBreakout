#ifndef BRICK_H
#define BRICK_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

const int BRICK_WIDTH = 50;
const int BRICK_HEIGHT = 20;

extern Game game;

class Brick : public Entity
{
public:
    Color color;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif