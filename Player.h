

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include <string>
#include "Cell.h"
#include "VirusWarModel.h"

class Player {
public:
    virtual std::string makeTurn(VirusWarModel &model) = 0;


    virtual ~Player() = default;
};

#endif //LAB3_PLAYER_H
