//
// Created by mates on 6/4/2025.
//

#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <SFML/Graphics.hpp>
#include "Chunk.h"


class GameObj {
public:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f velocity;

    int id;
    float ground_level = 400;
    bool active = false;

    float gravity_force = 981.f;

    GameObj(int id,  sf::Vector2f position, sf::Vector2f size);

    void update(float deltaTime);

    bool collide(const GameObj* game_obj) const;

    void draw(sf::RenderWindow& window, sf::RectangleShape* rectangle) const;

    void checkCollisions(Chunk* chunk);
};



#endif //GAMEOBJ_H
