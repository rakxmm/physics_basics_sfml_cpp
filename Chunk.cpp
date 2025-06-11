//
// Created by mates on 6/11/2025.
//

#include "Chunk.h"

#include <iostream>


const GameObj &Chunk::operator[](size_t index) const {
    return *game_objs[index];
}

GameObj &Chunk::operator[](size_t index) {
    return *game_objs[index];
}

void Chunk::add(GameObj *obj) {
    if (obj == nullptr) {
        std::cerr << "Trying to add nullptr into chunk!" << std::endl;
    }

    for (GameObj*& o : game_objs) {
        if (o == nullptr) {
            o = obj;
            return;
        }
    }
}

void Chunk::remove(const GameObj *obj) {
    if (obj == nullptr) {
        std::cerr << "Trying to remove nullptr from chunk!" << std::endl;
    }

    for (GameObj*& o : game_objs) {
        if (o == obj) {
            o = nullptr;
            return;
        }
    }
}



