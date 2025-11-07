#ifndef CLIENT_H
#define CLIENT_H

#include "Utilisateur.h"
#include <vector>

class Client : public Utilisateur {
private:
    string adresse;

public:
    Client(string nom, string prenom, string login, string mdp, string adresse);
    void afficherProfil() const override;
    // Sérialisation pour persistance
    std::string serializeFields() const; // nom|prenom|login|mdp|adresse
    static Client deserializeFromFields(const std::vector<std::string>& parts, size_t offset = 0);
};

#endif
