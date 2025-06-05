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

    sf::Vector2i getGridPosition(int square_width, int square_height);

    bool collide(GameObj* obj);

    void setPosition(sf::Vector2f position);

    float bottom();

    float top();

    float right();

    float left();
};



#endif //GAMEOBJ_H
