#include <string>
#include <SFML/Graphics.hpp>
#include <utility>

#include "Enums/PieceColour.h"
#include "Game.h"

Game::Game(GameMode gameMode, std::string player1Name, std::string player2Name) :
    Window(sf::RenderWindow(sf::VideoMode(1250, 800), "Chess", sf::Style::Titlebar | sf::Style::Close)),
    TextureManager(),
    Board(Window, TextureManager, Players),
    Players {
    Player(Window, PieceColour::White,Board.InitBoardPieces(PieceColour::White)),
    Player(Window, PieceColour::Black,Board.InitBoardPieces(PieceColour::Black))
    },
    UI(Window, TextureManager, std::move(player1Name), std::move(player2Name), gameMode == GameMode::Local)
    {}

void Game::Start() {
    while (Window.isOpen())
    {
        HandleEvents();
        Draw();
    }
}

void Game::Draw() {
    Window.clear(sf::Color(35, 40, 50));

    Board.Draw();
    Players[0].Draw();
    Players[1].Draw();
    UI.Draw();

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
    int currentPlayer = Board.CurrentPlayer;

    int index = Players[currentPlayer].FindClickedPieceIndex(mousePosition);
    if (index != -1) {
        SelectedPieceIndex = index;
        Board.ClearPossibleMoves();
        if (event.mouseButton.button == sf::Mouse::Left) {
            int otherPlayer = currentPlayer == 0 ? 1 : 0;
            auto possibleMoves = Players[currentPlayer].GetPossibleMoves(SelectedPieceIndex, Players[otherPlayer].GetPieces());
            Board.SetPossibleMoves(possibleMoves);
        }
    }
    else {
        if (Board.ClickedPossibleMove(mousePosition)) {
            Players[currentPlayer].MovePiece(SelectedPieceIndex, mousePosition / 100);
            PieceType type = Players[currentPlayer == 0 ? 1 : 0].TryRemovePiece(mousePosition / 100);
            if (type != PieceType::None) {
                UI.UpdateScore(type, currentPlayer);
            }

            SelectedPieceIndex = -1;
            Board.CurrentPlayer = currentPlayer == 0 ? 1 : 0;
        }

        Board.ClearPossibleMoves();
    }
}
