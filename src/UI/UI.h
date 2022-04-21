#pragma once
#include <SFML/Graphics.hpp>

class UI {
public:
    UI(sf::RenderWindow& window, std::string player1Name, std::string player2Name, bool isLocalGame);
    void Draw();

private:
    sf::Font Font;
    sf::RenderWindow& Window;

    sf::Text Player1Label, Player2Label;

    bool IsLocalGame;
    std::string Player1Name;
    std::string Player2Name;
};
