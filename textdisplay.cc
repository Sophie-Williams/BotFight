#include "textdisplay.h"
#include <iostream>
#include <sstream>
using namespace std;
TextDisplay::TextDisplay(int size): size{size}, p1Points{0},p2Points{0},
p1Hp{0}, p2Hp{0} {
	for (int i = 0; i < size; ++i){
		vector<char> v;
		for(int j = 0; j < size; ++j){
			v.emplace_back(' ');
		}
		theDisplay.emplace_back(v);
	}
}

void TextDisplay::notify(Subject &whoFrom) {
    if (whoFrom.getState().a == Action::moved){
        theDisplay[whoFrom.getState().x][whoFrom.getState().y] = ' ';
        if (whoFrom.getState().botName == 1)
        theDisplay[whoFrom.getState().newX][whoFrom.getState().newY] = '1';
        else if (whoFrom.getState().botName == 2)
            theDisplay[whoFrom.getState().newX][whoFrom.getState().newY] = '2';
    } else if (whoFrom.getState().a == Action::updatePoints && whoFrom.getState().botName == 1) {
        p1Points = whoFrom.getState().points;
    } else if (whoFrom.getState().a == Action::updateHp && whoFrom.getState().botName == 1) {
        p1Hp = whoFrom.getState().hp;
    } else if (whoFrom.getState().a == Action::updatePoints && whoFrom.getState().botName == 2) {
        p2Points = whoFrom.getState().points;
    } else if (whoFrom.getState().a == Action::updateHp && whoFrom.getState().botName == 2) {
        p2Hp = whoFrom.getState().hp;
    } else if (whoFrom.getState().a == Action::addItems){
          theDisplay[whoFrom.getState().x][whoFrom.getState().y] = '.';
    }
}
void TextDisplay::print(){
    cout<<"Bot 1 Hp: "<<p1Hp<<endl;
    cout<<"Bot 1 Points: " <<p1Points<<endl;
    cout<<"Bot 2 Hp: "<<p2Hp<<endl;
    cout<<"Bot 2 Points: " <<p2Points<<endl;
	for (int i = 0; i < size + 1; ++i) cout<<"-";
	cout<<endl;
	for (int i = 0; i < size; ++i){
        cout<<"|";
		for(int j = 0; j < size; ++j){
			cout<<theDisplay[i][j];
		}
        cout<<"|"<<endl;
	}
    for (int i = 0; i < size + 1; ++i) cout<<"-";
    cout<<endl;
}
