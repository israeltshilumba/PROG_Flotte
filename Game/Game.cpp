//
// Created by isilu on 25.05.2022.
//

#include "Game.h"
#include "../Dice/Dice.h"

Game::Game(Flotte &player1,Flotte &player2) {
    this->player1 = player1;
    this->player2 = player2;
}

Game::~Game() {

}

bool Game::attack(bool player){
    Flotte *attacker;
    Flotte *defender;

    switch(player){
        case true: {
            attacker = &player1;
            defender = &player2;
        }
        break;
        case false: {
            attacker = &player2;
            defender = &player1;
            break;
        }
    }
    cout << endl <<"** Angreifer Flotte **" << endl;
    cout << "Waehlen Sie ein Schiff, das den Gegner angreifen soll!" << endl;
    attacker -> printFleet();
    int attackShip = selectShip(*attacker);
    cout << endl << "Verteidiger Flotte" << endl;
    cout << "Waehlen Sie ein Schiff, das angegriffen werden soll!" << endl;
    defender -> printFleet();
    int defendingShip = selectShip(*defender);

    int defenderSize = defender -> flottenListe.at(defendingShip) -> getGroesse();
    //throw dice
    int dice = Dice::rollDice();
    int damage = attacker -> flottenListe.at(attackShip) -> attack(dice, defenderSize);
    int state = defender -> flottenListe.at(defendingShip) ->takeDamage(damage);
    if (!state) cout << endl << "***Schiff wurde zerstoert!***" << endl;

    //check if fleet is alive
    bool fleetState = defender -> checkState();
    return fleetState;
}

int Game::selectShip(Flotte &player) const{
    int input = 0;
    bool stop = true;
    while (stop){
        try {
            cin >> input;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                throw invalid_argument("Fehler: Ihre Eingabe ist ungueltig");
            }
            if (input > player.getSize() - 1 || input < 0){
                throw "Fehler: Schiffe befinden sich nicht in Ihrer Flotte";
            }
            if(!player.flottenListe.at(input)->getState()){
                throw "Schiff wurde bereits zerstoert";
            }
            stop = false;
        } catch (const invalid_argument& msg) {
            cout << endl << msg.what() << endl;
            cout << "Versuchen Sie es noch einmal" << endl;
        }
        catch (const char* msg){
            cout << msg << endl;
        }
    }
    return input;
}

bool Game::gameTurns() {
    bool state;
    bool player; //switch zwischen spieler 1 und spieler 2
    while(true){
        player = true;
        state = attack(player);
        if(!state) return player;
        player = false;
        state = attack(player);
        if(!state) return player;
    }
}
