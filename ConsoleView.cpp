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

void ConsoleView::printWinMessage() {
    std::cout << "Wrong turn.Try again";
}

void ConsoleView::wrongTurnMessage() {
    std::cout << "Wrong turn.Try again";
}

void ConsoleView::printStartMessage() {
    std::cout << "Hello it`s Virus War game.There are a Board 8x8" << std::endl;
}
