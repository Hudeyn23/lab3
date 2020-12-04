#include "ConsoleView.h"

void ConsoleView::syncWithModel(Board &board) {
    system("CLS");
    for (int k = 0; k < 8; k++) {
        std::cout << "  " << char('a' + k);
    }
    std::cout << std::endl;
    for (int k = 0; k < 8; k++) {
        std::cout << "  " << '_';
    }
    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; j++) {
            std::cout << VirusWarUtil::getCharByStatus(board.getCell(i, j).getCurrentStatus()) << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ConsoleView::printWinMessage(Status status) {
    if (status == CROSS) {
        std::cout << "ZERO win";
    } else {
        std::cout << "CROSS win";
    }
}

void ConsoleView::wrongTurnMessage() {
    std::cout << "Wrong turn.Try again" << std::endl;
}
