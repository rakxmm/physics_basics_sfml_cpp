//
// Created by mates on 6/13/2025.
//

#ifndef STONE_H
#define STONE_H
#include "GameObj.h"


class Stone : public GameObj {
public:
    Stone(int id, sf::Vector2i position, sf::Vector2f size, sf::RectangleShape* rectangle) : GameObj(id, position, size, rectangle) {};

    void update(float deltaTime, Grid &grid) override;

};



#endif //STONE_H
