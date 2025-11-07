#ifndef BANQUE_H
#define BANQUE_H

#include <vector>#include <unordered_map>
#include <fstream>
#include <sstream>
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
    void supprimerCompte(string numero);    std::unordered_map<std::string, Client> clients;
    void sauverClients();
    void chargerClients();
    void creerClient(const Client& client);
    bool transfererArgent(string numeroSource, string numeroDestination, double montant);
};

#endif
