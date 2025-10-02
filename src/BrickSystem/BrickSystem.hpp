#ifndef BRICKSYSTEM_H
#define BRICKSYSTEM_H

#include <vector>
#include <string>
#include <raylib.h>

#include "../Brick/Brick.hpp"

const std::vector<std::vector<std::string>> game_levels = {
    {
        "###0###0###",
        "###0###0###",
        "###0###0###",
    },
    {
        "0#0#0#0#0#0",
        "0#0#0#0#0#0",
        "0#0#0#0#0#0",
    }
};

void BrickLoadSystem(const std::vector<std::string>& level);

#endif