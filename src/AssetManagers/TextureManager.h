#pragma once
#include "../Enums/PieceType.h"
#include "../Enums/PieceColour.h"

class TextureManager {
public:
    TextureManager();

    sf::Texture& GetTexture(PieceType type, PieceColour colour);

private:
    bool LoadTextures();

    std::map<PieceType, sf::Texture> WhiteTextures;
    std::map<PieceType, sf::Texture> BlackTextures;
};
