#pragma once
#include "../PieceType.h"

class TextureManager {
public:
    TextureManager();

    sf::Texture& GetTexture(PieceType type, bool isWhite);

private:
    bool LoadTextures();

    std::map<PieceType, sf::Texture> WhiteTextures;
    std::map<PieceType, sf::Texture> BlackTextures;
};
