#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture), StartLocation(location) {
        MovementDirection = StartLocation.y == 6 ? -1 : 1;
    }

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override
    {
        // TODO: check for en passant
        std::vector<sf::Vector2i> possibleMoves;

        bool isPieceInFront = false, isPiece2Ahead = false;
        CheckSpacesAhead(isPieceInFront, isPiece2Ahead, other);
        CheckSpacesAhead(isPieceInFront, isPiece2Ahead, currentPlayer);
        if (!isPieceInFront) {
            possibleMoves.emplace_back(Location.x, Location.y + MovementDirection);
        }
        if (!isPiece2Ahead && Location == StartLocation) {
            possibleMoves.emplace_back(Location.x, Location.y + MovementDirection * 2);
        }

        bool fromLowerX = false, fromHigherX = false;
        CheckIfCanTakePiece(fromLowerX, fromHigherX, other);
        if (fromLowerX) {
            sf::Vector2i possibleMove(Location.x - 1, Location.y + MovementDirection);
            possibleMoves.emplace_back(possibleMove);
        }
        if (fromHigherX) {
            sf::Vector2i possibleMove(Location.x + 1, Location.y + MovementDirection);
            possibleMoves.emplace_back(possibleMove);
        }

        return possibleMoves;
    }

private:
    sf::Vector2i StartLocation;
    int MovementDirection;

    void CheckSpacesAhead(bool& isPieceInFront, bool& isPiece2Ahead, std::vector<Piece*> const& pieces) {
        for (Piece* piece : pieces) {
            if (piece->GetLocation().y == Location.y + MovementDirection && piece->GetLocation().x == Location.x) {
                isPieceInFront = true;
            }
            else if (piece->GetLocation().y == Location.y + MovementDirection * 2 && piece->GetLocation().x == Location.x) {
                isPiece2Ahead = true;
            }
        }
    }

    void CheckIfCanTakePiece(bool& fromLowerX, bool& fromHigherX, std::vector<Piece*> const& pieces) {
        for (Piece* piece : pieces) {
            if (piece->GetLocation() == sf::Vector2i(Location.x - 1, Location.y + MovementDirection)) {
                fromLowerX = true;
            }
            else if (piece->GetLocation() == sf::Vector2i(Location.x + 1, Location.y + MovementDirection))  {
                fromHigherX = true;
            }
        }
    }
};