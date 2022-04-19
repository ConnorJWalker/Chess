#pragma once

class Piece {
public:
    Piece(sf::Vector2i location, sf::Texture& texture) : Body(sf::Vector2f(60.f, 60.f)) {
        Body.setOrigin(Body.getSize().x / 2, Body.getSize().y / 2);
        Body.setTexture(&texture);
        Body.setPosition((location.x * 100.f) + 50.f, (location.y * 100.f) + 50.f);
    }

    virtual ~Piece() = default;
    virtual std::vector<sf::Vector2i> GetPossibleMoves() = 0;

    void Draw(sf::RenderWindow& window) {
        window.draw(Body);
    }

private:
    sf::RectangleShape Body;
};