//
// Created by mates on 6/4/2025.
//

#include "GameObj.h"
#include <SFML/Graphics.hpp>


GameObj::GameObj(int id, sf::Vector2f position, sf::Vector2f size) :
    id(id), position(position), size(size) {

}

void GameObj::update(float deltaTime) {
    velocity.y += deltaTime * gravity_force;
    position.y += velocity.y * deltaTime;

    if (position.y + size.y > ground_level) {
        position.y = ground_level - size.y;
        velocity.y = 0;
        active = false;
    }
}


bool GameObj::collide(const GameObj *game_obj) const {
    return position.x + size.x > game_obj->position.x &&
        position.x < game_obj->position.x + game_obj->size.x &&
            position.y + size.y > game_obj->position.y &&
        position.y < game_obj->position.y + game_obj->size.y;
}

void GameObj::draw(sf::RenderWindow &window, sf::RectangleShape* rectangle) const {
    rectangle->setPosition(position);
    window.draw(*rectangle);
}






