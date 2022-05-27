//
// Created by isilu on 25.05.2022.
//
#include <ctime>
#include <stdlib.h>

#include "Dice.h"
int Dice::rollDice() {
    int random;
    srand(time(NULL));

    random = rand()*(rand()+1111);
    return random % 11;
}