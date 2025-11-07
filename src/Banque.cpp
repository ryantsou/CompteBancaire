#include "Banque.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void Banque::ajouterCompte(const CompteBancaire &compte) {
    comptes.push_back(compte);
}

CompteBancaire* Banque::trouverCompte(string numero) {
    for (auto &c : comptes) {
        if (c.getNumero() == numero)
            return &c;
    }
    return nullptr;
}

CompteBancaire* Banque::trouverCompteParCredentials(const std::string& login, const std::string& mdp) {
    // recherche insensitive pour le login (pour éviter les erreurs de casse de l'utilisateur)
    auto toLower = [](std::string s){
        for (auto &ch : s) ch = std::tolower((unsigned char)ch);
        return s;
    };
    std::string loginLower = toLower(login);
    for (auto &c : comptes) {
        // comparer login en lowercase, mot de passe en sensitif
        // récupérer le login du proprietaire via le serialize/deserialize intern
        // on utilise matchesCredentials mais en vérifiant seulement le login insensible
        // puis verifier le mot de passe
        // pour obtenir le login du proprietaire, on désérialise la ligne du compte
        // (mais on peut récupérer via c.serialize parsing) — plus simple :
        // use c.deserialize or parse serialize output
        std::string line = c.serialize();
        // line format: numero|nom|prenom|login|mdp|adresse|solde
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, '|')) parts.push_back(token);
        if (parts.size() >= 4) {
            std::string ownerLogin = parts[3];
            if (toLower(ownerLogin) == loginLower) {
                if (c.matchesCredentials(ownerLogin, mdp)) return &c;
            }
        }
    }
    return nullptr;
}

void Banque::afficherTousLesComptes() const {
    if (comptes.empty()) {
        cout << "Aucun compte enregistré.\n";
        return;
    }
    for (const auto &c : comptes)
        c.afficherInfos();
}

void Banque::creerCompte(Client client, string numero, double montantInitial) {
    comptes.push_back(CompteBancaire(numero, client, montantInitial));
    // Sauvegarde après création
    sauverComptes();
}

void Banque::supprimerCompte(string numero) {
    for (auto it = comptes.begin(); it != comptes.end(); ++it) {
        if (it->getNumero() == numero) {
            comptes.erase(it);
            cout << "Compte " << numero << " supprimé avec succès.\n";
            sauverComptes();
            return;
        }
    }
    cout << "❌ Compte introuvable.\n";
}

bool Banque::transfererArgent(string numeroSource, string numeroDestination, double montant) {
    CompteBancaire* source = trouverCompte(numeroSource);
    CompteBancaire* destination = trouverCompte(numeroDestination);
    
    if (!source) {
        cout << "❌ Compte source introuvable.\n";
        return false;
    }
    if (!destination) {
        cout << "❌ Compte destination introuvable.\n";
        return false;
    }
    if (source->getSolde() < montant) {
        cout << "❌ Solde insuffisant.\n";
        return false;
    }
    
    source->retirer(montant);
    destination->deposer(montant);
    cout << "✅ Transfert de " << fixed << setprecision(2) << montant << "€ effectué avec succès.\n";
    sauverComptes();
    return true;
}

void Banque::sauverComptes() const {
    std::ofstream ofs("comptes.txt");
    if (!ofs) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier de sauvegarde.\n";
        return;
    }
    for (const auto &c : comptes) {
        ofs << c.serialize() << "\n";
    }
}

void Banque::chargerComptes() {
    comptes.clear();
    std::ifstream ifs("comptes.txt");
    if (!ifs) return; // pas de fichier, rien à charger
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        comptes.push_back(CompteBancaire::deserialize(line));
    }
}
