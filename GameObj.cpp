//
// Created by mates on 6/4/2025.
//

#include "GameObj.h"

#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Grid.h"


struct Grid;



GameObj::GameObj(int id, sf::Vector2i position, sf::Vector2f size, sf::RectangleShape* rectangle) :
    id(id), position(position), size(size), rectangle(rectangle) {

}

void GameObj::update(float deltaTime, Grid &grid) {

}


bool GameObj::collide(const GameObj *game_obj) const {
    return position.x + size.x > game_obj->position.x &&
        position.x < game_obj->position.x + game_obj->size.x &&
            position.y + size.y > game_obj->position.y &&
        position.y < game_obj->position.y + game_obj->size.y;
}

void GameObj::draw(sf::RenderWindow &window) const {
    if (rectangle) {
        rectangle->setPosition(sf::Vector2f(grid_position * 10));
        window.draw(*rectangle);
    }

}

sf::Vector2i GameObj::getGridPosition() const {
    return this->grid_position;
}






