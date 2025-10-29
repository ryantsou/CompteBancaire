#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string nom, string prenom, string login, string mdp)
    : Utilisateur(nom, prenom, login, mdp) {}

void Admin::afficherProfil() const {
    cout << "[ADMIN] " << prenom << " " << nom << " (Compte administrateur)" << endl;
}
