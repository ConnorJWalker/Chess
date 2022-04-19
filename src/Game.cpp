#include <SFML/Graphics.hpp>

#include "Enums/PieceColour.h"
#include "Game.h"

Game::Game() :
    Window(sf::RenderWindow(sf::VideoMode(800, 800), "Chess", sf::Style::Titlebar | sf::Style::Close)),
    TextureManager(),
    Board(Window, TextureManager),
    Players {
    Player(Window, PieceColour::White,Board.InitBoardPieces(PieceColour::White)),
    Player(Window, PieceColour::Black,Board.InitBoardPieces(PieceColour::Black))
    } {}

void Game::Start() {
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        Draw();
    }
}

void Game::Draw() {
    Window.clear();

    Board.Draw();
    Players[0].Draw();
    Players[1].Draw();

    Window.display();
}
