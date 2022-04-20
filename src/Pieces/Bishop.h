#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override
    {
        std::vector<sf::Vector2i> possibleMoves;

        // Set initial values to the longest possible so real values will always start smaller
        int northEast = 8, southEast = 8, southWest = 8, northWest = 8;
        FindClosestDistances(northEast, southEast, southWest, northWest, currentPlayer, true);
        FindClosestDistances(northEast, southEast, southWest, northWest, other, false);

        // TODO: add checks that the possible location is on the board
        for (int i = 1; i < 8; i++) {
            if (northEast > i) {
                possibleMoves.emplace_back(Location.x + i, Location.y - i);
            }

            if (southEast > i) {
                possibleMoves.emplace_back(Location.x + i, Location.y + i);
            }

            if (southWest > i) {
                possibleMoves.emplace_back(Location.x - i, Location.y + i);
            }

            if (northWest > i) {
                possibleMoves.emplace_back(Location.x - i, Location.y - i);
            }
        }

        return possibleMoves;
    }

    void FindClosestDistances(
            int& northEast, int& southEast, int& southWest, int& northWest,
            std::vector<Piece*> const& pieces,
            bool isOwnPiece)
    {
        for (Piece* piece : pieces) {
            sf::Vector2i otherLocation = piece->GetLocation();
            // Prevent piece from checking itself
            if (otherLocation == Location && isOwnPiece) {
                continue;
            }

            int differenceX = std::abs(otherLocation.x - Location.x);
            int differenceY = std::abs(otherLocation.y - Location.y);

            // Skip over pieces that are not diagonal
            if (differenceX != differenceY) {
                continue;
            }

            // Handle eastern pieces
            if (otherLocation.x > Location.x) {
                // Handle northeast pieces
                if (otherLocation.y < Location.y) {
                    northEast = std::min(northEast, isOwnPiece ? differenceX : differenceX + 1);
                }
                // Handle southeast pieces
                else if (otherLocation.y > Location.y) {
                    southEast = std::min(southEast, isOwnPiece ? differenceX : differenceX + 1);
                }
            }
            // Handle western pieces
            else if (otherLocation.x < Location.x) {
                // Handle northwest pieces
                if (otherLocation.y < Location.y) {
                    northWest = std::min(northWest, isOwnPiece ? differenceX : differenceX + 1);
                }
                // Handle southwest pieces
                else if (otherLocation.y > Location.y) {
                    southWest = std::min(southWest, isOwnPiece ? differenceX : differenceX + 1);
                }
            }
        }
    }
};