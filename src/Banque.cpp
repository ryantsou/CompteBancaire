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
