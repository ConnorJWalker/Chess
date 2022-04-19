#pragma once

class Player {
public:
    Player(sf::RenderWindow& window, PieceColour colour, std::vector<Piece*> pieces);
    ~Player();

    void Draw();
    void HandleClickEvent(sf::Event event);
private:
    sf::RenderWindow& Window;
    PieceColour Colour;
    std::vector<Piece*> Pieces;
};
