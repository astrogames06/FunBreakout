#include "BrickSystem.hpp"

#include "../Main/Main.hpp"

namespace Scenes
{
    extern std::unique_ptr<Main> main_scene;
};

void BrickLoadSystem(const std::vector<std::string>& level)
{
    for (int i = 0; i < level.size(); i++)
    {
        std::string row = level[i];
        int row_width = row.size() * (BRICK_WIDTH * 1.2);

        for (int j = 0; j < row.size(); j++)
        {
            char item = row[j];
            if (item == '#')
            {
                std::unique_ptr<Brick> new_brick = std::make_unique<Brick>();

                new_brick->x = (j * (BRICK_WIDTH*1.2))+((game.WIDTH-row_width)/2);
                new_brick->y = (i * (BRICK_HEIGHT*1.2))+30;

                game.AddEntity(std::move(new_brick));
            }
        }
    }
}