# 🧠 Phase 1 – Réflexion
## 1. Analyse du problème

Le système doit permettre de **gérer plusieurs comptes bancaires**, chacun associé à un client, un numéro de compte et un solde.  
Des opérations de base doivent être possibles :

- Crédits (ajouts d’argent),
    
- Retraits (retraits d’argent si solde suffisant),
    
- Transferts (d’un compte à un autre),
    
- Affichage des informations du compte.
    

---

## 2. Données à stocker

### a. Classe `Client`

Représente le propriétaire d’un compte bancaire.

| Attribut   | Type          | Description                  |
| ---------- | ------------- | ---------------------------- |
| `nom`      | `std::string` | Nom du client                |
| `prenom`   | `std::string` | Prénom du client             |
| `adresse`  | `std::string` | Adresse postale              |
| `idClient` | `int`         | Identifiant unique du client |

**Méthodes possibles :**

- `afficherInfos()` : affiche les informations du client.
    
- (optionnel) `modifierAdresse(std::string nouvelleAdresse)`.
    

---

### b. Classe `CompteBancaire`

Représente un compte bancaire individuel.

| Attribut       | Type          | Description                      |
| -------------- | ------------- | -------------------------------- |
| `numeroCompte` | `std::string` | Identifiant unique du compte     |
| `proprietaire` | `Client`      | Client propriétaire du compte    |
| `solde`        | `double`      | Montant disponible sur le compte |

**Méthodes publiques :**

- `crediter(double montant)` → ajoute de l’argent au compte.
    
- `debiter(double montant)` → retire de l’argent si le solde est suffisant.
    
- `transferer(CompteBancaire &autreCompte, double montant)` → déplace de l’argent d’un compte à un autre.
    
- `afficherInfos()` → affiche les infos du compte (numéro, client, solde).
    
- (optionnel) `getSolde()` → retourne le solde (lecture seule).
    

**Règles :**

- Le solde ne peut pas être négatif.
    
- L’accès direct au solde doit être interdit (utilisation de getters/setters).
    

---

## 3. Encapsulation et abstraction

- Les attributs sont **privés** (`private`) pour éviter toute modification directe.
    
- Les opérations sur le solde passent uniquement par des **méthodes publiques** qui contrôlent les valeurs (encapsulation).
    
- Les méthodes de transfert utilisent les méthodes `debiter` et `crediter` pour respecter la cohérence.
    

---

## 4. Diagramme UML simplifié

```
+-------------------+
|      Client       |
+-------------------+
| - idClient : int  |
| - nom : string    |
| - prenom : string |
| - adresse : string|
+-------------------+
| + afficherInfos() |
+-------------------+

           1
           |
           |
           *
+--------------------------+
|     CompteBancaire       |
+--------------------------+
| - numeroCompte : string  |
| - proprietaire : Client  |
| - solde : double         |
+--------------------------+
| + crediter(montant)      |
| + debiter(montant)       |
| + transferer(compte, mnt)|
| + afficherInfos()        |
+--------------------------+
```

---

## 5. Plan de travail pour l’implémentation (et versioning Git)

| Étape | Tâche                                        | Commande Git suggérée                                               |
| ----- | -------------------------------------------- | ------------------------------------------------------------------- |
| 1     | Création du dépôt et des fichiers            | `git init`, `git add .`, `git commit -m "Initialisation du projet"` |
| 2     | Implémentation de la classe `Client`         | `git commit -m "Ajout de la classe Client"`                         |
| 3     | Implémentation de la classe `CompteBancaire` | `git commit -m "Création de la classe CompteBancaire"`              |
| 4     | Ajout des méthodes `crediter` et `debiter`   | `git commit -m "Ajout des méthodes de crédit et retrait"`           |
| 5     | Ajout du transfert entre comptes             | `git commit -m "Ajout de la méthode transferer"`                    |
| 6     | Ajout de la fonction `afficherInfos`         | `git commit -m "Ajout de l’affichage des infos du compte"`          |
| 7     | Tests et corrections                         | `git commit -m "Tests unitaires et corrections"`                    |
| 8     | Refactorisation et amélioration du code      | `git branch refactor`, puis `git merge refactor`                    |

---

## 6. Possibilités d’extension
    
- Classe `Banque` pour **gérer plusieurs comptes**.
        
- Interface utilisateur en ligne de commande.
    

---
