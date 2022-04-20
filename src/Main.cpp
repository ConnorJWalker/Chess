#include <iostream>

#include "Game.h"
#include "Enums/GameMode.h"

std::string getName(int playerNumber = 0) {
    std::string name;

    if (playerNumber == 0) {
        std::cout << "Enter your name: ";
    }
    else {
        std::cout << "Enter player " << playerNumber << "'s name: ";
    }

    std::getline(std::cin, name);

    return name;
}

GameMode getGameMode() {
    std::cout << "What would you like to do? \n";
    std::cout << "\t1: Play locally \n";
    std::cout << "\t2: Host private game \n";
    std::cout << "\t3: Join private game \n";
    std::cout << "\t4: Join random game \n";
    std::cout << "\t5: Quit" << std::endl;

    int answer;
    bool validInputGiven = false;
    while (!validInputGiven) {
        try {
            std::string input;
            std::getline(std::cin, input);
            answer = std::stoi(input);

            if (answer > 0 && answer < 6) {
                validInputGiven = true;
            }
        }
        catch (std::invalid_argument&) { /* Ignore */ }
    }

    return static_cast<GameMode>(answer - 1);
}

int main()
{
    Game game;

    // TODO: create ui to display user data
    // TODO: create socket connection/server for multiplayer
    switch (getGameMode()) {
        case GameMode::Local: {
            std::string player1Name = getName(1);
            std::string player2Name = getName(2);
            std::cout << player1Name << " " << player2Name << std::endl;
            break;
        }
        case GameMode::HostPrivate: {
            std::string playerName = getName();
            std::cout << playerName << std::endl;
            break;
        }
        case GameMode::JoinPrivate: {
            std::string playerName = getName();
            std::cout << playerName << std::endl;
            break;
        }
        case GameMode::JoinRandom: {
            std::string playerName = getName();
            std::cout << playerName << std::endl;
            break;
        }
        case GameMode::Quit:
            std::cout << "Exiting game" << std::endl;
            return 0;
    }

    game.Start();

    return 0;
}
