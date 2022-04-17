#pragma once

class Board {
public:
    explicit Board(sf::RenderWindow& window);
    void Draw();

private:
    sf::RenderWindow& Window;
};

