#include <SFML/Graphics.hpp>

#include "Board.h"

Board::Board(sf::RenderWindow& window) : Window(window) {}

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

