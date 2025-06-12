//
// Created by mates on 6/11/2025.
//

#ifndef GRID_H
#define GRID_H
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "GameObj.h"

class GameObj;


struct Grid {
    std::vector<std::vector<GameObj*>> grid;
    int rows;
    int cols;

    Grid(size_t rows, size_t cols) : grid(rows, std::vector<GameObj*>(cols, nullptr)), rows(rows), cols(cols) {}

    GameObj*& at(size_t  row_index, size_t  col_index) {
        return grid[row_index][col_index];
    }
    GameObj* at(size_t  row_index, size_t  col_index) const {
        return grid[row_index][col_index];
    }

    GameObj*& at(sf::Vector2i indexes) {
        return grid[indexes.y][indexes.x];
    }
    GameObj* at(sf::Vector2i indexes) const {
        return grid[indexes.y][indexes.x];
    }

    bool isEmpty(sf::Vector2i grid_position) {
        return at(grid_position) == nullptr;
    }

    bool isEmpty(size_t row, size_t col) {
        return at(row, col) == nullptr;
    }

    bool isValid(sf::Vector2i position) {
        return position.x >= 0 && position.y >= 0 && position.x < cols && position.y < rows;
    }

    ~Grid() {
        for (auto row : grid) {
            for (GameObj* obj : row) {
                delete obj;
            }
        }
    }

};



#endif //GRID_H
