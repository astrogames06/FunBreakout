#ifndef POWERUP_H
#define POWERUP_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

enum POWERUP_TYPE
{
    FIRE = 0,
    SPEED = 1,
    SIZE = 2,
};

class PowerUp : public Entity
{
public:
    int powerup_type;
    Color color;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif