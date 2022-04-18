#pragma once

class Piece {
public:
    Piece(sf::Vector2i location, sf::Texture& texture) : body(sf::Vector2f(60.f, 60.f)) {
        body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
        body.setTexture(&texture);
        body.setPosition((location.x * 100.f) + 50.f, (location.y * 100.f) + 50.f);
    }

    virtual ~Piece() = default;
    virtual std::vector<sf::Vector2i> GetPossibleMoves() = 0;
//protected:
    sf::RectangleShape body;
};