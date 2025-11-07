#include "CompteBancaire.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

CompteBancaire::CompteBancaire(string numero, Client client, double montantInitial)
    : numeroCompte(numero), proprietaire(client), solde(montantInitial) {}

void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        cout << " !! Montant invalide !" << endl;
        return;
    }
    solde += montant;
    cout << "Dépôt de " << fixed << setprecision(2) << montant << " € effectué. Nouveau solde : " << solde << " €." << endl;
}

void CompteBancaire::retirer(double montant) {
    if (montant <= 0) {
        cout << " !! Montant invalide !" << endl;
        return;
    }
    if (montant > solde) {
        cout << "!! Solde insuffisant !" << endl;
    } else {
        solde -= montant;
        cout << " !! Retrait de " << fixed << setprecision(2) << montant << " € effectué. Nouveau solde : " << solde << " €." << endl;
    }
}

void CompteBancaire::afficherInfos() const {
    cout << "\n=== Informations du compte ===" << endl;
    cout << "Numéro de compte : " << numeroCompte << endl;
    cout << "Propriétaire : ";
    proprietaire.afficherProfil();
    cout << "Solde actuel : " << fixed << setprecision(2) << solde << " €" << endl;
}

string CompteBancaire::getNumero() const {
    return numeroCompte;
}

double CompteBancaire::getSolde() const {
    return solde;
}


string CompteBancaire::serialize() const {
    std::ostringstream oss;
    oss << numeroCompte << "|" << proprietaire.serializeFields() << "|";
    // solde formaté en fixe
    oss << std::fixed << std::setprecision(2) << solde;
    return oss.str();
}

CompteBancaire CompteBancaire::deserialize(const string& line) {
    std::vector<std::string> parts;
    std::istringstream iss(line);
    std::string token;
    while (std::getline(iss, token, '|')) parts.push_back(token);
    if (parts.size() < 7) return CompteBancaire("", Client("", "", "", "", ""), 0.0);
    string numero = parts[0];
    // client parts are parts[1]..parts[5]
    Client cl = Client::deserializeFromFields(parts, 1);
    double sol = 0.0;
    try { sol = std::stod(parts[6]); } catch(...) { sol = 0.0; }
    return CompteBancaire(numero, cl, sol);
}

bool CompteBancaire::matchesCredentials(const std::string& login, const std::string& mdp) const {
    return proprietaire.getLogin() == login && proprietaire.verifierMotDePasse(mdp);
}



