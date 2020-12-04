#ifndef LAB3_BOARD_H
#define LAB3_BOARD_H

#include <memory>
#include "Cell.h"
#include <vector>
#include "VirusWarUtil.h"

class Board {
private:
    std::vector<std::vector<Cell>> board;
    int freeCell;

public:
    Board();

    void ChangeCellStatus(Status status, int row, int column);

    Cell &getCell(int row, int column);

    bool isThereSimilarCellAround(int row, int column, Status status);

    bool isTherePathToSimilarCell(int row, int column, Status status, bool (&isChecked)[8][8]);
};

#endif //LAB3_BOARD_H
