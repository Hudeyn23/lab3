#ifndef LAB3_VIRUSWARVIEW_H
#define LAB3_VIRUSWARVIEW_H

#include "VirusWarUtil.h"
#include <iostream>
#include "Board.h"

class VirusWarView {
public:

    virtual void syncWithModel(Board &board) = 0;

    virtual void printWinMessage(Status status) = 0;

    virtual void wrongTurnMessage() = 0;

};


#endif //LAB3_VIRUSWARVIEW_H
