
#ifndef LAB3_VIRUSWARUTIL_H
#define LAB3_VIRUSWARUTIL_H

#include <stdexcept>
#include <vector>
#include <sstream>
#include "Cell.h"

namespace VirusWarUtil {
    static Status getDeadStatusOfEnemy(const Status &status) {
        if (status == ZERO) {
            return DEAD_CROSS;
        }
        if (status == CROSS) {
            return DEAD_ZERO;
        }
        throw std::invalid_argument("wrong status");
    }

    static char getCharByStatus(Status status) {
        if (status == EMPTY) {
            return ' ';
        }
        if (status == ZERO) {
            return 'O';
        }
        if (status == CROSS) {
            return 'X';
        }
        if (status == DEAD_CROSS) {
            return '*';
        }
        if (status == DEAD_ZERO) {
            return '+';
        }
        throw std::invalid_argument("haha");
    }

    static int getColumnByChar(char symbol) {
        return symbol - 96;
    }

    static Status getOpositeStatus(Status status) {
        if (status == CROSS) {
            return ZERO;
        }
        if (status == ZERO) {
            return CROSS;
        }
        throw std::invalid_argument("haha");
    }

    static std::vector<std::string> split(const std::string &s, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

};


#endif //LAB3_VIRUSWARUTIL_H
