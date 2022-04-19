#include <iostream>
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
        HandleEvents();
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

void Game::HandleEvents() {
    sf::Event event{};
    while (Window.pollEvent(event))
    {
        switch(event.type) {
            case sf::Event::Closed:
                Window.close();
                break;
            case sf::Event::MouseButtonPressed:
                HandleClickEvent(event);
                break;
            default: break;
        }
    }
}

void Game::HandleClickEvent(sf::Event event) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(Window);

    int index = Players[CurrentPlayer].FindClickedPieceIndex(mousePosition);
    if (index != -1) {
        SelectedPieceIndex = index;
        if (event.mouseButton.button == sf::Mouse::Left) {
            int otherPlayer = CurrentPlayer == 0 ? 1 : 0;
            auto possibleMoves = Players[CurrentPlayer].GetPossibleMoves(SelectedPieceIndex, Players[otherPlayer].GetPieces());

            Board.SetPossibleMoves(possibleMoves);
        }
    }
    else {
        if (Board.ClickedPossibleMove(mousePosition)) {
            Players[CurrentPlayer].MovePiece(SelectedPieceIndex, mousePosition / 100);
        }

        Board.ClearPossibleMoves();
    }
}
