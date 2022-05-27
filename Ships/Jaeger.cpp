//
// Created by isilu on 25.05.2022.
//
#include "iostream"
#include "Jaeger.h"


Jaeger::Jaeger() {
    this->huelle = 75;
    this->groesse = 4;
    this->schaden = 125;
    name = "Jaeger";
    state = true;
}

int Jaeger::attack(int dice, int defenderSize) {
    cout << "DICE: " << "[" << dice <<  "]" << endl;
    if (dice < defenderSize) {
        cout << "Erfolgloser Angriff!" << endl;
        return 0;
    }
    cout << "Jaeger attack" << endl;
    if (dice > 8){
        return special();
    } else {
        return schaden;
    }
}

int Jaeger::special() {
    std::cout << "Kritischer Treffer" << endl;
    return schaden * 2;

}

bool Jaeger::takeDamage(int damage) {
    this->huelle -= damage;
    if (this->huelle <= 0){
        this->state = false;
        return false;
    }
    return true;
}

Jaeger::~Jaeger() {

}

int Jaeger::getHuelle() const {
    return huelle;
}

void Jaeger::setHuelle(int huelle) {
    Jaeger::huelle = huelle;
}

int Jaeger::getGroesse() const {
    return groesse;
}

void Jaeger::setGroesse(int groesse) {
    Jaeger::groesse = groesse;
}

int Jaeger::getSchaden() const {
    return schaden;
}

void Jaeger::setSchaden(int schaden) {
    Jaeger::schaden = schaden;
}

string Jaeger::getName() const {
    return name;
}

bool Jaeger::getState() const {
    return this->state;
}
