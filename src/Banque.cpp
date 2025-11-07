#include "Banque.h"
#include <iostream>
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

//jereo aloha raha efa misy ilay compte    
//    cout << "Compte créé avec succès pour " << client.getLogin() << " !\n";
}

void Banque::supprimerCompte(string numero) {
    for (auto it = comptes.begin(); it != comptes.end(); ++it) {
        if (it->getNumero() == numero) {
            comptes.erase(it);
            cout << "Compte " << numero << " supprimé avec succès.\n";
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
    cout << "✅ Transfert de " << montant << "€ effectué avec succès.\n";
    return true;
}
