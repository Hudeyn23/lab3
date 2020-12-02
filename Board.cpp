#include "Board.h"

bool Board::isThereSimilarCellAround(int row, int column, Status status) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (row + i > -1 && row + i < 8 && column + j > -1 && column + j < 8) {
                if (getCell(row + i, column + j).getCurrentStatus() == status) {
                    Status status1 = getCell(row + i, column + j).getCurrentStatus();
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::isTherePathToSimilarCell(int row, int column, Status status, bool (&isChecked)[8][8]) {
    if (isThereSimilarCellAround(row, column, status)) {
        return true;
    }
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (row + i > -1 && row + i < 8 && column + j > -1 && column + j < 8) {
                if (!isChecked[i][j] &&
                    getCell(row + i, column + j).getCurrentStatus() ==
                    VirusWarUtil::getDeadStatusOfEnemy(status)) {
                    return isTherePathToSimilarCell(row + i, column + j, status, isChecked);
                }
            }
        }
    }
    return false;
}
