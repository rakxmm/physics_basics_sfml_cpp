#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameObj.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Physics Engine");
    window.setFramerateLimit(180);
    sf::Clock clock;
    sf::Clock fpsClock;
    std::vector<GameObj*> game_objs;

    sf::RectangleShape rectangle({10, 10});
    rectangle.setFillColor(sf::Color::Green);


    sf::Font font;
    if (!font.openFromFile("fonts/AnakPaud.ttf")) {
        std::cerr << "Font file was not found!" << std::endl;
    }
    sf::Text text(font);
    text.setFillColor(sf::Color::Red);
    text.setPosition({0.f, 0.f});
    text.setCharacterSize(13);


    int click = 0;

    int fps = 0;
    int fps_count = 0;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color::Black);

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
                    click++;
                    pos.x -= 5;
                    pos.y -= 5;

                    auto* obj = new GameObj(click, sf::Vector2f(pos), {10, 10});
                    std::cout << "New object has been created on position: {x: " << pos.x << " y: " << pos.y << "}" << std::endl;
                    game_objs.push_back(obj);
                }
            }


        }
        fps_count++;

        if (fpsClock.getElapsedTime().asSeconds() >= .5f) {
            fps = 2 * fps_count;
            std::cout << "FPS: " << fps << std::endl;
            fps_count = 0;
            fpsClock.restart();
        }



       for (GameObj* obj : game_objs) {
           obj->update(deltaTime);






           obj->draw(window, &rectangle);
       }
        text.setString("FPS: " + std::to_string(fps));
        window.draw(text);





        window.display();
    }

    return 0;
}
