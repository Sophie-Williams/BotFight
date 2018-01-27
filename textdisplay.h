#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include <string>


class TextDisplay: public Observer {
    int size, p1Points, p2Points, p1Hp, p2Hp;
    std::vector<std::vector<char>> theDisplay;
    std::vector<std::pair<std::string, int>> gameInfo;
public:
	TextDisplay(int size);
    void notify(Subject &whoFrom) override;
   	void print();
};
#endif
