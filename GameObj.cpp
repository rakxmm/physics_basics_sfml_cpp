//
// Created by mates on 6/4/2025.
//

#include "GameObj.h"
#include <SFML/Graphics.hpp>


GameObj::GameObj(sf::Vector2f position, sf::Vector2f size, float mass, float ground_level) {
    this->size = size;
    this->mass = mass;
    this->position = position;
    this->ground_level = ground_level;
    this->rect.setSize(size);
    this->rect.setFillColor(sf::Color::Green);
    this->rect.setPosition(this->position);
}


void GameObj::update(float deltaTime) {
    this->velocity.y += 981.f * deltaTime;
    this->position.y += this->velocity.y * deltaTime;

    if (this->position.y + this->size.y>= this->ground_level) {
        this->position.y = this->ground_level - this->size.y;
    }

    this->rect.setPosition(this->position);
}

void GameObj::draw(sf::RenderWindow &window) {
    window.draw(this->rect);
}

sf::Vector2i GameObj::getGridPosition(int square_width, int square_height) {
    int col = this->position.x / square_width;
    int row = this->position.y / square_height;
    return {col, row};
}

bool GameObj::collide(GameObj* obj) {
    return obj->position.x + obj->size.x > this->position.x &&
        obj->position.x < this->position.x + this->size.x &&
            obj->position.y + obj->size.y > this->position.y &&
        obj->position.y < this->position.y + this->size.y;;
}

void GameObj::setPosition(sf::Vector2f position) {
    this->position = position;
    this->rect.setPosition(position);
}

float GameObj::bottom() {
    return this->position.y + this->size.y;
}

float GameObj::left() {
    return this->position.x;
}

float GameObj::right() {
    return this->position.x + this->size.x;
}

float GameObj::top() {
    return this->position.y;
}





