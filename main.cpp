#include <iostream>
#include "Dice/Dice.h"
#include "Schiff.h"
#include "Ships/Kreuzer.h"
#include "Ships/Jaeger.h"
#include "Flotte.h"
#include "Ships/Zerstoerer.h"
#include "Game/Game.h"
#include <vector>

using namespace std;
//ToDo: Erstellung einer Flotte mit mehreren Schiffen
void printInfo(){
    cout << "Jaeger:        Huelle: 75    Groesse:4   Schaden:30" << endl;
    cout << "Zerstoerer:    Huelle: 150   Groesse:6   Schaden:60" << endl;
    cout << "Kreuzer:       Huelle: 250   Groesse:8   Schaden:50" << endl;
}

void addPlayerFleet(Flotte &player1, int input){
    while (input != 0){
        cout << endl << "Waehlen Sie ein Schiff, das Sie zu Ihrer Flotte hinzufuegen moechten!" << endl;
        cout << endl << "[0] Auswahl beenden \n[1] Jaeger \n[2] Zerstoerer \n[3] Kreuzer \n[4] Infos zu den Schiffen" << endl;
        cout << "Sie haben: " << player1.getSize() << " Schiff(e)" << endl << endl;

        cin >> input;
        switch (input) {
            case 1: {
                Schiff *ship = new Jaeger;
                player1.addShip(*ship);

            } break;
            case 2: {
                Schiff *ship = new Kreuzer;
                player1.addShip(*ship);
            } break;
            case 3: {
                Schiff *ship = new Zerstoerer;
                player1.addShip(*ship);
            } break;
            case 4: printInfo();
                break;
            case 0: cout << endl << "** Auswahl wurde beendet **" << endl;
                break;
            default: cout << "** Ungueltige Auswahl **" << endl;
        }
    }
}

void debug(){
    Flotte *player1 = new Flotte;
    Flotte *player2 = new Flotte;
    int input = 1;
    //Flotte Player1
    addPlayerFleet(*player1, input);
    cout << endl << "Player 2 Auswahl:" << endl;
    addPlayerFleet(*player2, input);
    Game *GAME = new Game(*player1, *player2);
    bool winner = GAME->gameTurns();
    switch (winner) {
        case true: cout << "Player 1 won the Game" << endl;
        break;
        case false: cout << "Player 2 won the Game" << endl;
    }
}

int main() {
    debug();


    //toDo Attack
    return 0;
}