#include "Human.h"
#include <iostream>

std::string Human::makeTurn(VirusWarModel &model) {
    std::cout << "Waiting player " << name << " turn" << std::endl;
    std::string turn;
    std::cin >> turn;
    return turn;
}

Human::Human(const std::string &name, Status status) {
    this->name = name;
    this->status = status;
}

Human::~Human() = default;



