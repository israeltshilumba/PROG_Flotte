//
// Created by isilu on 25.05.2022.
//
#include <iostream>
#include "Kreuzer.h"
#include "../Dice/Dice.h"

Kreuzer::Kreuzer(){
    this->huelle = 75;
    this->groesse = 6;
    this->schaden = 30;
    name = "Kreuzer";
    state = true;
}

int Kreuzer::attack(int dice, int defenderSize) {
    int damage = 0;
    cout << "DICE: " << "[" << dice <<  "]" << endl;
    if (dice < defenderSize) {
        cout << "Erfolgloser Angriff!" << endl;
        return 0;
    }
    while (dice >= defenderSize){
        cout << "DICE: " << "[" << dice <<  "]" << endl;
        damage += special();
        dice = Dice::rollDice();
        system("pause"); //unsaubere Lösung, aber srand ist in diesem Fall nicht verlässlich ist
    }
    return damage;
}

int Kreuzer::special() {
    std::cout << "\nBombardement!" << endl;
    return schaden;
}

bool Kreuzer::takeDamage(int damage) {
    this->huelle -= damage;
    if (this->huelle <= 0){
        this->state = false;
        return false;
    }
    return true;
}

Kreuzer::~Kreuzer() {

}

int Kreuzer::getHuelle() const {
    return huelle;
}

void Kreuzer::setHuelle(int huelle) {
    Kreuzer::huelle = huelle;
}

int Kreuzer::getGroesse() const {
    return groesse;
}

void Kreuzer::setGroesse(int groesse) {
    Kreuzer::groesse = groesse;
}

int Kreuzer::getSchaden() const {
    return schaden;
}

void Kreuzer::setSchaden(int schaden) {
    Kreuzer::schaden = schaden;
}

string Kreuzer::getName() const {
    return name;
}

bool Kreuzer::getState() const {
    return this->state;
}