#ifndef LAB3_VIRUSWARCONTROLLER_H
#define LAB3_VIRUSWARCONTROLLER_H

#include "VirusWarModel.h"
#include "VirusWarView.h"
#include "VirusWarUtil.h"
#include <string>
#include "Player.h"

class VirusWarController {
public:
    explicit VirusWarController(VirusWarModel &model);

    void handleTurn();

    void addPlayer(Player *player);

private:
    unsigned int currentPlayer = 0;
    VirusWarModel &model;

    std::vector<Player *> players;

    bool checkTurnFormat(std::vector<std::string> turns);
};


#endif //LAB3_VIRUSWARCONTROLLER_H
