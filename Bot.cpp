
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
                                for (int i = 0; i < 8; i++) {
                                    stringTurn = stringTurn + turn[i];
                                }

                                auto vector = VirusWarUtil::split(stringTurn, '-');
                                if (model.isTurnCorrect(vector, status)) {
                                    return stringTurn;
                                }
                            }
                        }
                    }
                }
        }
    }
    return "wo";
}


Bot::Bot(std::string name, Status status) {
    this->name = name;
    this->status = status;
}

Status Bot::getStatus() {
    return status;
}
