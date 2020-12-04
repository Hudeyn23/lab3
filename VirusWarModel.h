#ifndef LAB3_VIRUSWARMODEL_H
#define LAB3_VIRUSWARMODEL_H

#include "Board.h"
#include "VirusWarModelException.h"
#include "VirusWarUtil.h"
#include "VirusWarView.h"


class VirusWarModel {
private:
    Board virusWarBoard;
    std::vector<VirusWarView *> viewers;
    Status currentTurn = CROSS;
    bool zeroFirstTurn = true;
    bool crossFirstTurn = true;
public:

    bool isWin();

    bool isGameOver();

    void interactWithCell(int row, int column, Board &board);

    bool isTurnCorrect(const std::vector<std::string> &turn);

    Status getCellStatus(int row, int column) {
        return virusWarBoard.getCell(row, column).getCurrentStatus();
    }

    void updateViewers();

    void notifyAboutWrongTurn();

    void notifyAboutWin();

    void addViewer(VirusWarView *viewer);

    void makeTurns(const std::vector<std::string> &turn);
};


#endif //LAB3_VIRUSWARMODEL_H
