#include "Bot.h"

std::string Bot::makeTurn(VirusWarModel &model) {
    std::string turnString;
    for (char a = 'a'; a <= 'h'; a++) {
        for (char b = '1'; b <= '8'; b++) {
            for (char c = 'a'; c <= 'h'; c++)
                for (char d = '1'; d <= '8'; d++) {
                    if (a != c || b != d) {
                        for (char e = 'a'; e <= 'h'; e++) {
                            for (char f = '1'; f <= '8'; f++) {
                                std::string stringTurn = "";
                                char turn[] = {a, b, '-', c, d, '-', e, f};
                                for (char i : turn) {
                                    stringTurn += i;
                                }

                                auto vector = VirusWarUtil::split(stringTurn, '-');
                                if (model.isTurnCorrect(vector)) {
                                    return stringTurn;
                                }
                            }
                        }
                    }
                }
        }
    }
    return "";
}


Bot::Bot(Status status) {
    this->status = status;
}


Status Bot::getStatus() {
    return status;
}

Bot::~Bot() = default;


