#ifndef LAB3_VIRUSWARCONTROLLER_H
#define LAB3_VIRUSWARCONTROLLER_H

#include "VirusWarModel.h"
#include "VirusWarView.h"
#include "VirusWarUtil.h"
#include <string>
#include "Player.h"
#include <map>
class VirusWarController {
public:
    explicit VirusWarController(VirusWarModel &model);

    void handleTurn();

    void addPlayer(Player *player);

private:
    VirusWarModel &model;
    std::map<Status ,Player*> players;

    bool checkTurnFormat(std::vector<std::string> turns);

    Player *currentPlayer();
};


#endif //LAB3_VIRUSWARCONTROLLER_H
