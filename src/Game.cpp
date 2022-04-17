#include <SFML/Graphics.hpp>

#include "Game.h"

Game::Game() :
    Window(sf::RenderWindow(sf::VideoMode(800, 800), "Chess")),
    Board(Window) {}

void Game::Start() {

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear();
        Board.Draw();
        Window.display();
    }
}
