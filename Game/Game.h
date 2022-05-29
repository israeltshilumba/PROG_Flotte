//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_GAME_H
#define FLOTTENKAMPF_GAME_H

#include <iostream>
#include "../Flotte.h"
#include "../Field.h"

using namespace std;

class Game {

public:
    Game(Flotte&, Flotte&, Field&);
    virtual ~Game();
    Flotte player1;
    Flotte player2;
    Field field;
    bool attack(bool);
    bool gameTurns();
    void movePlayer(bool);

    int selectShip(Flotte& player) const;

    void selectDirection(Schiff&);

    bool changePosition(Schiff&, char);

    int shipDistance(Schiff&, Schiff&);

    int modifyDamage(int, int);
};


#endif //FLOTTENKAMPF_GAME_H
