//
// Created by mates on 6/11/2025.
//

#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

class GameObj;

struct Chunk {
    std::vector<GameObj*> game_objs;

    GameObj& operator[](size_t index);

    const GameObj& operator[](size_t index) const;

    void add(GameObj* obj);

    void remove(const GameObj* obj);

};



#endif //CHUNK_H
