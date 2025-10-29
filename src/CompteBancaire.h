#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <string>
#include "Client.h"
using namespace std;

class CompteBancaire {
private:
    string numeroCompte;
    Client proprietaire;
    double solde;

public:
    CompteBancaire(string numero, Client client, double montantInitial);

    void deposer(double montant);
    void retirer(double montant);
    void afficherInfos() const;

    string getNumero() const;
    double getSolde() const;
    Client getProprietaire() const;
};

#endif