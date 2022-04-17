#pragma once

class Board {
public:
    Board(sf::RenderWindow* window);
    void Draw();

private:
    sf::RenderWindow* Window;
};

