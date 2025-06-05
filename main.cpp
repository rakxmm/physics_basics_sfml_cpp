#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameObj.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Physics Engine");

    sf::Clock clock;
    std::vector<GameObj*> game_objs;


    std::vector<std::vector<std::vector<GameObj*>>> game_objs_grid;

    int grid_height = window.getSize().y / 50;
    int grid_width = window.getSize().x / 50;
    game_objs_grid.resize(grid_height);
    for (auto& grid_col : game_objs_grid) {
        grid_col.resize(grid_width);
    }


    window.setFramerateLimit(180);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                for (GameObj* obj : game_objs) {
                    delete obj;
                }
                window.close();
            }
            if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse->button == sf::Mouse::Button::Left) {
                    auto pos = mouse->position;
                    pos.x -= 5;
                    pos.y -= 5;

                    auto obj = new GameObj(sf::Vector2f(pos), {10.f, 10.f}, 10.f, 400);

                    std::cout << "New object has been created on position: {x: " << pos.x << " y: " << pos.y << "}" << std::endl;
                    game_objs.push_back(obj);
                }
            }


        }

        for (auto& grid_col : game_objs_grid) {
            grid_col.clear();
        }

        window.clear(sf::Color::Black);

        for (int index = 0; index < game_objs.size(); ) {
            GameObj* obj = game_objs[index];

            const int row = obj->getGridPosition(50, 50).y;
            const int col = obj->getGridPosition(50, 50).x;
            if (row >= 0 && row < grid_height && col >= 0 && col < grid_width) {
                game_objs_grid[row][col].push_back(obj);
                index++;
            } else {
                delete obj;
                game_objs.erase(game_objs.begin() + index);
                continue;
            }

            obj->draw(window);
            obj->update(deltaTime);

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = col + j;
                    int ny = row + i;

                    if (nx >= 0 &&
                        ny >= 0 &&
                        nx < grid_width &&
                        ny < grid_height) {

                        auto& grid_cell = game_objs_grid[ny][nx];

                        for (GameObj* neighbor : grid_cell) {
                            if (obj != neighbor) {
                                if (obj->collide(neighbor)) {
                                    float overlapX = (obj->position.x + obj->size.x) - neighbor->position.x;
                                    float overlapY = (obj->position.y + obj->size.y) - neighbor->position.y;

                                    if (std::abs(overlapX) < std::abs(overlapY)) {
                                        obj->position -= sf::Vector2f(overlapX / 2, 0);
                                        neighbor->position += sf::Vector2f(overlapX / 2, 0);
                                    } else {
                                        obj->position -= sf::Vector2f(0, overlapY / 2);
                                        neighbor->position += sf::Vector2f(0, overlapY / 2);
                                    }


                                }
                            }

                        }
                    }
                }
            }
        }





        window.display();
    }

    return 0;
}
