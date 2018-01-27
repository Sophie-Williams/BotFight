#ifndef BOT_H
#define BOT_H
#include "subject.h"
#include "observer.h"


struct BotInfo{
    int x, y, points, hp, botName;
	BotInfo(int x, int y, int points, int hp, int botName): 
	x{x}, y{y}, points{points}, hp{hp}, botName{botName}{}
};

class Bot : public Subject, public Observer{
	int x, y, points, hp, botName;
public:
    Bot(int botName);
    void init();
	void updateLocation(int x, int y);
	void updatePoints(int points);
	void updateHp(int hp);
	void notify(Subject &whoFrom);
	BotInfo getInfo();
	void useItem(Cell c);
};

#endif
