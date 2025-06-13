//
// Created by mates on 6/13/2025.
//

#include "Sand.h"

#include "Grid.h"


void Sand::update(float deltaTime, Grid &grid) {
    velocity.y += deltaTime * gravity_force;
    position.y += velocity.y * deltaTime;


    auto new_pos = position / 10;
    if (grid.isValid(new_pos)) {
        if (new_pos != grid_position) {
            if (grid.isEmpty(new_pos)) {
                grid.at(grid_position) = nullptr;
                grid.at(new_pos) = this;
                grid_position = new_pos;
            } else {

                bool moved = false;

                std::array<sf::Vector2i, 2> dirs = {
                    sf::Vector2i(new_pos.x + 1, new_pos.y),
                    sf::Vector2i(new_pos.x - 1, new_pos.y)
                };

                for (const sf::Vector2i& direction : dirs) {
                    if (grid.isValid(direction) && grid.isEmpty(direction)) {
                        grid.at(grid_position) = nullptr;
                        grid.at(direction) = this;
                        position.x = direction.x * 10;
                        grid_position = direction;
                        moved = true;
                        break;
                    }
                }

                if (not moved) {
                    position = grid_position * 10;
                    velocity.y = 0;
                }
            }
        }
    }


    if (position.y + size.y > ground_level) {
        position.y = ground_level - size.y;
        velocity.y = 0;
        grid_position = position / 10;
    }
}
