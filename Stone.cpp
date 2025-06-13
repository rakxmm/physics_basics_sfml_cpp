//
// Created by mates on 6/13/2025.
//

#include "Stone.h"

#include "Grid.h"


void Stone::update(float deltaTime, Grid &grid) {

    grid_position = position / 10;
    if (grid.isEmpty(grid_position)) {
        grid.at(grid_position) = this;
    }

}
