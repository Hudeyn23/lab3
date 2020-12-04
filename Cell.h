#ifndef LAB3_CELL_H
#define LAB3_CELL_H
enum Status {
    CROSS,
    ZERO,
    DEAD_CROSS,
    DEAD_ZERO,
    EMPTY
};

class Cell {
    Status cellStatus;
public:
    Cell() {
        cellStatus = EMPTY;
    }

    void ChangeCellStatus(Status newStatus) {
        cellStatus = newStatus;
    }

    Status getCurrentStatus() {
        return cellStatus;
    }


};


#endif //LAB3_CELL_H
