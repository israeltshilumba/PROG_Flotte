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
    void setHuelle(int huelle);
    int getGroesse() const;
    void setGroesse(int groesse);
    int getSchaden() const;
    void setSchaden(int schaden);
    string getName() const;
    bool getState() const;
private:
        int huelle;
        int groesse;
        int schaden;
        string name;
        bool state;
};


#endif //FLOTTENKAMPF_JAEGER_H
