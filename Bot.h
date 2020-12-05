#include "Player.h"

#ifndef LAB3_BOT_H
#define LAB3_BOT_H


class Bot : public ::Player {
public:
    Status status;

    Bot(Status status);

    std::string makeTurn(VirusWarModel &model) override;

    virtual ~Bot();
};


#endif //LAB3_BOT_H
