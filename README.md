# **Phase 1 – Réflexion et Conception**

## **1️⃣ Analyse du problème**

### **Objectif**

Créer un système de gestion bancaire avec plusieurs types d’utilisateurs et des comptes bancaires sécurisés.

### **Données essentielles**

1. **Compte bancaire**

   * Numéro de compte (string)
   * Propriétaire (Client)
   * Solde (double)

2. **Utilisateur**

   * Nom, prénom
   * Login (identifiant unique)
   * Mot de passe

3. **Client** (hérite de Utilisateur)

   * Adresse / ville
   * Peut effectuer : dépôt, retrait, consultation solde

4. **Admin** (hérite de Utilisateur)

   * Peut créer de nouveaux comptes pour les clients
   * Peut afficher tous les comptes

---

## **2️⃣ Opérations à implémenter**

### **CompteBancaire**

* `deposer(double montant)` : ajouter de l’argent
* `retirer(double montant)` : retirer de l’argent si le solde le permet
* `afficherInfos()` : afficher le numéro, le solde et le propriétaire

### **Banque**

* `creerCompte(Client client, string numero, double montantInitial, bool afficherMessage = true)` : créer un compte
* `trouverCompte(string numero)` : retourner un pointeur vers le compte (ou nullptr si inexistant)
* `trouverClient(string login)` : retourner un pointeur vers le client
* `afficherTousLesComptes()` : afficher tous les comptes

### **Utilisateur / Client / Admin**

* `verifierMotDePasse(string mdp)` : vérifier les identifiants
* `afficherProfil()` : afficher nom/prénom et type (Client ou Admin)

---

## **3️⃣ Organisation des classes**

```
Utilisateur
├── Client
└── Admin

CompteBancaire
Banque
```

### **Classes et responsabilités**

| Classe               | Attributs principaux                      | Méthodes principales                                                      |
| -------------------- | ----------------------------------------- | ------------------------------------------------------------------------- |
| Utilisateur          | nom, prénom, login, motDePasse            | verifierMotDePasse(), afficherProfil()                                    |
| Client (Utilisateur) | adresse                                   | hérite de Utilisateur                                                     |
| Admin (Utilisateur)  | -                                         | afficherProfil()                                                          |
| CompteBancaire       | numeroCompte, proprietaire(Client), solde | deposer(), retirer(), afficherInfos()                                     |
| Banque               | vector<CompteBancaire>, vector<Client>    | creerCompte(), trouverCompte(), afficherTousLesComptes(), trouverClient() |

---

## **4️⃣ Encapsulation et abstraction**

* **Attributs privés** pour protéger les informations sensibles (solde, mot de passe)
* **Méthodes publiques** pour interagir avec les données (dépôt, retrait, affichage)
* **Pointeurs / vérifications** pour éviter les accès à des comptes inexistants (nullptr)

---

## **5️⃣ Diagramme simplifié UML**

```
          +-------------------+
          |  Utilisateur      |
          |-------------------|
          | - nom             |
          | - prenom          |
          | - login           |
          | - motDePasse      |
          |-------------------|
          | + verifierMDP()   |
          | + afficherProfil()|
          +--------+----------+
                   |
          -----------------
          |               |
       +-------+       +--------+
       | Client|       | Admin  |
       +-------+       +--------+
       | -      adresse       - | 
       +------------------------+
       
+-------------------+
|  CompteBancaire   |
|-------------------|
| - numeroCompte    |
| - proprietaire    |
| - solde           |
|-------------------|
| + deposer()       |
| + retirer()       |
| + afficherInfos() |
+-------------------+

+------------------+
|     Banque       |
|------------------|
| - comptes        |
| - clients        |
|------------------|
| + creerCompte()  |
| + trouverCompte()|
| + afficherTous() |
| + trouverClient()|
+------------------+
```

---

## **6️⃣ Liste des méthodes à implémenter**

### **CompteBancaire**

* `deposer(double montant)`
* `retirer(double montant)`
* `afficherInfos()`
* `getNumero()`
* `getSolde()`
* `getProprietaire()`

### **Utilisateur**

* `verifierMotDePasse(string mdp)`
* `afficherProfil()`

### **Client / Admin**

* `afficherProfil()` (override)

### **Banque**

* `creerCompte(Client client, string numero, double montantInitial, bool afficherMessage = true)`
* `trouverCompte(string numero)`
* `trouverClient(string login)`
* `afficherTousLesComptes()`
* `ajouterClient(Client client)`

---

## **7️⃣ Plan de travail pour implémentation**

1. Créer les classes **Utilisateur, Client, Admin**
2. Créer la classe **CompteBancaire**
3. Créer la classe **Banque**
4. Implémenter les opérations de base (dépôt, retrait, affichage)
5. Implémenter la création de comptes par l’Admin
6. Implémenter la connexion avec login/mot de passe
7. Mettre en place un **menu pour Admin et Client**
8. Tester avec plusieurs clients
9. Ajouter option pour **créer des comptes sans message automatique** (bool afficherMessage)
10. Vérifier les cas limites (solde insuffisant, compte inexistant)
