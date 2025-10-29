#ifndef CLIENT_H
#define CLIENT_H

#include "Utilisateur.h"

class Client : public Utilisateur {
private:
    string adresse;

public:
    Client(string nom, string prenom, string login, string mdp, string adresse);
    void afficherProfil() const override;
};

#endif
