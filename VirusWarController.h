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

    void handleTurn(std::string &str);

private:
    VirusWarModel &model;

    bool checkTurnFormat(std::vector<std::string>);
};


#endif //LAB3_VIRUSWARCONTROLLER_H
