#include <utility>
#include <iostream>

#include "UI.h"

UI::UI(sf::RenderWindow& window, std::string player1Name, std::string player2Name, bool isLocalGame)
    : Window(window), Player1Name(std::move(player1Name)), Player2Name(std::move(player2Name)), IsLocalGame(isLocalGame)
{
    if (!Font.loadFromFile("../assets/Raleway-Regular.ttf")) {
        std::cerr << "Could not load font file" << std::endl;
        return;
    }

    Player1Label.setFont(Font);
    Player1Label.setString(Player1Name);
    Player1Label.setCharacterSize(24);
    Player1Label.setPosition(sf::Vector2f(820.f, 770.f));

    Player2Label.setFont(Font);
    Player2Label.setString(Player2Name);
    Player2Label.setCharacterSize(24);
    Player2Label.setPosition(sf::Vector2f(820.f, 0.f));
}

void UI::Draw() {
    Window.draw(Player1Label);
    Window.draw(Player2Label);
}
