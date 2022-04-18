#pragma once
#include "Pieces/Piece.h"
#include "Enums/PieceColour.h"
#include "AssetManagers/TextureManager.h"

class Board {
public:
    Board(sf::RenderWindow& window, TextureManager& textureManager);
    void Draw();
    std::vector<Piece*> InitBoardPieces(PieceColour colour);

private:
    sf::RenderWindow& Window;
    TextureManager& TextureManager;
};
