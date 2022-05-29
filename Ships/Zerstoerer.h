//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_ZERSTOERER_H
#define FLOTTENKAMPF_ZERSTOERER_H
#include "..\Schiff.h"

using namespace std;

class Zerstoerer : public Schiff {

    //überschreibe mich!
public:
    Zerstoerer();
    virtual ~Zerstoerer();
    int attack(int, int);
    int special();
    bool takeDamage(int);
    int getHuelle() const;
    void setHuelle(int huelle);
    int getGroesse() const;
    void setGroesse(int groesse);
    int getSchaden() const;
    void setSchaden(int schaden);
    string getName() const;
    bool getState() const;
    //position
    int getX() const;
    void setX(int);
    int getY() const;
    void setY(int);

private:
    int huelle;
    int groesse;
    int schaden;
    string name;
    bool state;
    //position
    int x;
    int y;
};


#endif //FLOTTENKAMPF_ZERSTOERER_H
