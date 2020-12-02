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
    bool zeroFirstTurn = true;
    bool crossFirstTurn = true;
public:
    void startGame();

    bool isWin();

    bool isGameOver();

    void interactWithCell(int row, int column, Status status,Board& board);

    bool isTurnCorrect(std::vector<std::string> turn, Status status);

    Status getCellStatus(int row, int column) {
        return virusWarBoard.getCell(row, column).getCurrentStatus();
    }

    void updateViewers();

    void addViewer(VirusWarView *viewer);

    void makeTurns(std::vector<std::string> turn, Status status);
};


#endif //LAB3_VIRUSWARMODEL_H
