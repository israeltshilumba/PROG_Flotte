//
// Created by isilu on 25.05.2022.
//

#ifndef FLOTTENKAMPF_KREUZER_H
#define FLOTTENKAMPF_KREUZER_H
#include "..\Schiff.h"

using namespace std;

class Kreuzer : public Schiff {
    //überschreibe mich!
public:
    Kreuzer();
    virtual ~Kreuzer();
    int attack(int, int);
    int special();
    bool takeDamage(int);
    int debug = 10;
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


#endif //FLOTTENKAMPF_KREUZER_H
