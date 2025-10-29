#include "CompteBancaire.h"
#include <iostream>
using namespace std;

CompteBancaire::CompteBancaire(string numero, Client client, double montantInitial)
    : numeroCompte(numero), proprietaire(client), solde(montantInitial) {}

void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        cout << " !! Montant invalide !" << endl;
        return;
    }
    solde += montant;
    cout << "Dépôt de " << montant << " € effectué. Nouveau solde : " << solde << " €." << endl;
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
        cout << " !! Retrait de " << montant << " € effectué. Nouveau solde : " << solde << " €." << endl;
    }
}

void CompteBancaire::afficherInfos() const {
    cout << "\n=== Informations du compte ===" << endl;
    cout << "Numéro de compte : " << numeroCompte << endl;
    cout << "Propriétaire : ";
    proprietaire.afficherProfil();
    cout << "Solde actuel : " << solde << " €" << endl;
}

string CompteBancaire::getNumero() const {
    return numeroCompte;
}

double CompteBancaire::getSolde() const {
    return solde;
}

Client CompteBancaire::getProprietaire() const {
    return proprietaire;
}
