//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_JAEGER_H
#define FLOTTENKAMPF_JAEGER_H
#include "..\Schiff.h"

using namespace std;

class Jaeger : public Schiff {
        //überschreibe mich!
public:
    Jaeger();
    virtual ~Jaeger();
    int attack(int, int);
    int special();
    bool takeDamage(int);
    int getHuelle() const;
    void setHuelle(int);
    int getGroesse() const;
    void setGroesse(int);
    int getSchaden() const;
    void setSchaden(int);
    string getName() const;
    bool getState() const;
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


#endif //FLOTTENKAMPF_JAEGER_H
