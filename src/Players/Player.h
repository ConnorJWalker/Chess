#pragma once

class Player {
public:
    Player(sf::RenderWindow& window, PieceColour colour, std::vector<Piece*> pieces);
    ~Player();

    void Draw();
private:
    sf::RenderWindow& Window;
    PieceColour Colour;
    std::vector<Piece*> Pieces;
};
