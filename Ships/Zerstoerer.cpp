//
// Created by isilu on 25.05.2022.
//
#include <iostream>
#include "Zerstoerer.h"

Zerstoerer::Zerstoerer() {
    this->huelle = 300;
    this->groesse = 6;
    this->schaden = 20;
    name = "Zerstoerer";
    state = true;
}

int Zerstoerer::attack(int dice, int defenderSize) {
    cout << "DICE: " << "[" << dice <<  "]" << endl;
    if (dice < defenderSize - 2) {
        cout << "Erfolgloser Angriff!" << endl;
        return 0;
    }
    cout << "Zerstoerer attack" << endl;
    return special();
}

int Zerstoerer::special() {
    std::cout << "\nZielsuchend";
    return schaden;
}

bool Zerstoerer::takeDamage(int damage) {
    this->huelle -= damage;
    if (this->huelle <= 0){
        this->state = false;
        return false;
    }
    return true;
}

Zerstoerer::~Zerstoerer() {

}

int Zerstoerer::getHuelle() const {
    return huelle;
}

void Zerstoerer::setHuelle(int huelle) {
    Zerstoerer::huelle = huelle;
}

int Zerstoerer::getGroesse() const {
    return groesse;
}

void Zerstoerer::setGroesse(int groesse) {
    Zerstoerer::groesse = groesse;
}

int Zerstoerer::getSchaden() const {
    return schaden;
}

void Zerstoerer::setSchaden(int schaden) {
    Zerstoerer::schaden = schaden;
}

string Zerstoerer::getName() const {
    return name;
}

bool Zerstoerer::getState() const {
    return this->state;
}

//position
int Zerstoerer::getX() const {
    return this->x;
}

void Zerstoerer::setX(int xPosition) {
    this->x = xPosition;
}

int Zerstoerer::getY() const {
    return this->y;
}

void Zerstoerer::setY(int yPosition) {
    this->y = yPosition;
}