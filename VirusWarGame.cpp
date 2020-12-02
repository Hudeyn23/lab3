#include "VirusWarGame.h"
#include "ConsoleView.h"
#include "Human.h"
#include "Bot.h"

void VirusWarGame::start() {
    VirusWarModel model;
    ConsoleView view;
    model.addViewer(&view);
    VirusWarController controller(model);
    view.printStartMessage();
    std::cout << "Print number of players";
    int numberOfPlayers;
    std::cin >> numberOfPlayers;
    if (numberOfPlayers == 1) {
        Human firstPlayer("Nikita", ZERO);
        Bot secondPlayer("Bot", CROSS);
        while (!model.isGameOver()) {
            loop1:
            try {
                std::string turns = firstPlayer.makeTurn(model);
                controller.handleTurn(turns, firstPlayer.getStatus(), &firstPlayer);
            }
            catch (VirusWarModelException &a) {
                std::cerr << a.what();
                goto loop1;
            }
            if (!model.isGameOver()) {
                loop2:
                try {
                    std::string turns = secondPlayer.makeTurn(model);
                    controller.handleTurn(turns, secondPlayer.getStatus(), &secondPlayer);
                }
                catch (VirusWarModelException &a) {
                    std::cerr << a.what();
                    goto loop2;
                }
            }
        }
    } else if (numberOfPlayers == 2) {
        Human firstPlayer("Nikita", ZERO);
        Human secondPlayer("2", CROSS);
        while (!model.isGameOver()) {
            loop3:
            try {
                std::string turns = firstPlayer.makeTurn(model);
                controller.handleTurn(turns, firstPlayer.getStatus(), &firstPlayer);
            }
            catch (VirusWarModelException &a) {
                std::cerr << a.what();
                goto loop3;
            }
            if (!model.isGameOver()) {
                loop4:
                try {
                    std::string turns = secondPlayer.makeTurn(model);
                    controller.handleTurn(turns, secondPlayer.getStatus(), &secondPlayer);
                }
                catch (VirusWarModelException &a) {
                    std::cerr << a.what();
                    goto loop4;
                }
            }
        }
    } else {
        std::cerr << "Wrong number of players";
    }

}


