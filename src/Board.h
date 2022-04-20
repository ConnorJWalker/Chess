#pragma once
#include <utility>
#include <unordered_set>

#include "Pieces/Piece.h"
#include "Enums/PieceColour.h"
#include "Helpers/VectorHash.h"
#include "AssetManagers/TextureManager.h"
#include "Players/Player.h"

class Board {
public:
    Board(sf::RenderWindow& window, TextureManager& textureManager, Player* players);

    int CurrentPlayer = 0;

    void Draw();
    void ClearPossibleMoves();
    void SetPossibleMoves(std::vector<sf::Vector2i> possibleMoves);
    bool ClickedPossibleMove(sf::Vector2i mousePosition);
    std::vector<Piece*> InitBoardPieces(PieceColour colour);

private:
    sf::RenderWindow& Window;
    TextureManager& TextureManager;

    Player* Players;

    bool ShouldFillPossibleMovesOnPiece = false;

    std::unordered_set<sf::Vector2i> PossibleMoves{};
    std::unordered_set<sf::Vector2i> PossibleMovesOnPiece{};

    sf::Color WhiteSquareColour = sf::Color::White;
    sf::Color BlackSquareColor = sf::Color(110, 80, 60);
    sf::Color PosssibleMoveColour = sf::Color(200, 100, 100, 200);

    void DrawSquares();
    void DrawPossibleMoves();
    void DrawPossibleMovesOnPiece(sf::Vector2i square);

    void FillPossibleMovesOnPiece();
};
