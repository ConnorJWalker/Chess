#pragma once

class Player {
public:
    Player(sf::RenderWindow& window, PieceColour colour, std::vector<Piece*> pieces);
    ~Player();

    void Draw();
    void MovePiece(int index, sf::Vector2i square);
    int FindClickedPieceIndex(sf::Vector2i mousePosition);
    std::vector<sf::Vector2i> GetPossibleMoves(int index, std::vector<Piece*> const& otherPlayersPieces);
    void TryRemovePiece(sf::Vector2i square);

    const std::vector<Piece*>& GetPieces() { return Pieces; }
private:
    sf::RenderWindow& Window;
    PieceColour Colour;
    std::vector<Piece*> Pieces;
};
