#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>

using namespace std;

class Grille
{
public:
    Grille(); // Constructeur par défaut
    Grille(vector<vector<Cellule>> g); // Constructeur paramétré

    // getLongueur / Largeur --> pour obtenir la longueur et largeur de la grille + etatSimulation --> pour vérifier si la simulation est active ou pas
    int getLongueur(); 
    int getLargeur(); 
    bool etatSimulation(); 

    //////////////////////////////////////////////////////////////////////

    // getValue - setValue --> Obtenir l'état / Definir l'état d'une cellule 

    int getValue(int L, int l); // Méthode pour obtenir l'état d'une cellule
    void setValue(int L, int l, int valeur); // Méthode pour définir l'état d'une cellule

    //////////////////////////////////////////////////////////////////////


    int AliveNeighbors(int x, int y); // AliveNeighbors et ses coordonnées pour compter le nombre de voisins vivants autour d'une cellule
    void run(); // Méthode pour exécuter une itération de la simulation
    void print(); // print --> Affichage de la grille

private:
    vector<vector<Cellule>> grille; 
    bool Simulation = true; // État de la simulation
};

#endif 