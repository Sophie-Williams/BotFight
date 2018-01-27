//
//  options.hpp
//  BOTFIGHTv2
//
//  Created by William Tang on 2018-01-09.
//  Copyright © 2018 WT. All rights reserved.
//

#ifndef options_hpp
#define options_hpp



enum class Direction { right, left, down, up, none};
enum class Player { player1, player2 , opponent, draw, none};
enum class Effect { losePoints, gainPoints, loseHp, gainHp, updateBoard, none};
enum class Action { moved, usedItem, updateHp, updatePoints,addItems, none};

struct Cell{
    Effect e;
    int val;
};

#endif /* options_hpp */
