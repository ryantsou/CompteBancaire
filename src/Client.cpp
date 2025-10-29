#include "Client.h"
#include <iostream>
using namespace std;

Client::Client(string nom, string prenom, string login, string mdp, string adresse)
    : Utilisateur(nom, prenom, login, mdp), adresse(adresse) {}

void Client::afficherProfil() const {
    cout << "[CLIENT] " << prenom << " " << nom << " - " << adresse << endl;
}
