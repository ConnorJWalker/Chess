#include <utility>
#include <iostream>
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
            sf::Color colour = isWhiteSquare ? sf::Color::White : sf::Color(110, 80, 60);

            square.setFillColor(colour);
            square.setPosition(x * 100, y * 100);

            Window.draw(square);

            isWhiteSquare = !isWhiteSquare;
        }

        isWhiteSquare = !isWhiteSquare;
    }

    // Draw possible moves
    if (!PossibleMoves.empty()) {
        for (sf::Vector2i move : PossibleMoves) {
            sf::CircleShape circle(10);
            circle.setOrigin(circle.getRadius(), circle.getRadius());
            circle.setFillColor(sf::Color(200, 100, 100, 200));
            circle.setPosition((move.x * 100.f) + 50.f, (move.y * 100.f) + 50.f);

            Window.draw(circle);
        }
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

void Board::ClearPossibleMoves() {
    PossibleMoves.clear();
}

void Board::SetPossibleMoves(std::vector<sf::Vector2i> possibleMoves) {
    PossibleMoves = std::move(possibleMoves);
}

bool Board::ClickedPossibleMove(sf::Vector2i mousePosition) {
    sf::Vector2i square = mousePosition / 100;
    return std::any_of(PossibleMoves.begin(), PossibleMoves.end(), [square](sf::Vector2i move){ return move == square; });
}
