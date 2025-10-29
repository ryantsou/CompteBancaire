#include "Utilisateur.h"
#include <iostream>
using namespace std;

Utilisateur::Utilisateur(string nom, string prenom, string login, string mdp)
    : nom(nom), prenom(prenom), login(login), motDePasse(mdp) {}

string Utilisateur::getLogin() const {
    return login;
}

bool Utilisateur::verifierMotDePasse(string mdp) const {
    return mdp == motDePasse;
}

void Utilisateur::afficherProfil() const {
    cout << "Nom : " << prenom << " " << nom << endl;
}
