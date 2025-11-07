#include <iostream>
#include "Banque.h"
#include "Admin.h"
#include "Client.h"
//#include "CompteBancaire.h"
//#include "Utilisateur.h"
using namespace std;

int main() {
    Banque banque;
    Admin admin("Admin", "admin", "admin", "azerty");
    Client client1("RAJHONSON", "Sedra", "sedra", "4321", "96_BD_Mansart");
    Client client2("TONFEU NJODIEU", "Styve friedel", "styvy", "Nengo273@#", "carrefour tomate");
    Client client3("TETOG TATCHIM", "DJEF CABREL", "dt212649", "dt212649", "09 avenue alain savary");


    banque.creerCompte(client1, "C001", 1000);
    banque.creerCompte(client2, "C002", 500);
    banque.creerCompte(client3, "C003", 1000500);

    string login, mdp;
    cout << "=== Connexion ===\n";
    cout << "Login : ";
    cin >> login;
    cout << "Mot de passe : ";
    cin >> mdp;

    if (login == admin.getLogin() && admin.verifierMotDePasse(mdp)) {
        cout << "Bienvenue administrateur !\n";
        int choix;
        do {
            cout << "\n1. Créer un nouveau compte\n2. Afficher tous les comptes\n0. Quitter\n";
            cout << "Choix : ";
            cin >> choix;
            if (choix == 1) {
                string nom, prenom, adresse, loginClient, mdpClient, num;
                double montant;
                cout << "Nom : "; cin >> nom;
                cout << "Prénom : "; cin >> prenom;
                cout << "Adresse : "; cin >> adresse;
                cout << "Login : "; cin >> loginClient;
                cout << "Mot de passe : "; cin >> mdpClient;
                cout << "Numéro de compte : "; cin >> num;
                cout << "Montant initial : "; cin >> montant;
                Client nouveau(nom, prenom, loginClient, mdpClient, adresse);
                banque.creerCompte(nouveau, num, montant);
            } else if (choix == 2) {
                banque.afficherTousLesComptes();
            }
        } while (choix != 0);
    }

    else if (login == client1.getLogin() && client1.verifierMotDePasse(mdp)) {
        cout << "Bienvenue " << client1.getLogin() << " !\n";
        CompteBancaire* compte = banque.trouverCompte("C001");
        int choix;
        double montant;
        do {
            cout << "\n1. Dépôt\n2. Retrait\n3. Voir le solde\n0. Quitter\n";
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
            }
        } while (choix != 0);
    }

    else if (login == client2.getLogin() && client2.verifierMotDePasse(mdp)) {
        cout << "Bienvenue " << client2.getLogin() << " !\n";
        CompteBancaire* compte = banque.trouverCompte("C002");
        int choix;
        double montant;
        do {
            cout << "\n1. Dépôt\n2. Retrait\n3. Voir le solde\n0. Quitter\n";
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
            }
        } while (choix != 0);
    }

    else if (login == client3.getLogin() && client3.verifierMotDePasse(mdp)) {
        cout << "Bienvenue " << client3.getLogin() << " !\n";
        CompteBancaire* compte = banque.trouverCompte("C003");
        int choix;
        double montant;
        do {
            cout << "\n1. Dépôt\n2. Retrait\n3. Voir le solde\n0. Quitter\n";
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
            }
        } while (choix != 0);
    }


    else {
        cout << "!! Identifiants incorrects.\n";
    }

    return 0;
}
