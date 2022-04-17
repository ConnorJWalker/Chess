#include <SFML/Graphics.hpp>

#include "game.h"

Game::Game() : Window(sf::VideoMode(200, 200), "Chess") {}

void Game::Start() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear();
        Window.draw(shape);
        Window.display();
    }
}
