//
// Created by mates on 6/13/2025.
//

#ifndef WATER_H
#define WATER_H
#include "GameObj.h"


class Water : public GameObj {
public:
    Water(int id, sf::Vector2i position, sf::Vector2f size, sf::RectangleShape* rectangle) : GameObj(id, position, size, rectangle) {};

    void update(float deltaTime, Grid &grid) override;
};



#endif //WATER_H
