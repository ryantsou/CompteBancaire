#include <iostream>
#include "Banque.h"
#include "Admin.h"
#include "Client.h"
#include "Menu.h"
using namespace std;

int main() {
    Banque banque;
    // Charger les comptes sauvegardés (s'il y en a)
    banque.chargerComptes();
    Admin admin("Admin", "admin", "admin", "azerty");
    Client client1("RAJHONSON", "Sedra", "sedra", "4321", "96_BD_Mansart");
    Client client2("TONFEU NJODIEU", "Styve friedel", "styvy", "Nengo273@#", "carrefour tomate");
    Client client3("TETOG TATCHIM", "DJEF CABREL", "dt212649", "dt212649", "09 avenue alain savary");


    // Si aucun compte n'existe (première exécution), créer des comptes de démonstration
    if (!banque.trouverCompte("C001")) banque.creerCompte(client1, "C001", 1000);
    if (!banque.trouverCompte("C002")) banque.creerCompte(client2, "C002", 500);
    if (!banque.trouverCompte("C003")) banque.creerCompte(client3, "C003", 1000500);

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
            cout << "\n1. Créer un nouveau compte\n2. Afficher tous les comptes\n3. Supprimer un compte\n0. Quitter\n";
            cout << "Choix : ";
            cin >> choix;
            switch(choix) {
                case 1: {
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
                    break;
                }
                case 2:
                    banque.afficherTousLesComptes();
                    break;
                case 3: {
                    string numCompte;
                    cout << "Numéro du compte à supprimer : ";
                    cin >> numCompte;
                    banque.supprimerCompte(numCompte);
                    break;
                }
            }
        } while (choix != 0);
    }

    else {
        // Chercher un compte correspondant aux identifiants
        CompteBancaire* compte = banque.trouverCompteParCredentials(login, mdp);
        if (compte) {
            cout << "Bienvenue " << login << " !\n";
            menuClient(banque, compte->getNumero(), login);
        } else {
            cout << "!! Identifiants incorrects.\n";
        }
    }

    return 0;
}
