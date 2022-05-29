//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_FLOTTE_H
#define FLOTTENKAMPF_FLOTTE_H

#include <vector>

#include "Schiff.h"

#define MAX_SHIPS 8
#define FIELDSIZE 15
using namespace std;

class Flotte {
public:
    Flotte();
    virtual ~Flotte();
    std::vector<Schiff*> flottenListe; //wenn man eine Pointer auf eine Abstrakte Klasse hat, dann kann diese vom Vector verwendet werden
    void addShip(Schiff&);
    void printFleet();
    //getter setter
    int getSize() const;
    void setSize(int size);
    bool checkState();
    void initializePosition(bool);
private:
    int size;
};


#endif //FLOTTENKAMPF_FLOTTE_H
