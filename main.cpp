#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObj.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Physics Engine");

    sf::Clock clock;

    GameObj game_obj();
    window.setFramerateLimit(180);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);



        window.display();
    }

    return 0;
}
