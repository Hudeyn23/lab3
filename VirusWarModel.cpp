
#include <iostream>
#include "VirusWarModel.h"


bool VirusWarModel::isWin() {
    return false;
}

bool VirusWarModel::isTurnCorrect(const std::vector<std::string> &turn) {
    Board boardForCheckTurn = virusWarBoard;
    bool zeroFirstTurnForCheck = zeroFirstTurn;
    bool crossFirstTurnForCheck = crossFirstTurn;
    for (int i = 0; i < 3; i++) {
        int column = VirusWarUtil::getColumnByChar(turn[i].at(0));
        int row = turn[i].at(1) - '0';
        if (row >= 1 && row <= 8 && column >= 1 && column <= 8) {
            Cell currentCell = boardForCheckTurn.getCell(row - 1, column - 1);
            if (currentCell.getCurrentStatus() == EMPTY) {
                if (zeroFirstTurnForCheck && currentTurn == ZERO) {
                    if (row == 8 && column == 8) {
                        zeroFirstTurnForCheck = false;
                        interactWithCell(row, column, boardForCheckTurn);
                        continue;
                    } else {
                        return false;
                    }
                }
                if (crossFirstTurnForCheck && currentTurn == CROSS) {
                    if (row == 1 && column == 1) {
                        crossFirstTurnForCheck = false;
                        interactWithCell(row, column, boardForCheckTurn);
                        continue;
                    } else {
                        return false;
                    }
                }
            }
            if (currentCell.getCurrentStatus() == DEAD_CROSS || currentCell.getCurrentStatus() == DEAD_ZERO ||
                currentCell.getCurrentStatus() == currentTurn) {
                return false;
            }
            bool isChecked[8][8] = {false};
            if (boardForCheckTurn.isTherePathToSimilarCell(row - 1, column - 1, currentTurn, isChecked)) {
                interactWithCell(row, column, boardForCheckTurn);
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


void VirusWarModel::notifyAboutWrongTurn() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->wrongTurnMessage();
        it++;
    }
}

void VirusWarModel::notifyAboutWin() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->printWinMessage(currentTurn);
        it++;
    }
}

void VirusWarModel::interactWithCell(int row, int column, Board &board) {
    if (board.getCell(row - 1, column - 1).getCurrentStatus() == EMPTY) {
        board.ChangeCellStatus(currentTurn, row - 1, column - 1);
    } else {
        board.ChangeCellStatus(VirusWarUtil::getDeadStatusOfEnemy(currentTurn), row - 1, column - 1);

    }
}

void VirusWarModel::makeTurns(const std::vector<std::string> &turn) {
    Board boardBeforeTurns = virusWarBoard;
    if (isTurnCorrect(turn)) {
        if (crossFirstTurn && currentTurn == CROSS) {
            crossFirstTurn = false;
        }
        if (zeroFirstTurn && currentTurn == ZERO) {
            zeroFirstTurn = false;
        }
        for (int i = 0; i < 3; i++) {
            int column = VirusWarUtil::getColumnByChar(turn[i].at(0));
            int row = turn[i].at(1) - '0';
            this->interactWithCell(row, column, virusWarBoard);
        }
    } else {
        notifyAboutWrongTurn();
        throw VirusWarModelException("invalid turn");
    }
    if (currentTurn == CROSS) {
        currentTurn = ZERO;
    } else {
        currentTurn = CROSS;
    }
    updateViewers();
}


bool VirusWarModel::isGameOver() {
    if (zeroFirstTurn || crossFirstTurn) {
        return false;
    }
    Board boardForCheckTurn = virusWarBoard;
    int possibleTurns = 0;
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            Cell currentCell = boardForCheckTurn.getCell(i, j);
            if (currentCell.getCurrentStatus() == EMPTY ||
                currentCell.getCurrentStatus() == VirusWarUtil::getOpositeStatus(currentTurn)) {
                bool isChecked[8][8] = {false};
                if (boardForCheckTurn.isTherePathToSimilarCell(i, j, currentTurn, isChecked)) {
                    possibleTurns++;
                }
                if (possibleTurns >= 3) {
                    return false;
                }
            }
        }
    }
    return true;
}


