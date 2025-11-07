### ESIREM ###
###--------------------###
### 1️⃣ `Utilisateur` (Utilisateur.cpp / Utilisateur.h)

* **Rôle** : Classe de base pour tout utilisateur du système (Client ou Admin)

# CompteBancaire — mini-projet de gestion bancaire

Ce dépôt contient une petite application C++ pour gérer des comptes bancaires, des clients et un administrateur en ligne de commande. Le projet a évolué pour inclure :

- un module de persistence simple (fichier `comptes.txt`)
- une séparation de l'interface menu (`Menu.h` / `Menu.cpp`)
- sérialisation / désérialisation des comptes pour sauvegarder/charger l'état

Ce README documente l'architecture actuelle, comment compiler/exécuter, le format de sauvegarde, et quelques recommandations.

## Arborescence principale

src/
- Admin.cpp / Admin.h
- Client.cpp / Client.h
- CompteBancaire.cpp / CompteBancaire.h
- Banque.cpp / Banque.h
- Menu.cpp / Menu.h        # menu client déplacé ici
- main.cpp
- comptes.txt              # fichier de persistence (généré/lu par la banque)


## Architecture (résumé)

- `Utilisateur` : base pour `Client` et `Admin` (nom, prénom, login, motDePasse)
- `Client` : ajoute l'adresse et l'affichage spécifique
- `Admin` : utilisateur avec droits d'administration
- `CompteBancaire` : numéro, propriétaire (`Client`), solde; opérations dépôt/retrait et sérialisation
- `Banque` : container des comptes et responsabilité de la persistance (sauver/charger)
- `Menu` : interface textuelle pour les clients (déplacée dans `Menu.cpp`/`Menu.h`)


## Compilation

Depuis le répertoire `src/` :

```sh
g++ *.cpp -o banque
```

Cela produit le binaire `banque` dans `src/`.


## Exécution

Lancer le binaire :

```sh
./banque
```

Au démarrage, le programme charge `comptes.txt` s'il existe. Si aucun compte n'est présent, des comptes de démonstration sont créés.


## Authentification

- Admin : login `admin`, mot de passe `azerty` (codé en dur pour le moment)
- Les clients : login et mot de passe sont stockés dans `comptes.txt` (voir format ci‑dessous)

Vous pouvez vous authentifier en entrant votre login et mot de passe à l'invite.


## Format du fichier `comptes.txt`

Chaque ligne représente un compte et suit le format (séparateur `|`) :

```
numero|nom|prenom|login|motDePasse|adresse|solde
```

Exemple :

```
C001|RAJHONSON|Sedra|sedra|4321|96_BD_Mansart|1000.00
C004|Caroline|Andriaparany|caro|caro|Antananarivo|4000.00
```

Remarques :
- Le projet utilise une sérialisation simple ; si vos champs peuvent contenir `|`, remplacez ou échappez ce caractère.
- Les mots de passe sont actuellement stockés en clair (voir section Sécurité ci‑dessous).


## Fonctionnalités principales

- Création de compte (admin)
- Affichage de tous les comptes (admin)
- Suppression de compte (admin)
- Dépôt / Retrait / Consultation de solde (clients)
- Transfert entre comptes
- Persistance automatique : la banque appelle `sauverComptes()` après les opérations mutantes


## Sécurité et améliorations recommandées

1. Ne pas stocker les mots de passe en clair : implémenter un hachage (bcrypt recommandé). Je peux mettre en place un hachage simple (SHA‑256) ou intégrer bcrypt si vous le souhaitez.
2. Utiliser JSON (ex. nlohmann/json) pour une persistance plus robuste, avec échappement automatique des champs.
3. Ajouter des tests unitaires pour dépôt/retrait/transfert/sauvegarde‑chargement.
4. Ajouter confirmation interactive avant suppression de compte (sécurité UX).


## Notes développeur

- Le menu client a été déplacé dans `Menu.h` / `Menu.cpp` pour séparer la logique UI du `main`.
- La persistance est gérée par `Banque::sauverComptes()` et `Banque::chargerComptes()` ; le format est la responsabilité de `CompteBancaire::serialize()` / `CompteBancaire::deserialize()` et `Client::serializeFields()` / `Client::deserializeFromFields()` pour garder l'encapsulation.


## Commandes utiles

```sh
cd src
g++ *.cpp -o banque   # compiler
./banque              # lancer
```


Si vous voulez que je :

- remplace la persistance par JSON,
- hache les mots de passe avant sauvegarde,
- ajoute la confirmation avant suppression,
- ou génère des tests unitaires — dites‑moi et je l'implémente.
      | + ajouterClient()          |

