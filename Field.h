//
// Created by isilu on 28.05.2022.
//

#ifndef FLOTTENKAMPF_FIELD_H
#define FLOTTENKAMPF_FIELD_H

#include <iostream>
#include <vector>
#include "Schiff.h"
#include "Flotte.h"

using namespace std;

class Field {
public:
    int field[FIELDSIZE][FIELDSIZE];
    void printField(Flotte&, Flotte&);
    int distance(Schiff&, Schiff&);
};


#endif //FLOTTENKAMPF_FIELD_H
