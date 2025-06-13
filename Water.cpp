//
// Created by mates on 6/13/2025.
//

#include "Water.h"

#include "Grid.h"


void Water::update(float deltaTime, Grid &grid) {
    velocity.y += deltaTime * gravity_force;
    position.y += velocity.y * deltaTime;


    auto new_pos = position / 10;

    std::array<sf::Vector2i, 2> directions = {
        sf::Vector2i(new_pos.x + 1, new_pos.y),
        sf::Vector2i(new_pos.x - 1, new_pos.y)
    };

    if (grid_position != new_pos && grid.isValid(new_pos)) {
        if (grid.isEmpty(new_pos)) {
            grid.at(grid_position) = nullptr;
            grid.at(new_pos) = this;
            this->grid_position = new_pos;
            position = grid_position * 10;

        } else {
            bool moved = false;

            for (sf::Vector2i& direction : directions) {
zle je toto
                if (grid.isEmpty(direction)) {
                    grid.at(grid_position) = nullptr;
                    grid_position = direction;
                    grid.at(grid_position) = this;
                    moved = true;
                    position = grid_position * 10;
                    break;
                }
            }
            if (not moved) {
                position = grid_position * 10;
                velocity.y = 0;
            }
        }

    }




    if (position.y + size.y > ground_level) {
        position.y = ground_level - size.y;
        velocity.y = 0;
        grid_position = position / 10;
    }
}
