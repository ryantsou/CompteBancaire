#ifndef BANQUE_H
#define BANQUE_H

#include <vector>
#include "CompteBancaire.h"
#include "Client.h"
using namespace std;

class Banque {
private:
    vector<CompteBancaire> comptes;

public:
    void ajouterCompte(const CompteBancaire &compte);
    CompteBancaire* trouverCompte(string numero);
    void afficherTousLesComptes() const;
    void creerCompte(Client client, string numero, double montantInitial);
    void supprimerCompte(string numero);
    bool transfererArgent(string numeroSource, string numeroDestination, double montant);
};

#endif
