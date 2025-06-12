//
// Created by mates on 6/4/2025.
//

#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <SFML/Graphics.hpp>


struct Grid;

class GameObj {
public:
    sf::Vector2i position;
    sf::Vector2i grid_position;
    sf::Vector2f size;
    sf::Vector2f velocity;

    int id;
    float ground_level = 400;

    float gravity_force = 1500.f;

    GameObj(int id, sf::Vector2i position, sf::Vector2f size);

    void update(float deltaTime, Grid &grid);

    bool collide(const GameObj* game_obj) const;

    void draw(sf::RenderWindow& window, sf::RectangleShape* rectangle) const;

    sf::Vector2i getGridPosition() const;
};



#endif //GAMEOBJ_H
