#include "Board.h"

Board::Board() {
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

void Board::ChangeCellStatus(Status status, int row, int column) {
    board[row][column].ChangeCellStatus(status);

}

Cell &Board::getCell(int row, int column) {
    return board[row][column];

}

bool Board::isThereSimilarCellAround(int row, int column, Status status) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (row + i > -1 && row + i < 8 && column + j > -1 && column + j < 8) {
                if (getCell(row + i, column + j).getCurrentStatus() == status) {
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
