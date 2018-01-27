#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <memory>
#include "options.h"
#include "bot.h"
#include "board.h"
#include "textdisplay.h"

class GameController {
	std::shared_ptr<Board> b;
	std::shared_ptr<Bot> p1;
	std::shared_ptr<Bot> p2;
	std::shared_ptr<TextDisplay> td;
	Player winner;
public:
	GameController(int size);
	void move(Direction d, Player t);
	bool validMove(Direction d, Player t);
	void useItem();
	bool gameOver(int time);
	void displayWinner();
	void print();
};

#endif
