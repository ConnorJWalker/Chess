#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"

class Castle : public Piece {
public:
    Castle(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override
    {
        std::vector<sf::Vector2i> possibleMoves;
        // Set initial values to the longest possible so real values will always start smaller
        int longestUp = 8, longestDown = 8, longestLeft = 8, longestRight = 8;
        FindClosestDistances(longestUp, longestDown, longestLeft, longestRight, currentPlayer, true);
        FindClosestDistances(longestUp, longestDown, longestLeft, longestRight, other, false);

        for (int i = 0; i < 8; i++) {
            if (longestUp > i && Location.y - i >= 0) {
                possibleMoves.emplace_back(sf::Vector2i(Location.x, Location.y - i));
            }

            if (longestDown > i && Location.y + i < 8) {
                possibleMoves.emplace_back(sf::Vector2i(Location.x, Location.y + i));
            }

            if (longestLeft > i && Location.x - i >= 0) {
                possibleMoves.emplace_back(sf::Vector2i(Location.x - i, Location.y));
            }

            if (longestRight > i && Location.x + i < 8) {
                possibleMoves.emplace_back(sf::Vector2i(Location.x + i, Location.y));
            }
        }

        return possibleMoves;
    }

private:
    void FindClosestDistances(
            int& longestUp, int& longestDown, int& longestLeft, int& longestRight,
            std::vector<Piece*> const& pieces,
            bool isOwnPiece)
    {
        for (Piece* piece : pieces) {
            sf::Vector2i otherLocation = piece->GetLocation();
            // Prevent piece checking against itself
            if (otherLocation == Location && isOwnPiece) {
                continue;
            }

            // Handle vertical piece detection
            if (otherLocation.x == Location.x) {
                // Other piece is above
                if (otherLocation.y < Location.y) {
                    int distance = Location.y - otherLocation.y;
                    longestUp = std::min(longestUp, isOwnPiece ? distance : distance + 1);
                }
                // Other piece is below
                else {
                    int distance =  otherLocation.y - Location.y;
                    longestDown = std::min(longestDown, isOwnPiece ? distance : distance + 1);
                }
            }
            // Handle horizontal piece detection
            else if (otherLocation.y == Location.y) {
                // Other piece is left
                if (otherLocation.x < Location.x) {
                    int distance = Location.x - otherLocation.x;
                    longestLeft = std::min(longestLeft, isOwnPiece ? distance : distance + 1);
                }
                // Other piece is right
                else {
                    int distance = otherLocation.x - Location.x;
                    longestRight = std::min(longestRight, isOwnPiece ? distance : distance + 1);
                }
            }
        }
    }

};