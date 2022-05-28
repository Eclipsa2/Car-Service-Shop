//
// Created by Andrei on 5/28/2022.
//

#include <iostream>
#include "Masina.h"
#include "Motocicleta.h"
#include "Vehicul.h"

using namespace std;

#ifndef MAIN_CPP_VALOAREVEHICUL_H
#define MAIN_CPP_VALOAREVEHICUL_H

class VehiculExotic : public Vehicul
{
private:
    const Vehicul& vehicul;
    int tip;
    int valoare;
public:
    VehiculExotic(const Vehicul &v, int &valoare, int tip) : vehicul{v}{
        this->valoare = valoare;
        this->tip = tip;
    }
    friend ostream& operator<<(ostream& out, VehiculExotic& v)
    {
        cout<<"Vehiculul este unul exotic, cu o valoare de: "<<v.valoare<<" euro";
        if(v.tip == 1)
            cout<<(Masina&) v;
        else
            cout<<(Motocicleta&) v;
    }
};

#endif //MAIN_CPP_VALOAREVEHICUL_H
