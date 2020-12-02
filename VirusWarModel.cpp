
#include <iostream>
#include "VirusWarModel.h"


bool VirusWarModel::isWin() {
    return false;
}

bool VirusWarModel::isTurnCorrect(std::vector<std::string> turn, Status status) {
    Board boardForCheckTurn = virusWarBoard;
    bool zeroFirstTurnForCheck = zeroFirstTurn;
    bool crossFirstTurnForCheck = crossFirstTurn;
    for (int i = 0; i < 3; i++) {
        int column = VirusWarUtil::getColumnByChar(turn[i].at(0));
        int row = turn[i].at(1) - '0';
        if (row >= 1 && row <= 8 && column >= 1 && column <= 8) {
            Cell currentCell = boardForCheckTurn.getCell(row - 1, column - 1);
            if (currentCell.getCurrentStatus() == EMPTY) {
                if (zeroFirstTurn && status == ZERO) {
                    zeroFirstTurnForCheck = false;
                    interactWithCell(row, column, status, boardForCheckTurn);
                    continue;
                }
                if (crossFirstTurn && status == CROSS) {
                    crossFirstTurnForCheck = false;
                    interactWithCell(row, column, status, boardForCheckTurn);
                    continue;
                }
            }
            if (currentCell.getCurrentStatus() == DEAD_CROSS || currentCell.getCurrentStatus() == DEAD_ZERO ||
                currentCell.getCurrentStatus() == status) {
                return false;
            }
            bool isChecked[8][8] = {false};
            if (boardForCheckTurn.isTherePathToSimilarCell(row - 1, column - 1, status, isChecked)) {
                interactWithCell(row, column, status, boardForCheckTurn);
            } else {
                return false;
            }
        }
    }
    return true;
}

void VirusWarModel::addViewer(VirusWarView *viewer) {
    viewers.push_back(viewer);
}

void VirusWarModel::updateViewers() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->syncWithModel(virusWarBoard);
        it++;
    }
}

void VirusWarModel::interactWithCell(int row, int column, Status status, Board &board) {
    Cell &currentCell = board.getCell(row - 1, column - 1);
    if (currentCell.getCurrentStatus() == EMPTY) {
        currentCell.ChangeCellStatus(status);
    } else {
        currentCell.ChangeCellStatus(VirusWarUtil::getDeadStatusOfEnemy(status));
    }
}

void VirusWarModel::makeTurns(std::vector<std::string> turn, Status status) {
    Board boardBeforeTurns = virusWarBoard;
    bool oldZeroFirstTurn = zeroFirstTurn;
    bool oldCrossFirstTurn = crossFirstTurn;
    if (isTurnCorrect(turn, status)) {
        if (crossFirstTurn && status == CROSS) {
            crossFirstTurn = false;
        }
        if (zeroFirstTurn && status == ZERO) {
            zeroFirstTurn = false;
        }
        for (int i = 0; i < 3; i++) {
            int column = VirusWarUtil::getColumnByChar(turn[i].at(0));
            int row = turn[i].at(1) - '0';
            this->interactWithCell(row, column, status, virusWarBoard);
        }
    } else {
        throw VirusWarModelException("invalid turn");
    }
    updateViewers();
}

bool VirusWarModel::isGameOver() {
    return false;
}

