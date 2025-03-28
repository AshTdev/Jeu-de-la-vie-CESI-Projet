# ❗"Lifegame" - Projet POO en C++❗

## 📜 **Sommaire**

- I/ Introduction du jeu de la vie
      
- II/ Règles du jeu de la vie
      
- III/ Fonctionnalité du programme
      
   -  A / Lecture du fichier ( création de la grille )
   -  B / Mode console ou mode graphique ? 

-  IV/ Langages et bibliothèques
  
-  V/ Présentation des fonctions dans la structure de notre programme

-  VI/ Légende
      
-  VII/ Extensions présentes
      
-  VIII/ Comment lancer le jeu

----------------------
##  **🪴I/ Introduction du jeu de la vie**

Le "Jeu de la vie" est un automate cellulaire (un modèle où l'état d'une entité conduit à un nouvel état en se fixant sur des règles) qui a été imaginé par M.Conway, un mathématicien britannique en 1970. Notre projet consiste donc à développer le jeu de la vie en appliquant les notions de la POO avec le langage de programmation C++.

Le jeu consiste à placer des cellules dans une grille et de les caractériser par deux états qui sont :
-  **Cellule morte**
-  **Cellule vivante**

Ainsi, lorsque les cellules vivantes sont placées, on lance une simulation et on observe les changements d'état, et plus globalement, l'évolution de nos cellules.

----------------------

## **📏 II/ Règles du jeu de la vie**

Une cellule possède huit cellules voisines (2 cellules horizontales, 2 cellules verticales, 4 cellules diagonales) :
- ◼️◼️◼️ 
- ◼️◻️◼️ 
- ◼️◼️◼️

A chaque itération, on définit l'état d'une cellule en fonction de l'état de ses huit cellules voisines, avec les règles suivantes :

-  Une cellule *morte* (0) qui possède *exactement* trois cellules voisines vivantes devient vivante (1).
-  Une cellule *vivante* (1) qui ne possède pas *exactement* deux/trois cellules voisines vivantes devient une cellule morte (0).

<p align="center">
  <img src="https://github.com/user-attachments/assets/a8637444-208c-466c-8484-63e368080606" alt="Game of Life">
</p>

--------------------

## **⚙️ III/ Fonctionnalités du programme**

### **A/ Lecture du fichier (création de la grille)**

Avant le démarrage de la simulation, le programme demande à l'utilisateur un fichier qui comprend les dimensions de la grille, ainsi que la matrice (0 ou 1 + obstacles)

Note : Le fichier doit être un .txt

### **B/ Mode console ou mode graphique ? 🤔**

Lorsqu'on envoie le fichier, le programme demande à l'utilisateur de faire le choix entre le mode graphique et le mode console.

### Mode Console
----------
-  Le programme reçoit le fichier contenant la matrice et les dimensions.
-  L'utilisateur initialise le nombre d'itérations
-  Le programme crée un dossier au nom du fichier donné où le nombre d'itérations défini par l'utilisateur sera stocké.


![image](https://github.com/user-attachments/assets/6558483c-96b6-4c1b-b587-5d56e43469a7)


Exemple : 5 Itérations demandées par l'utilisateur --> 5 fichiers logs produits
----------

### Mode Graphique (bibliothèque SFML)

----------
-  Le programme reçoit le fichier contenant la matrice et les dimensions.
-  Le programme utilise la bibliothèque SFML afin de représenter en direct l'évolution de la simulation.
-  La simulation s'arrête lorsqu'il n'y a plus d'évolution possible des cellules.
-  On peut accélerer ou décélérer avec les flèches de gauche et de droite du clavier.

![image](https://github.com/user-attachments/assets/ab56ee01-bede-41ae-a281-5a452a9c4471)


##  **📚 IV/ Langages et bibliothèques**

-  C++ standard
-  Bibliothèque graphique "SFML" pour afficher le jeu.

## **🚧 V/ Présentation des fonctions dans la structure de notre programme**
Dans le cadre de ce rattrapage, le modèle MVC a été appliqué.

- ```main.cpp``` : Exécute la simulation, point d'entrée de notre programme.  

- ```Cellule.cpp | Cellule.h``` : S'occupe de l'état de chaque cellule dans la grille.

- ```Grille.cpp | Grille.h``` : Affichage de la grille de cellules

- ```Fichier.cpp | Fichier.h``` : Permet de lire l'état initial des cellules, les dimensions + écrire les états de la grille dans le mode console

- ```Controleur.cpp | Controleur.h``` : Exécute et contrôle la simulation (le coeur du programme)

- ```Vue.cpp | Vue.h``` : Gère l'affichage de la grille & interface utilisateur

- ```Input.txt``` : Un fichier texte qui sert d'exemple, elle décrit notamment les dimensions de la grille ainsi que les différentes cellules présentes + obstacles

- ```test_unitaire_cellule.cpp``` : Test unitaire qui pose des conditions pour voir si elles sont bien respectées, permet de s'assurer du bon fonctionnement d'un bout de code, en l'occurence, le test unitaire se base sur la classe "Cellule"

## **🧭 VI/ Légende**

- **1** : Correspond à une cellule **vivante** --> la couleur d'une cellule vivante est en **jaune**  
- **0** : Correspond à une cellule **morte** --> la couleur d'une cellule vivante est en **noir**  
- **3** : Correspond à un obstacle **vivant** --> la couleur de cet obstacle est en **vert**  
- **2** : Correspond à un obstacle **mort** --> la couleur de cet obstacle est en **rouge**  

## **🌻 VII/ Extensions présentes**

✅ Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes.  

✅ Introduction de cellules obstacle. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de base.  


## **✈️ VIII/ Comment lancer le jeu**

1. **Ouvrez votre terminal** (Sur Linux - Ubuntu)  
2. **Accédez aux fichiers** grâce à la commande `cd` :  
   ```bash
   cd chemin/vers/le/dossier 
3 **Compiler le jeu**
- Lorsque vous serez dans le dossier contenant le programme, compilez le script grace à cette commande dans le terminal :
```bash
make
```
-Puis, une fois le code compilé, utilisez cette commande dans le même dossier :
```bash
./main
```
- Pour le test unitaire :
```bash
make test
```
-Puis :
```bash
./test_unitaire_cellule
```
