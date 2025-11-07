#include "Client.h"
#include <iostream>
#include <sstream>
using namespace std;

Client::Client(string nom, string prenom, string login, string mdp, string adresse)
    : Utilisateur(nom, prenom, login, mdp), adresse(adresse) {}

void Client::afficherProfil() const {
    cout << "[CLIENT] " << prenom << " " << nom << " - " << adresse << endl;
}

string Client::serializeFields() const {
    std::ostringstream oss;
    // Ne pas inclure le séparateur '|' dans les champs; si besoin, échapper plus tard
    oss << nom << "|" << prenom << "|" << login << "|" << motDePasse << "|" << adresse;
    return oss.str();
}

Client Client::deserializeFromFields(const std::vector<std::string>& parts, size_t offset) {
    // parts[offset] = nom, [offset+1]=prenom, [offset+2]=login, [offset+3]=mdp, [offset+4]=adresse
    if (parts.size() < offset + 5) return Client("", "", "", "", "");
    return Client(parts[offset], parts[offset+1], parts[offset+2], parts[offset+3], parts[offset+4]);
}
