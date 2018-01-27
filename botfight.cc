
#include <iostream>
#include <sstream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <chrono>

#include "gamecontroller.h"

using namespace std;

int main(int argc, const char *argv[]){
	string gameMode = "PvP";
	int size = 10;
	for (int i = 1; i < argc; ++i){
		string x(argv[i]);
		if (x == "PvC" || x == "CvC"){
			gameMode = x;
		} else if (x == "-size") {
			++i;
			int temp;
			string x(argv[i]);
            istringstream iss(x);
			iss>>temp;
			if (temp <= 30 && temp >=10) size = temp;			
		}
	}
	srand(time(NULL));
	GameController gc(size);
    gc.print();
    int totalTime = 60;
    bool player1 = true;
    bool player2 = true;
    bool noInput = false;
    if (gameMode == "CvC"){
        player1 = false;
        player2 = false;
    } else if (gameMode == "PvC"){
        player2 = false;
    }
	do {
        auto start = chrono::steady_clock::now();
        bool valid= false;
		string c;
		do {
            if (player1) {
              cin >> c;
                if (cin.fail()) {
                    noInput = true;
                    break;
                }
            } else {
                int y = rand() % 4;
                if (y == 0){
                    c = "w";
                } else if (y == 1){
                    c = "a";
                } else if (y == 2){
                    c = "s";
                } else {
                    c = "d";
                }
            }

			if (c == "w"){
				if (gc.validMove(Direction::up, Player::player1)){
					valid = true;
					gc.move(Direction::up, Player::player1);
				}
			} else if (c == "a"){
				if (gc.validMove(Direction::left, Player::player1)){
					valid = true;
					gc.move(Direction::left, Player::player1);
				}
			} else if (c == "s"){
				if (gc.validMove(Direction::down, Player::player1)){
					valid = true;
					gc.move(Direction::down, Player::player1);
				}
			} else if (c == "d"){
				if (gc.validMove(Direction::right, Player::player1)){
					valid = true;
					gc.move(Direction::right, Player::player1);
				}
			}
			if (!valid) cout<<"Invalid move"<<endl;
		} while(!valid);
		valid = false;
		do {
            if (player2 && !noInput) {
                cin >> c;
                if (cin.fail()) {
                    noInput = true;
                    break;
                }
            } else {
                int y = rand() % 4;
                if (y == 0){
                    c = "w";
                } else if (y == 1){
                    c = "a";
                } else if (y == 2){
                    c = "s";
                } else {
                    c = "d";
                }
            }
			if (c == "w"){
				if (gc.validMove(Direction::up, Player::player2)){
					valid = true;
					gc.move(Direction::up, Player::player2);
				}
			} else if (c == "a"){
				if (gc.validMove(Direction::left, Player::player2)){
					valid = true;
					gc.move(Direction::left, Player::player2);
				}
			} else if (c == "s"){
				if (gc.validMove(Direction::down, Player::player2)){
					valid = true;
					gc.move(Direction::down, Player::player2);
				}
			} else if (c == "d"){
				if (gc.validMove(Direction::right, Player::player2)){
					valid = true;
					gc.move(Direction::right, Player::player2);
				}
			}
			if (!valid) cout<<"Invalid move"<<endl;
		} while(!valid);
        auto end = chrono::steady_clock::now();
        valid = false;
		gc.useItem();
		gc.print();
        totalTime -=chrono::duration_cast<chrono::seconds>(end - start).count();
	} while (!gc.gameOver(totalTime) && !noInput);
	gc.displayWinner();
 
}
