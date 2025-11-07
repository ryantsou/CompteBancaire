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
    // Sérialisation pour persistance
    std::string serialize() const; // ligne complète pour le fichier
    static CompteBancaire deserialize(const std::string& line);
    // Vérifier si les identifiants correspondent au propriétaire
    bool matchesCredentials(const std::string& login, const std::string& mdp) const;
};

#endif