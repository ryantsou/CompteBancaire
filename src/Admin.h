#ifndef ADMIN_H
#define ADMIN_H

#include "Utilisateur.h"

class Admin : public Utilisateur {
public:
    Admin(string nom, string prenom, string login, string mdp);
    void afficherProfil() const override;
};

#endif
