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
    Board() {
        for (int i = 0; i < 8; i++) {
            std::vector<Cell> vector;
            board.push_back(vector);
            for (int j = 0; j < 8; j++) {
                Cell cell;
                board[i].push_back(cell);
            }
        }
        freeCell = 0;
    }

    void ChangeCellStatus(Status status, int row, int column) {
        board[row][column].ChangeCellStatus(status);

    }

    Cell &getCell(int row, int column) {
        return board[row][column];

    }
    bool isThereSimilarCellAround(int row, int column, Status status);

    bool isTherePathToSimilarCell(int row, int column, Status status, bool (&isChecked)[8][8]);
};

#endif //LAB3_BOARD_H
