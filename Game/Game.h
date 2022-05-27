//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_GAME_H
#define FLOTTENKAMPF_GAME_H

#include <iostream>
#include "../Flotte.h"
using namespace std;

class Game {

public:
    Game(Flotte&, Flotte&);
    virtual ~Game();
    Flotte player1;
    Flotte player2;
    bool attack(bool);
    bool gameTurns();

    int selectShip(Flotte& player) const;
};


#endif //FLOTTENKAMPF_GAME_H
