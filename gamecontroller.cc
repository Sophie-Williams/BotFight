#include "gamecontroller.h"
#include <cstdlib>
#include "options.h"
using namespace std;

GameController::GameController(int size): b{make_shared<Board>(size)},
p1{make_shared<Bot>(1)},p2{make_shared<Bot>(2)}, td{make_shared<TextDisplay>(size)}{
    b->attach(td);
    b->init();
	p1->attach(p2);
	p1->attach(td);
	p1->attach(b);
	p2->attach(p1);
	p2->attach(td);
	p2->attach(b);
	int x = rand() % size;
	int y = rand() % size;
	p1->updateLocation(x,y);
	b->clearCell(x,y);
	x = (x + 6 < size)? x + 6 : x - 6;
	p2->updateLocation(x,y);
	b->clearCell(x,y);
    p1->init();
    p2->init();
}

void GameController::move(Direction d, Player t){
	if (t == Player::player1){
		if (d == Direction::down){
			p1->updateLocation(p1->getInfo().x + 1, p1->getInfo().y);
		} else if (d == Direction::up){
			p1->updateLocation(p1->getInfo().x - 1, p1->getInfo().y);
		} else if (d == Direction::left){
			p1->updateLocation(p1->getInfo().x, p1->getInfo().y - 1);
		} else {
			p1->updateLocation(p1->getInfo().x, p1->getInfo().y + 1);
		}
	} else {
		if (d == Direction::down){
			p2->updateLocation(p2->getInfo().x + 1, p2->getInfo().y);
		} else if (d == Direction::up){
			p2->updateLocation(p2->getInfo().x - 1, p2->getInfo().y);
		} else if (d == Direction::left){
			p2->updateLocation(p2->getInfo().x, p2->getInfo().y - 1);
		} else {
			p2->updateLocation(p2->getInfo().x, p2->getInfo().y + 1);
		}
	}
}
bool GameController::validMove(Direction d, Player t){
	if (t == Player::player1){
		if (d == Direction::down){
			return p1->getInfo().x + 1 < b->getSize();
		} else if (d == Direction::up){
			return p1->getInfo().x - 1 >= 0;
		} else if (d == Direction::left){
			return p1->getInfo().y - 1 >= 0;
		} else {
			return p1->getInfo().y + 1 < b->getSize();
		}
	} else {
		if (d == Direction::down){
			return p2->getInfo().x + 1 < b->getSize();
		} else if (d == Direction::up){
			return p2->getInfo().x - 1 >= 0;
		} else if (d == Direction::left){
			return p2->getInfo().y - 1 >= 0;
		} else {
			return p2->getInfo().y + 1 < b->getSize();
		}
	}
}
void GameController::useItem(){
	p1->useItem(b->getCell(p1->getInfo().x, p1->getInfo().y));
	p2->useItem(b->getCell(p2->getInfo().x, p2->getInfo().y));
}

bool GameController::gameOver(int time){
	if ((p1->getInfo().x == p2->getInfo().x &&
		p1->getInfo().y == p2->getInfo().y) || time <= 0){
		if (p1->getInfo().points > p2->getInfo().points){
			winner = Player::player1;
        } else  if (p1->getInfo().points < p2->getInfo().points) {
			winner = Player::player2;
        } else {
            winner = Player::draw;
        }
	} else if (p1->getInfo().hp <=0){
		winner = Player::player2;
	} else if (p2->getInfo().hp <=0){
		winner = Player::player1;
	} else {
		return false;
	}
	return true;
 
}

void GameController::displayWinner(){
	if (winner == Player::player1){
		cout<<"Player1 wins"<<endl;
    } else  if (winner == Player::player2){
		cout<<"Player2 wins"<<endl;
    } else {
        cout<<"Draw";
    }
}

void GameController::print(){
	td->print();
}
