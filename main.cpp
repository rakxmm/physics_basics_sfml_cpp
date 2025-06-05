#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameObj.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Physics Engine");

    sf::Clock clock;
    std::vector<GameObj*> game_objs;


    std::vector<std::vector<std::vector<GameObj*>>> game_objs_grid;

    game_objs_grid.resize(window.getSize().y / 50);
    for (auto& grid_col : game_objs_grid) {
        grid_col.resize(window.getSize().x / 50);
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

                    int gridX = pos.x / 50;
                    int gridY = pos.y / 50;
                    auto obj = new GameObj(sf::Vector2f(pos), {10.f, 10.f}, 10.f, 400);
                    game_objs_grid[gridX][gridY].push_back(obj);
                    treba spravit kolizie
                    std::cout << "New object has been created on position: {x: " << pos.x << " y: " << pos.y << "}" << std::endl;
                    game_objs.push_back(obj);
                }
            }


        }
        window.clear(sf::Color::Black);

        for (GameObj* obj : game_objs) {
            obj->draw(window);
            obj->update(deltaTime);
        }



        window.display();
    }

    return 0;
}
