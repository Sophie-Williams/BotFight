#include "board.h"
#include <cstdlib>
#include <vector>
#include "subject.h"
#include "options.h"
using namespace std;


void Board::clearCell(int x, int y){
	c[x][y].e = Effect::none;
}

Board::Board(int size): size{size}{
    for (int i = 0; i < size; ++i){
		vector <Cell> v;
		for (int j = 0; j < size; ++j){
			Cell a;
            int x = rand() % 17;
			if (x >= 0 && x <=2){
				a.e = Effect::losePoints;
			} else if (x >= 2 && x <= 4){
				a.e = Effect::gainPoints;
			} else if (x == 4){
				a.e = Effect::gainHp;
			} else if (x >=5 && x <= 7) {
				a.e = Effect::loseHp;
			} else {
				a.e = Effect::none;
			}
			x = rand() % 50 + 1;
			a.val = x;
			v.emplace_back(a);
		}
		c.emplace_back(v);
	}
}


void Board::init(){
    State s = State();
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (c[i][j].e != Effect::none){
                s.x = i;
                s.y = j;
                s.a = Action::addItems;
                setState(s);
                notifyObservers();
            }
        }
    }
}

Cell Board::getCell(int x, int y){
	return c[x][y];
}

void Board::notify(Subject &whoFrom){
	if (whoFrom.getState().e == Effect::none) return;
	c[whoFrom.getState().x][whoFrom.getState().y].e = Effect::none;
}

int Board::getSize(){
	return size;
}
