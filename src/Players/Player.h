#pragma once

class Player {
public:
    Player(sf::RenderWindow& window, PieceColour colour, std::vector<Piece*> pieces);
    ~Player();

    void Draw();
    void HandleClickEvent(sf::Event event, std::vector<Piece*> const& otherPlayersPieces);
    const std::vector<Piece*>& GetPieces() {
        return Pieces;
    }
private:
    sf::RenderWindow& Window;
    PieceColour Colour;
    std::vector<Piece*> Pieces;
};
