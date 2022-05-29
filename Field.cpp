//
// Created by isilu on 28.05.2022.
//

#include "Field.h"

void Field::printField(Flotte &player1, Flotte &player2) {
    for (int y = 0; y < FIELDSIZE; y++){
        for(int x = 0; x < FIELDSIZE; x++){
            //Schiffe aus der Flotte printen
            for(int i = 0; i < player1.getSize(); i++){
                if (player1.flottenListe.at(i)->getX() == x &&
                    player1.flottenListe.at(i)->getY() == y){
                    cout << " 0 ";
                }
            } cout << " ~ ";


        }
        cout << endl;
    }
}

int Field::distance(Schiff &player1, Schiff &player2) {
    int xDistance = abs(player1.getX() - player2.getX());
    int yDistance = abs(player1.getY() - player2.getY());

    return xDistance + yDistance;
}
