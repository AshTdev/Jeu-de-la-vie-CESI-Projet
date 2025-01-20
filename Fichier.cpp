#include "Fichier.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Fichier::Fichier() // Constructeur par défaut
{
    this->longueur = 0;
    this->largeur = 0;
    this->chemin = "";
}

Fichier::Fichier(string path) // Constructeur paramétré
{
    // Lecture du fichier --> longueur + largeur
    this->chemin = path;
    ifstream fichier(chemin);
    if (fichier)
    {
        fichier >> this->longueur >> this->largeur;
    }
    else
    {
        cerr << "Erreur : impossible d'ouvrir le fichier " << chemin << endl;
    }
}

pair<int, int> Fichier::getDimensions() // getDimensions --> Méthode pour les dimensions de la grille
{
    return pair<int, int>(longueur, largeur);
}

Grille Fichier::creation_Grille() // Création d'une grille à partir du fichier fourni
{
    vector<vector<Cellule>> grille(this->longueur, vector<Cellule>(this->largeur));
    ifstream fichier(chemin);
    int valeur;
    fichier.ignore();
    for (int i = 0; i < this->longueur; i++)
    {
        for (int j = 0; j < this->largeur; j++)
        {
            fichier >> valeur;
            grille[i][j] = Cellule(valeur);
        }
    }
    return grille;
}

void Fichier::sauvegarderEtat(Grille &grille, const string &cheminDossier, int iteration) // Sauvegarde de l'état de la grille
{
    ostringstream fichierNom;
    fichierNom << cheminDossier << "/iteration_" << iteration << ".txt";

    ofstream fichier(fichierNom.str());
    if (!fichier)
    {
        cerr << "Erreur lors de la création du fichier : " << fichierNom.str() << endl;
        return;
    }

    for (int i = 0; i < grille.getLongueur(); ++i)
    {
        for (int j = 0; j < grille.getLargeur(); ++j)
        {
            fichier << grille.getValue(i, j) << " ";
        }
        fichier << endl;
    }

    fichier.close();
}
