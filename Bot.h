#include "Player.h"

#ifndef LAB3_BOT_H
#define LAB3_BOT_H


class Bot : public ::Player {
public:
    std::string name;
    Status status;

    Bot(const std::string &name, Status status);

    Status getStatus() override;

    std::string makeTurn(VirusWarModel &model) override;
};


#endif //LAB3_BOT_H
