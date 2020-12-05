#include "VirusWarGame.h"
#include "ConsoleView.h"
#include "Human.h"
#include "Bot.h"
#include <conio.h>

void VirusWarGame::start() {
    VirusWarModel model;
    ConsoleView view;
    model.addViewer(&view);
    VirusWarController controller(model);
    std::cout << "Hello it`s Virus War game.There are a Board 8x8" << std::endl;
    int numberOfPlayers = 0;
    std::cout << "Print number of players";
    std::cin >> numberOfPlayers;
    while (numberOfPlayers != 2 && numberOfPlayers != 1) {
        std::cerr << "Wrong number of players" << std::endl;
        std::cout << "Print number of players" << std::endl;
        std::cin >> numberOfPlayers;
    }
    Player *firstPlayer;
    Player *secondPlayer;
    if (numberOfPlayers == 1) {
        std::string name;
        std::cout << "Print first player name" << std::endl;
        std::cin >> name;
        firstPlayer = new Human(name, CROSS);
        secondPlayer = new Bot(ZERO);
    }
    if (numberOfPlayers == 2) {
        std::string name;
        std::cout << "Print first player name" << std::endl;
        std::cin >> name;
        firstPlayer = new Human(name, CROSS);
        std::cout << "Print second player name" << std::endl;
        std::cin >> name;
        secondPlayer = new Human(name, ZERO);
    }
    controller.addPlayer(firstPlayer);
    controller.addPlayer(secondPlayer);
    while (!model.isGameOver()) {
        bool turnComplete = false;
        while (!turnComplete) {
            try {
                controller.handleTurn();
            }
            catch (const VirusWarModelException &a) {
                continue;
            }
            catch (const std::invalid_argument &a) {
                continue;
            }
            turnComplete = true;
        }
    }
    delete firstPlayer;
    delete secondPlayer;
    model.notifyAboutWin();
    _getch();
}




