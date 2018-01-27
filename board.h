#ifndef BOARD_H
#define BOARD_H
#include "options.h"
#include "observer.h"
#include <vector>

#include "subject.h"


class Board : public Subject, public Observer{
    std::vector<std::vector<Cell>> c;
	int size;
public:
    void notify(Subject &whoFrom) override;
	Board(int size);
	void clearCell(int x, int y);
	int getSize();
	Cell getCell(int x, int y);
    void init();
	
};

#endif
