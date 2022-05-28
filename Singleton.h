//
// Created by Andrei on 5/28/2022.
//
#include <iostream>
#include "Vehicul.h"
#include "Masina.h"
#include "Motocicleta.h"
#include <vector>
#include <fstream>
using namespace std;

#ifndef MAIN_CPP_SINGLETON_H
#define MAIN_CPP_SINGLETON_H

class Singleton{
private:
    static Singleton *instance;
public:
    static Singleton *getInstance() {
        if (!instance)
            instance = new Singleton;
        return instance;
    }

    void citireFisierReparate(int& nrMasiniReparate, int& nrMotocicleteReparate, vector <Vehicul*> &vehicule)
    {
        string marca, model, nrInmatriculare, culoare, tipTransmisie;
        bool reparata;
        int  manopera, anFabricatie, caiPutere, auxVector[5], distantaRoti, masaTotala;
        ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniReparateVeriku");
        f>>nrMasiniReparate;
        for (int i = 0; i < nrMasiniReparate; i++)
        {
            f>>marca>>model>>nrInmatriculare>>culoare>>reparata;
            for (int i = 0; i<=5; i++)
            {
                f>>auxVector[i];
            }
            f>>manopera>>anFabricatie>>caiPutere;
            vehicule.push_back(new Masina(marca, model, anFabricatie, culoare, nrInmatriculare, reparata, auxVector, caiPutere));
        }
        f>>nrMotocicleteReparate;
        for (int i = 0; i < nrMotocicleteReparate; i++)
        {
            f>>marca>>model>>nrInmatriculare>>culoare>>reparata>>tipTransmisie;
            for (int i = 0; i<=5; i++)
            {
                f>>auxVector[i];
            }
            f>>manopera>>anFabricatie>>caiPutere>>distantaRoti>>masaTotala;
            vehicule.push_back(new Motocicleta(marca, model, anFabricatie, culoare, nrInmatriculare, tipTransmisie, masaTotala, distantaRoti, reparata, auxVector, caiPutere));
        }
        f.close();
    }

    void citireFisierService(int& nrMasiniService, int& nrMotocicleteService, vector <Vehicul*> &vehicule)
    {
        string marca, model, nrInmatriculare, culoare, tipTransmisie;
        bool reparata;
        int  manopera, anFabricatie, caiPutere, auxVector[5], distantaRoti, masaTotala;
        ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniServiceVeriku");
        f>>nrMasiniService;
        for (int i = 0; i < nrMasiniService; i++)
        {
            f>>marca>>model>>nrInmatriculare>>culoare>>reparata;
            for (int i = 0; i<=5; i++)
            {
                f>>auxVector[i];
            }
            f>>manopera>>anFabricatie>>caiPutere;
            vehicule.push_back(new Masina(marca, model, anFabricatie, culoare, nrInmatriculare, reparata, auxVector, caiPutere));
        }
        f>>nrMotocicleteService;
        for (int i = 0; i < nrMotocicleteService; i++)
        {
            f>>marca>>model>>nrInmatriculare>>culoare>>reparata>>tipTransmisie;
            for (int i = 0; i<=5; i++)
            {
                f>>auxVector[i];
            }
            f>>manopera>>anFabricatie>>caiPutere>>distantaRoti>>masaTotala;
            vehicule.push_back(new Motocicleta(marca, model, anFabricatie, culoare, nrInmatriculare, tipTransmisie, masaTotala, distantaRoti, reparata, auxVector, caiPutere));
        }
        f.close();
    }

    void scriereFisierReparate(int nrMasiniReparate, int nrMotocicleteReparate, vector <Vehicul*> vehicule)
    {
        ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniReparateVeriku") ;
        g<<nrMasiniReparate<<endl;
        int contor = 0;
        for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniReparate; p++)
        {
            if (dynamic_cast<Masina*>(*p)->isReparata() == true)
            {
                g<<dynamic_cast<Masina*>(*p)->getMarca()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getModel()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getNrInmatriculare()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getCuloare()<<" ";
                g<<dynamic_cast<Masina*>(*p)->isReparata()<<" ";
                const int* probleme = (dynamic_cast<Masina*>(*p)->getProbleme());
                for (int i = 0; i<=5; i++)
                    g<<probleme[i]<<" ";
                g<<dynamic_cast<Masina*>(*p)->getManopera()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getAnFabricatie()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getCaiPutere()<<" ";
                g<<endl;
            }
            contor++;
        }
        g<<nrMotocicleteReparate<<endl;
        contor = 0;
        for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniReparate; p++)
        {
            g<<dynamic_cast<Motocicleta*>(*p)->getMarca()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getModel()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getNrInmatriculare()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getCuloare()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->isReparata()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getTipTransmisie()<<" ";
            const int* probleme = (dynamic_cast<Motocicleta*>(*p)->getProbleme());
            for (int i = 0; i<=5; i++)
                g<<probleme[i]<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getManopera()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getAnFabricatie()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getCaiPutere()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getDistantaRoti()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getMasaTotala()<<" ";
            g<<endl;
            contor++;
        }

        g.close();
    }

    void scriereFisierService(int nrMasiniService, int nrMotocicleteService, vector <Vehicul*> vehicule)
    {
        ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniServiceVeriku") ;
        g<<nrMasiniService<<endl;
        int contor = 0;
        for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniService; p++)
        {
            if (dynamic_cast<Masina*>(*p)->isReparata() == false)
            {
                g<<dynamic_cast<Masina*>(*p)->getMarca()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getModel()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getNrInmatriculare()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getCuloare()<<" ";
                g<<dynamic_cast<Masina*>(*p)->isReparata()<<" ";
                const int* probleme = (dynamic_cast<Masina*>(*p)->getProbleme());
                for (int i = 0; i<=5; i++)
                    g<<probleme[i]<<" ";
                g<<dynamic_cast<Masina*>(*p)->getManopera()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getAnFabricatie()<<" ";
                g<<dynamic_cast<Masina*>(*p)->getCaiPutere()<<" ";
                g<<endl;
            }
            contor++;
        }
        g<<nrMotocicleteService<<endl;
        contor = 0;
        for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniService; p++)
        {
            g<<dynamic_cast<Motocicleta*>(*p)->getMarca()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getModel()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getNrInmatriculare()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getCuloare()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->isReparata()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getTipTransmisie()<<" ";
            const int* probleme = (dynamic_cast<Motocicleta*>(*p)->getProbleme());
            for (int i = 0; i<=5; i++)
                g<<probleme[i]<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getManopera()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getAnFabricatie()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getCaiPutere()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getDistantaRoti()<<" ";
            g<<dynamic_cast<Motocicleta*>(*p)->getMasaTotala()<<" ";
            g<<endl;
            contor++;
        }

        g.close();
    }
};

#endif //MAIN_CPP_SINGLETON_H
