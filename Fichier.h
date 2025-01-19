#ifndef FICHIER_H
#define FICHIER_H

#include "Grille.h"
#include <string>

using namespace std;

class Fichier
{
private:
    string chemin = ""; // Chemin du fichier
    // Longueur + Largeur de la grille
    int longueur = 0;
    int largeur = 0;

public:
    Fichier(); // Constructeur par défaut
    Fichier(string path); // Constructeur paramétré
    pair<int, int> getDimensions(); // Méthode pour obtenir les dimensions de la grille
    Grille creation_Grille(); // Méthode pour la création de la grille grâce au fichier
    void sauvegarderEtat(Grille &grille, const string &cheminDossier, int iteration); // Méthode pour sauvegarder l'état de la grille (mémoire)
};

#endif 