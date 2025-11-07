------------------------------------------------------------------------------------------------------------------

 **Rôle** : Classe de base pour tout utilisateur du système (Client ou Admin)

# Instructions — CompteBancaire

**COMPILATION**
---------
1. Ouvrez un terminal et placez-vous dans le dossier `src/` du projet.

2. Compilez :

```sh
g++ *.cpp -o banque
```

Exécution
---------
Lancez le binaire depuis `src/` :

```sh
./banque
```

Connexion
---------
1. Au démarrage, entrez votre `login` puis votre `mot de passe`.
2. Comptes disponibles :
       - Admin : login `admin`, mot de passe `azerty`
       - Clients : login/motDePasse définis dans `comptes.txt`

Menus et actions
-----------------
- Admin (après connexion) :
      1) Créer un nouveau compte — fournir : nom, prénom, adresse, login, mot de passe, numéro, montant initial.
      2) Afficher tous les comptes.
      3) Supprimer un compte — saisir le `numéro` du compte (ex. `C001`, `C004`).

- Client (après connexion) :
      1) Dépôt — entrer le montant.
      2) Retrait — entrer le montant.
      3) Voir le solde.
      4) Transfert — numéro de compte destination + montant.

Persistance
-----------
Le fichier de persistance est `comptes.txt` (créé/lu dans le répertoire d'exécution). Chaque ligne correspond à un compte :

```
numero|nom|prenom|login|motDePasse|adresse|solde
```

Exemple :

```
C001|RAJHONSON|Sedra|sedra|4321|96_BD_Mansart|1000.00
```

Commandes rapides
-----------------
```sh
cd src
g++ *.cpp -o banque
./banque
```
