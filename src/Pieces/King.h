#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"

class King : public Piece {
public:
    King(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            [[maybe_unused]] std::vector<Piece*> const& other) override
    {
        std::vector<sf::Vector2i> possibleMoves;

        for (int y = -1; y < 2; y++) {
            for (int x = -1; x < 2; x++) {
                // This piece is the kings current location so should be skipped
                if (x == 0 && y == 0) {
                    continue;
                }

                possibleMoves.emplace_back(sf::Vector2i(Location.x + x, Location.y + y));
            }
        }

        // Remove values where friendly pieces are located
        for (Piece* piece : currentPlayer) {
            auto position = std::find(possibleMoves.begin(), possibleMoves.end(), piece->GetLocation());
            if (position != possibleMoves.end()) {
                possibleMoves.erase(position);
            }
        }

        return possibleMoves;
    }
};