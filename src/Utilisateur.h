#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
using namespace std;

class Utilisateur {
protected:
    string nom;
    string prenom;
    string login;
    string motDePasse;

public:
    Utilisateur(string nom, string prenom, string login, string mdp);
    virtual ~Utilisateur() = default;

    string getLogin() const;
    bool verifierMotDePasse(string mdp) const;
    virtual void afficherProfil() const;
};

#endif
