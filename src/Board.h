#pragma once
#include <vector>

#include "Pieces/Piece.h"
#include "Enums/PieceColour.h"
#include "AssetManagers/TextureManager.h"

class Board {
public:
    Board(sf::RenderWindow& window, TextureManager& textureManager);

    void Draw();
    void ClearPossibleMoves();
    void SetPossibleMoves(std::vector<sf::Vector2i> possibleMoves);
    std::vector<Piece*> InitBoardPieces(PieceColour colour);

private:
    sf::RenderWindow& Window;
    TextureManager& TextureManager;

    std::vector<sf::Vector2i> PossibleMoves;
};
