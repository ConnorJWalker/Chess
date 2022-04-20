#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "../Pieces/Piece.h"

namespace plh {
    void FindClosestDistancesStraight(
            int& longestUp, int& longestDown, int& longestLeft, int& longestRight,
            std::vector<Piece*> const& pieces,
            sf::Vector2i currentLocation,
            bool isOwnPiece)
    {
        for (Piece* piece : pieces) {
            sf::Vector2i otherLocation = piece->GetLocation();
            // Prevent piece checking against itself
            if (otherLocation == currentLocation && isOwnPiece) {
                continue;
            }

            // Handle vertical piece detection
            if (otherLocation.x == currentLocation.x) {
                // Other piece is above
                if (otherLocation.y < currentLocation.y) {
                    int distance = currentLocation.y - otherLocation.y;
                    longestUp = std::min(longestUp, isOwnPiece ? distance : distance + 1);
                }
                    // Other piece is below
                else {
                    int distance =  otherLocation.y - currentLocation.y;
                    longestDown = std::min(longestDown, isOwnPiece ? distance : distance + 1);
                }
            }
                // Handle horizontal piece detection
            else if (otherLocation.y == currentLocation.y) {
                // Other piece is left
                if (otherLocation.x < currentLocation.x) {
                    int distance = currentLocation.x - otherLocation.x;
                    longestLeft = std::min(longestLeft, isOwnPiece ? distance : distance + 1);
                }
                    // Other piece is right
                else {
                    int distance = otherLocation.x - currentLocation.x;
                    longestRight = std::min(longestRight, isOwnPiece ? distance : distance + 1);
                }
            }
        }
    }

    void FindClosestDistancesDiagonal(
            int& northEast, int& southEast, int& southWest, int& northWest,
            std::vector<Piece*> const& pieces,
            sf::Vector2i currentLocation,
            bool isOwnPiece)
    {
        for (Piece* piece : pieces) {
            sf::Vector2i otherLocation = piece->GetLocation();
            // Prevent piece from checking itself
            if (otherLocation == currentLocation && isOwnPiece) {
                continue;
            }

            int differenceX = std::abs(otherLocation.x - currentLocation.x);
            int differenceY = std::abs(otherLocation.y - currentLocation.y);

            // Skip over pieces that are not diagonal
            if (differenceX != differenceY) {
                continue;
            }

            // Handle eastern pieces
            if (otherLocation.x > currentLocation.x) {
                // Handle northeast pieces
                if (otherLocation.y < currentLocation.y) {
                    northEast = std::min(northEast, isOwnPiece ? differenceX : differenceX + 1);
                }
                    // Handle southeast pieces
                else if (otherLocation.y > currentLocation.y) {
                    southEast = std::min(southEast, isOwnPiece ? differenceX : differenceX + 1);
                }
            }
                // Handle western pieces
            else if (otherLocation.x < currentLocation.x) {
                // Handle northwest pieces
                if (otherLocation.y < currentLocation.y) {
                    northWest = std::min(northWest, isOwnPiece ? differenceX : differenceX + 1);
                }
                    // Handle southwest pieces
                else if (otherLocation.y > currentLocation.y) {
                    southWest = std::min(southWest, isOwnPiece ? differenceX : differenceX + 1);
                }
            }
        }
    }

    std::vector<sf::Vector2i> GetPossibleMovesStraight(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other,
            sf::Vector2i location)
    {
        std::vector<sf::Vector2i> possibleMoves;
        // Set initial values to the longest possible so real values will always start smaller
        int longestUp = 8, longestDown = 8, longestLeft = 8, longestRight = 8;
        FindClosestDistancesStraight(longestUp, longestDown, longestLeft, longestRight, currentPlayer, location,true);
        FindClosestDistancesStraight(longestUp, longestDown, longestLeft, longestRight, other, location, false);

        // Start at 1 to prevent seeing current position as possible move
        for (int i = 1; i < 8; i++) {
            if (longestUp > i && location.y - i >= 0) {
                possibleMoves.emplace_back(sf::Vector2i(location.x, location.y - i));
            }

            if (longestDown > i && location.y + i < 8) {
                possibleMoves.emplace_back(sf::Vector2i(location.x, location.y + i));
            }

            if (longestLeft > i && location.x - i >= 0) {
                possibleMoves.emplace_back(sf::Vector2i(location.x - i, location.y));
            }

            if (longestRight > i && location.x + i < 8) {
                possibleMoves.emplace_back(sf::Vector2i(location.x + i, location.y));
            }
        }

        return possibleMoves;
    }

    std::vector<sf::Vector2i> GetPossibleMovesDiagonal(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other,
            sf::Vector2i location)
    {
        std::vector<sf::Vector2i> possibleMoves;

        // Set initial values to the longest possible so real values will always start smaller
        int northEast = 8, southEast = 8, southWest = 8, northWest = 8;
        FindClosestDistancesDiagonal(northEast, southEast, southWest, northWest, currentPlayer, location, true);
        FindClosestDistancesDiagonal(northEast, southEast, southWest, northWest, other, location, false);

        // Start at 1 to prevent seeing current position as possible move
        // TODO: add checks that the possible location is on the board
        for (int i = 1; i < 8; i++) {
            if (northEast > i) {
                possibleMoves.emplace_back(location.x + i, location.y - i);
            }

            if (southEast > i) {
                possibleMoves.emplace_back(location.x + i, location.y + i);
            }

            if (southWest > i) {
                possibleMoves.emplace_back(location.x - i, location.y + i);
            }

            if (northWest > i) {
                possibleMoves.emplace_back(location.x - i, location.y - i);
            }
        }

        return possibleMoves;
    }
}
