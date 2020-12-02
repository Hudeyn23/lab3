
#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "VirusWarView.h"

class ConsoleView: public::VirusWarView {
public:
    void syncWithModel(Board &board) override;

    void printWinMessage() override;

    void wrongTurnMessage() override;

    void printStartMessage() override;
};


#endif //LAB3_CONSOLEVIEW_H

#include "VirusWarView.h"



