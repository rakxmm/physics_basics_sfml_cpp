//
// Created by mates on 6/13/2025.
//

#ifndef SAND_H
#define SAND_H
#include "GameObj.h"


class Sand : public GameObj {
public:
    Sand(int id, sf::Vector2i position, sf::Vector2f size, sf::RectangleShape* rectangle) : GameObj(id, position, size, rectangle) {};

    void update(float deltaTime, Grid &grid) override;
};



#endif //SAND_H
