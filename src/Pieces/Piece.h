#pragma once
#include <iostream>

class Piece {
public:
    Piece(sf::Vector2i location, sf::Texture& texture) : Body(sf::Vector2f(60.f, 60.f)), Location(location) {
        Body.setOrigin(Body.getSize().x / 2, Body.getSize().y / 2);
        Body.setTexture(&texture);
        Body.setPosition((location.x * 100.f) + 50.f, (location.y * 100.f) + 50.f);
    }

    virtual ~Piece() = default;
    virtual std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other
        ) = 0;

    void Draw(sf::RenderWindow& window) {
        window.draw(Body);
    }

    bool HasBeenClicked(int x, int y) {
        return Body.getGlobalBounds().contains((float)x, (float)y);
    }

    sf::Vector2i GetLocation() {
        return Location;
    }

private:
    sf::RectangleShape Body;

protected:
    sf::Vector2i Location;
};