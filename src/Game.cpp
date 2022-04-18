#include <SFML/Graphics.hpp>

#include "Enums/PieceColour.h"
#include "Game.h"

Game::Game() :
    Window(sf::RenderWindow(sf::VideoMode(800, 800), "Chess", sf::Style::Titlebar | sf::Style::Close)),
    TextureManager(),
    Board(Window, TextureManager) {}

void Game::Start() {
    auto whitePieces = Board.InitBoardPieces(PieceColour::White);
    auto blackPieces = Board.InitBoardPieces(PieceColour::Black);

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

        for (int i = 0; i < whitePieces.size(); i++) {
            Window.draw(whitePieces[i]->body);
            Window.draw(blackPieces[i]->body);
        }

        Window.display();
    }

    for (int i = 0; i < whitePieces.size(); i++) {
        delete whitePieces[i];
        delete blackPieces[i];
    }
}
