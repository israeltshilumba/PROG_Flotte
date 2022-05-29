//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_SCHIFF_H
#define FLOTTENKAMPF_SCHIFF_H
#include <string>
using namespace std;

class Schiff {
public:
    //überschreibe mich!
    virtual int attack(int, int) = 0;
    virtual int special() = 0;
    virtual bool takeDamage(int) = 0;
    virtual int getHuelle() const = 0;
    virtual void setHuelle(int) = 0;
    virtual int getGroesse() const = 0;
    virtual void setGroesse(int) = 0;
    virtual int getSchaden() const = 0;
    virtual void setSchaden(int) = 0;
    virtual string getName() const = 0;
    virtual bool getState() const = 0;
    //neu, muss ueberschrieben werden
    virtual void setX(int) = 0;
    virtual int getX() const = 0;
    virtual void setY(int) = 0;
    virtual int getY() const = 0;
};


#endif //FLOTTENKAMPF_SCHIFF_H
