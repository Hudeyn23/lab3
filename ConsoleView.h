
#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "VirusWarView.h"

class ConsoleView : public ::VirusWarView {
public:
    void syncWithModel(Board &board) override;

    void printWinMessage(Status status) override;

    void wrongTurnMessage() override;

};


#endif //LAB3_CONSOLEVIEW_H

#include "VirusWarView.h"



