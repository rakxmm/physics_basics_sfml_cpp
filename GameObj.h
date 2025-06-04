//
// Created by mates on 6/4/2025.
//

#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <SFML/Graphics.hpp>


class GameObj {
public:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f velocity;
    float mass;
    float ground_level;

    sf::RectangleShape rect;


    GameObj(sf::Vector2f position, sf::Vector2f size, float mass, float ground_level);

    void update(float deltaTime);

    void draw(sf::RenderWindow& window);
};



#endif //GAMEOBJ_H
