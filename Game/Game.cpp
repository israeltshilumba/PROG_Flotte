//
// Created by isilu on 25.05.2022.
//

#include "Game.h"
#include "../Dice/Dice.h"

Game::Game(Flotte &player1,Flotte &player2, Field &field) {
    this->player1 = player1;
    this->player2 = player2;
    this->field = field;
}

Game::~Game() {

}

bool Game::changePosition(Schiff &schiff, char input){
    switch (input) {
        case 'w': {//up Y +1
            if(schiff.getY() + 1 > 15 || schiff.getY() + 1 < 0){
                cout << "Wumps, da scheint ein Wasserfall zu sein" << endl;
                return false;
            } else { schiff.setY(schiff.getY() + 1); return true;}
        }
            break;
        case 'a':{//left X - 1
            if(schiff.getX() - 1 > 15 || schiff.getX() - 1 < 0){
                cout << "Wumps, da scheint ein Wasserfall zu sein" << endl;
                return false;
            } else { schiff.setY(schiff.getX() - 1); return true;}
        }
        case 's':{ //it do go down
            if(schiff.getY() - 1 > 15 || schiff.getY() - 1 < 0){
                cout << "Wumps, da scheint ein Wasserfall zu sein" << endl;
                return false;
            } else { schiff.setY(schiff.getY() - 1); return true;}
        }
        case 'd':{ //right x + 1
            if(schiff.getX() + 1 > 15 || schiff.getX() + 1 < 0){
                cout << "Wumps, da scheint ein Wasserfall zu sein" << endl;
                return false;
            } else { schiff.setX(schiff.getX() + 1); return true;}
        }
        default: return false;
    }
}

void Game::selectDirection(Schiff &schiff){
    char input = 0;
    bool stop = true;
    cout << "Bewegen Sie sich mit W-A-S-D" << endl;
    while (stop){
        try {
            cin >> input;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                throw invalid_argument("Fehler: Ihre Eingabe ist ungueltig");
            }
            switch (input) {
                case 'w':
                case 'a':
                case 's':
                case 'd':
                case 'f': if (changePosition(schiff, input)) stop = false;
                    break;
                default: cout << "Waehlen Sie einen gueltigen Movement Command!" << endl;
            }
        } catch (const invalid_argument& msg) {
            cout << endl << msg.what() << endl;
            cout << "Versuchen Sie es noch einmal" << endl;
        }
    }
}

bool Game::attack(bool player){
    player1.initializePosition(true);
    player2.initializePosition(false);

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

    //new Movement before attack option
    cout << "Waehlen Sie ein Schiff aus, das Sie bewegen moechten!" << endl;
    attacker -> printFleet();
    int shipToMove = selectShip(*attacker);
    selectDirection(*attacker->flottenListe.at(shipToMove));
    //new
    cout << endl <<"** Angreifer Flotte **" << endl;
    cout << "Waehlen Sie ein Schiff, das den Gegner angreifen soll!" << endl;
    attacker -> printFleet();
    //insert Movement Option
    int attackShip = selectShip(*attacker);

    //print Field
   // field.printField(*attacker->flottenListe.at(attackShip), *defender);
    //insert Movement Option

    cout << endl << "Verteidiger Flotte" << endl;
    //cout << "Waehlen Sie ein Schiff aus, das Sie bewegen moechten!" << endl;
    //defender -> printFleet();
    //shipToMove = selectShip(*defender);
    //selectDirection(*defender->flottenListe.at(shipToMove));
    cout << "Waehlen Sie ein Schiff, das angegriffen werden soll!" << endl;
    defender -> printFleet();
    //new
    //field.printField(*attacker, *defender);
    int defendingShip = selectShip(*defender);

    int defenderSize = defender -> flottenListe.at(defendingShip) -> getGroesse();
    //throw dice
    int dice = Dice::rollDice();
    int damage = attacker -> flottenListe.at(attackShip) -> attack(dice, defenderSize);
    int distance = shipDistance(*attacker -> flottenListe.at(attackShip), *defender -> flottenListe.at(defendingShip));
    damage = modifyDamage(distance, damage);
    cout << "Schaden verursacht *" << damage << "*" << endl;
    int state = defender -> flottenListe.at(defendingShip) -> takeDamage(damage);
    if (!state) cout << endl << "***Schiff wurde zerstoert!***" << endl;

    //check if fleet is alive
    bool fleetState = defender -> checkState();
    return fleetState;
}

int Game::modifyDamage(int distance, int damage){
    cout << "Distanz: " << distance << endl;
    if (distance <= 10) { cout << "Distanz Bonus: [100%]"<< endl; return damage * 2; }
    if (distance <= 15) { cout << "Distanz Bonus: [50%]"<< endl; return (int) (damage * 1.5); }
    if (distance <= 20) { cout << "Distanz Bonus: [20%]"<< endl; return (int) (damage * 1.2); }
    if (distance <= 30) return (int)(damage * 1);
    return damage;

}
int Game::shipDistance(Schiff& attacker, Schiff& defender){
    int xDistance = abs(attacker.getX() - defender.getX());
    int yDistance = abs(attacker.getY() - defender.getY());

    return xDistance + yDistance;
}

void Game::movePlayer(bool player){
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
