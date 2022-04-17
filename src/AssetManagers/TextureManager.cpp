#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"

TextureManager::TextureManager() {
    LoadTextures();
}

sf::Texture& TextureManager::GetTexture(PieceType type, bool isWhite) {
    return isWhite ? WhiteTextures[type] : BlackTextures[type];
}

bool TextureManager::LoadTextures() {
    sf::Image spriteSheet;
    if (!spriteSheet.loadFromFile("../assets/ChessPiecesArray.png")) {
        std::cerr << "Could not load pieces sprite sheet" << std::endl;
        return false;
    }

    bool isWhite = false;
    std::vector<PieceType> types = {
        PieceType::Queen, PieceType::King, PieceType::Castle, PieceType::Knight, PieceType::Bishop, PieceType::Pawn
    };

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 6; x++) {
            sf::Texture texture;
            sf::Vector2i location(x * 60, y * 60);
            sf::Vector2i size(60, 60);
            texture.loadFromImage(spriteSheet, sf::IntRect(location, size));

            if (isWhite) {
                WhiteTextures[types[x]] = texture;
                continue;
            }

            BlackTextures[types[x]] = texture;
        }

        isWhite = !isWhite;
    }

    return true;
}
