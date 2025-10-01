#ifndef PLAYER_H
#define PLAYER_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

class Player : public Entity
{
public:
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif