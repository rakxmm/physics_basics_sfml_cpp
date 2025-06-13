#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameObj.h"
#include "Grid.h"
#include "Sand.h"
#include "Stone.h"

enum class ObjType {
    STONE,
    WATER,
    SAND,
    NONE
};

int main() {
    int win_x = 600;
    int win_y = 400;

    sf::RenderWindow window(sf::VideoMode({600, 400}), "Physics Engine", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(180);

    sf::Clock clock;
    sf::Clock fpsClock;
    std::vector<GameObj*> game_objs;

    sf::RectangleShape sand({10, 10});
    sand.setFillColor(sf::Color::Yellow);
    sf::RectangleShape stone({10, 10});
    stone.setFillColor(sf::Color::White);

    int grid_square_size = 10;

    Grid grid(win_y / grid_square_size, win_x / grid_square_size);
    
    ObjType selected = ObjType::NONE;

    sf::Font font;
    if (!font.openFromFile("fonts/AnakPaud.ttf")) {
        std::cerr << "Font file was not found!" << std::endl;
    }

    sf::Text text(font);
    text.setFillColor(sf::Color::Red);
    text.setPosition({0.f, 0.f});
    text.setCharacterSize(13);


    int obj_count = 0;
    int fps = 0;
    int fps_count = 0;


    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color::Black);

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                for (GameObj* obj : game_objs) {
                    if (obj) {
                        auto gp = obj->getGridPosition();
                        if (grid.isValid(gp) && grid.at(gp) == obj) {
                            grid.at(gp) = nullptr;
                        }
                        delete obj;
                    }
                }
                window.close();
            } else if (auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key) {
                    switch (key->scancode) {
                        case sf::Keyboard::Scancode::Q:
                            selected = ObjType::STONE;
                            break;
                        case sf::Keyboard::Scancode::W:
                            selected = ObjType::SAND;
                            break;
                        default: break;
                    }
                }

            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && selected != ObjType::NONE) {
            auto pos = sf::Mouse::getPosition(window);
            pos /= grid_square_size;
            if (grid.isValid(pos) && grid.isEmpty(pos)) {

                pos *= grid_square_size;
                obj_count++;
                GameObj* obj;
                switch (selected) {
                    case ObjType::SAND:
                        obj = new Sand(obj_count, pos, {10, 10}, &sand);
                        break;
                    case ObjType::STONE:
                        obj = new Stone(obj_count, pos, {10, 10}, &stone);
                        break;
                }

                game_objs.push_back(obj);
            }
        }

        fps_count++;
        if (fpsClock.getElapsedTime().asSeconds() >= .5f) {
            fps = 2 * fps_count;
            fps_count = 0;
            fpsClock.restart();
        }



        for (GameObj* obj : game_objs) {
            obj->update(deltaTime, grid);



            obj->draw(window);
        }


        // To draw FPS on screen.
        text.setString("FPS: " + std::to_string(fps) + "\nObjects: " + std::to_string(obj_count));
        window.draw(text);

        window.display();
    }

    return 0;
}
