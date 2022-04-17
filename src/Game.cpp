#include <SFML/Graphics.hpp>

#include "Game.h"

Game::Game() :
    Window(new sf::RenderWindow(sf::VideoMode(800, 800), "Chess")),
    Board(Window) {}

Game::~Game() {
    delete Window;
}

void Game::Start() {

    while (Window->isOpen())
    {
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
        }

        Window->clear();
        Board.Draw();
        Window->display();
    }
}
