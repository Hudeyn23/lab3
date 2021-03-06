#include "Player.h"

#ifndef LAB3_HUMAN_H
#define LAB3_HUMAN_H


#include "VirusWarController.h"

class Human : public ::Player {
    std::string name;
    Status status;
public:
    virtual ~Human();

public:
    Status getStatus();
    Human(const std::string &name, Status status);

    std::string makeTurn(VirusWarModel &model) override;
};


#endif //LAB3_HUMAN_H
