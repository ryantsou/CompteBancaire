#include "Menu.h"
#include "Banque.h"
#include "CompteBancaire.h"
#include <iostream>

using namespace std;

void menuClient(Banque& banque, const string& numeroCompte, const string& loginClient) {
    CompteBancaire* compte = banque.trouverCompte(numeroCompte);
    if (!compte) {
        cout << "Erreur : compte non trouvé.\n";
        return;
    }

    int choix;
    double montant;
    do {
        cout << "\n1. Dépôt\n2. Retrait\n3. Voir le solde\n4. Transfert\n0. Quitter\n";
        cout << "Choix : ";
        cin >> choix;
        switch (choix) {
            case 1:
                cout << "Montant à déposer : "; cin >> montant;
                compte->deposer(montant);
                break;
            case 2:
                cout << "Montant à retirer : "; cin >> montant;
                compte->retirer(montant);
                break;
            case 3:
                compte->afficherInfos();
                break;
            case 4: {
                string numDest;
                cout << "Numéro de compte destination : "; cin >> numDest;
                cout << "Montant à transférer : "; cin >> montant;
                banque.transfererArgent(numeroCompte, numDest, montant);
                break;
            }
        }
    } while (choix != 0);
}
