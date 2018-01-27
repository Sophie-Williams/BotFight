#include "bot.h"

void Bot::updateLocation(int x, int y){
	State s = State();
	s.x = this->x;
	s.y = this->y;
	this->x = x;
	this->y = y;
    s.newX = this->x;
    s.newY = this->y;
	s.a = Action::moved;
    s.botName = botName;
	setState(s);
	notifyObservers();
}
void Bot::updatePoints(int points){
	this->points = points;
	State s = State();
	s.a = Action::updatePoints;
    s.points = this->points;
        s.botName = botName;
	setState(s);
	notifyObservers();
}
void Bot::updateHp(int hp){
	this->hp = hp;
    State s = State();
	s.a = Action::updateHp;
    s.hp = this->hp;
    s.botName = botName;
	setState(s);
	notifyObservers();
}

BotInfo Bot::getInfo(){
	return BotInfo(x,y,points,hp, botName);
}

Bot::Bot(int botName): x{0}, y{0}, points{0}, hp{0}, botName{botName}{}

void Bot::notify(Subject &whoFrom){
	State s = whoFrom.getState();
	if (s.e == Effect::loseHp){
		updateHp(hp - s.damage);
	} else if (s.e == Effect::losePoints){
		updatePoints(points - s.damage);
	}
}

void Bot::init(){
    updateLocation(x,y);
    updateHp(100);
    updatePoints(0);
}

void Bot::useItem(Cell c){
    State s = State();
	s.x = x;
	s.y = y;
	if (c.e == Effect::gainPoints){
		updatePoints(points + c.val);
	} else if (c.e == Effect::gainHp){
		updateHp(hp + c.val);
	} else if (c.e == Effect::losePoints){
        s.e = c.e;
		s.damage = c.val;
	} else if (c.e == Effect::loseHp){
		s.damage = c.val;
        s.e = c.e;
	} else {
		s.e = Effect::none;
	}
    setState(s);
	notifyObservers();
}
