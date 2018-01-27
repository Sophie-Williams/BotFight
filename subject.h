#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include <iostream>
#include "options.h"
#include "observer.h"
struct State {
	Direction d;
	Effect e;
	Player p;
    int x, y, damage, newX, newY, points, hp, botName;
	Action a;
	State(): d{Direction::none}, e{Effect::none}, 
    p{Player::none}, x{0}, y{0}, damage{0},newX{0}, newY{0}, points{0}, hp{0}, botName{0}, a{Action::none}{}
};

class Subject{
	std::vector <std::shared_ptr<Observer>> observers;
	State s;
protected:
	void setState(State s);
public:
	void attach(const std::shared_ptr<Observer> &o);
    void notifyObservers();
    State getState() const;
    virtual ~Subject() = default;
};

#endif
