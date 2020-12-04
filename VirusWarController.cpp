#include "VirusWarController.h"

VirusWarController::VirusWarController(VirusWarModel &model) : model(model) {}


void VirusWarController::handleTurn(std::string &str) {
    auto turns = VirusWarUtil::split(str, '-');
    if (checkTurnFormat(turns)) {
        try {
            model.makeTurns(turns);
        }
        catch (VirusWarModelException &a) {
            throw a;
        }
    } else {
        model.notifyAboutWrongTurn();
        throw std::invalid_argument("Wrong turn format");
    }
}

bool VirusWarController::checkTurnFormat(std::vector<std::string> turns) {
    if (turns.size() != 3) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        std::string a = turns[i];
        if (turns[i].size() != 2) {
            return false;
        }
        if (!(turns[i].at(0) >= 'a' && turns[i].at(0) <= 'h' && turns[i].at(1) >= '1' &&
              turns[i].at(1) <= '9')) {
            return false;
        }
    }
    return true;
}
