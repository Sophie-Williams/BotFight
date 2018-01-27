#include "subject.h"

void Subject::setState(State s){
	this->s = s;
}

void Subject::attach(const std::shared_ptr<Observer> &o){
	observers.emplace_back(o);
}
void Subject::notifyObservers(){
	for (auto &ob : observers){
		ob->notify(*this);
	}
}
State Subject::getState() const{
	return s;
}
