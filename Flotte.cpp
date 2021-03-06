//
// Created by isilu on 25.05.2022.
//

#include "Flotte.h"
#include <iostream>




Flotte::Flotte() {
    this->size = 0;
}

Flotte::~Flotte() {

}

void Flotte::addShip(Schiff& ship) {

    if (size < MAX_SHIPS + 1){
        Schiff *shipPointer = &ship;
        flottenListe.push_back(shipPointer);
        ++size;
        std::cout << endl << " ** Added successfully **" << std::endl;
    } else std::cout << "Flotte voll!" << std::endl;

}

int Flotte::getSize() const {
    return size;
}

void Flotte::setSize(int size) {
    Flotte::size = size;
}

void Flotte::printFleet() {

    for(int i = 0; i < size; i++){
        if (flottenListe.at(i)->getHuelle() > 0) {
            cout << "[" << i << "]: " << flottenListe.at(i)->getName() << " |  HP: "<<
            flottenListe.at(i)->getHuelle() << " | Schaden: " << flottenListe.at(i)->getSchaden() <<
            " | POS[X]:" << flottenListe.at(i)->getX() << " | POS[Y]: " << flottenListe.at(i)->getY() << endl;
        } else cout << "[" << i << "]: " << "** Destroyed **" << endl;
    }
}

void Flotte::initializePosition(bool player){
    int tmpY = 0;
    if (player) tmpY = FIELDSIZE;


        for (int i = 0; i < size; i += 1) {
            flottenListe.at(i)->setX(i);
            flottenListe.at(i)->setY(tmpY);
        }


}

bool Flotte::checkState(){

    for(int i = 0; i < size; i++){
        if (flottenListe.at(i)->getState()) {
            return true;
        }
    }
    return false;
}

