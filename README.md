### ESIREM ###
###--------------------###
### 1️⃣ `Utilisateur` (Utilisateur.cpp / Utilisateur.h)

* **Rôle** : Classe de base pour tout utilisateur du système (Client ou Admin)
* **Attributs privés** :

  * `nom`, `prenom`
  * `login` (identifiant unique)
  * `motDePasse`
* **Méthodes publiques** :

  * `verifierMotDePasse(string mdp)` → renvoie `true` si le mot de passe correspond
  * `afficherProfil()` → affiche nom et prénom
* **Héritage** : base pour `Client` et `Admin`

---

### 2️⃣ `Client` (Client.cpp / Client.h)

* **Rôle** : Représente un utilisateur simple
* **Attributs spécifiques** :

  * `adresse` ou `ville`
* **Méthodes spécifiques** :

  * `afficherProfil()` (override) → affiche profil + adresse
* **Héritage** : hérite de `Utilisateur`

---

### 3️⃣ `Admin` (Admin.cpp / Admin.h)

* **Rôle** : Utilisateur spécial qui peut gérer la banque
* **Méthodes spécifiques** :

  * `afficherProfil()` (override)
  * peut créer des comptes pour les clients via `Banque`
* **Héritage** : hérite de `Utilisateur`
* **Pas d’attributs spécifiques pour l’instant**

---

### 4️⃣ `CompteBancaire` (CompteBancaire.cpp / CompteBancaire.h)

* **Rôle** : Représente un compte bancaire avec solde et opérations
* **Attributs privés** :

  * `numeroCompte` (string)
  * `proprietaire` (Client)
  * `solde` (double)
* **Méthodes publiques** :

  * `deposer(double montant)` → ajoute de l’argent
  * `retirer(double montant)` → retire de l’argent si possible
  * `afficherInfos()` → affiche numéro, solde et propriétaire
  * `getNumero()`, `getSolde()`, `getProprietaire()`

---

### 5️⃣ `Banque` (Banque.cpp / Banque.h)

* **Rôle** : Gère tous les comptes et tous les clients
* **Attributs privés** :

  * `vector<CompteBancaire> comptes`
  * `vector<Client> clients`
* **Méthodes publiques** :

  * `creerCompte(Client client, string numero, double montantInitial, bool afficherMessage = true)`
  * `trouverCompte(string numero)` → retourne pointeur vers le compte (ou nullptr)
  * `trouverClient(string login)` → retourne pointeur vers le client (ou nullptr)
  * `ajouterClient(Client client)` → ajoute un client à la banque
  * `afficherTousLesComptes()`

---

### 6️⃣ `main.cpp`

* **Rôle** : Point d’entrée du programme, gère :

  * Connexion des utilisateurs (login + mot de passe)
  * Menu dynamique selon type (Admin ou Client)
  * Appel aux méthodes de `Banque` et `CompteBancaire`

---

### 3️⃣ `Organisation des classes`

               +--------------------+
               |  Utilisateur       |  <-- Utilisateur.cpp / Utilisateur.h
               |--------------------|
               | - nom              |
               | - prenom           |
               | - login            |
               | - motDePasse       |
               |--------------------|
               | + verifierMDP()    |
               | + afficherProfil() |
               +--------+-----------+
                        ^
                        |
            ----------------------------------------------------------------
            |                                                              |
       +-------------------+                                +--------------------+ 
       | Client            |                                |  CompteBancaire    |
       |-------------------|                                |--------------------|
       | - adresse         |                                | - numeroCompte     |
       |-------------------|                                | - proprietaire     |
       | + afficherProfil()|                                | - solde            |
       +-------------------+                                |--------------------|
            |                                               | + deposer()        |
      +-------------------------------+                     | + retirer()        |
      | Admin                         |                     | + afficherInfos()  |
      |-------------------------------|                     | + getNumero()      |
      | - (aucun attribut spécifique) |                     | + getSolde()       |
      |-------------------------------|                     | + getProprietaire()|
      | + afficherProfil()            |                     +--------------------+
      +-------------------------------+                              |
        |                                                            |
        |                                                             |
      +----------------------------+                                 |
      |     Banque                 |  <------------------------------|
      |----------------------------|
      | - comptes                  | vector<CompteBancaire>
      | - clients                  | vector<Client>
      |----------------------------|
      | + creerCompte()            |
      | + ajouterClient()          |
      | + trouverCompte()          |
      | + trouverClient()          |
      | + afficherTousLesComptes() |
      +----------------------------+




## **📌 Synthèse des relations**

* `Client` et `Admin` héritent de `Utilisateur`
* `CompteBancaire` contient un `Client` comme propriétaire
* `Banque` contient :

  * tous les `Client` existants
  * tous les `CompteBancaire`
* `main.cpp` utilise `Banque`, `Client`, `Admin`, `CompteBancaire` pour orchestrer le programme

