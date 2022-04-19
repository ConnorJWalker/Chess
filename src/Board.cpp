#include <vector>
#include <SFML/Graphics.hpp>

#include "Pieces/Pawn.h"
#include "Pieces/Castle.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Board.h"

Board::Board(sf::RenderWindow& window, class TextureManager& textureManager) : Window(window), TextureManager(textureManager) {}

void Board::Draw() {
    // Draw chess board squares (8 x 8)
    bool isWhiteSquare = true;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
            square.setFillColor(isWhiteSquare ? sf::Color::White : sf::Color(110, 80, 60));
            square.setPosition(x * 100, y * 100);

            Window.draw(square);

            isWhiteSquare = !isWhiteSquare;
        }

        isWhiteSquare = !isWhiteSquare;
    }
}

std::vector<Piece*> Board::InitBoardPieces(PieceColour colour) {
    std::vector<Piece*> pieces;
    int pawnY = colour == PieceColour::White ? 6 : 1;
    int otherY = colour == PieceColour::White ? 7 : 0;

    // Add pawns to pieces array
    sf::Texture& pawnTexture = TextureManager.GetTexture(PieceType::Pawn, colour);
    for (int i = 0; i < 8; i++) {
        pieces.push_back(new Pawn(sf::Vector2i(i, pawnY), pawnTexture));
    }

    // Add the rest of the chest pieces
    sf::Texture& castleTexture = TextureManager.GetTexture(PieceType::Castle, colour);
    pieces.push_back(new Castle(sf::Vector2i(0, otherY), castleTexture));
    pieces.push_back(new Castle(sf::Vector2i(7, otherY), castleTexture));

    sf::Texture& knightTexture = TextureManager.GetTexture(PieceType::Knight, colour);
    pieces.push_back(new Knight(sf::Vector2i(1, otherY), knightTexture));
    pieces.push_back(new Knight(sf::Vector2i(6, otherY), knightTexture));

    sf::Texture& bishopTexture = TextureManager.GetTexture(PieceType::Bishop, colour);
    pieces.push_back(new Bishop(sf::Vector2i(2, otherY), bishopTexture));
    pieces.push_back(new Bishop(sf::Vector2i(5, otherY), bishopTexture));

    sf::Texture& queenTexture = TextureManager.GetTexture(PieceType::Queen, colour);
    pieces.push_back(new Bishop(sf::Vector2i(3, otherY), queenTexture));

    sf::Texture& kingTexture = TextureManager.GetTexture(PieceType::King, colour);
    pieces.push_back(new Bishop(sf::Vector2i(4, otherY), kingTexture));

    return pieces;
}
