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
