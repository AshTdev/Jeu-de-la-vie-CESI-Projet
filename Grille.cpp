#include "Grille.h"
#include <iostream>
using namespace std;

Grille::Grille() // Constructeur par défaut
{
    this->grille = {{}};
}

Grille::Grille(vector<vector<Cellule>> g) : grille(g) {} // Constructeur paramétré

int Grille::getValue(int L, int l) // getValue --> obtenir l'état de la cellule
{
    return this->grille[L][l].getEtat();
}

void Grille::setValue(int L, int l, int valeur) // setValue --> définir l'état de la cellule
{
    grille[L][l].setEtat(valeur);
}

void Grille::print() // print --> affichage de la grille
{
    for (int i = 0; i < grille.size(); i++)
    {
        for (int j = 0; j < grille[0].size(); j++)
        {
            cout << grille[i][j].getEtat() << " ";
        }
        cout << endl;
    }
}

int Grille::AliveNeighbors(int x, int y) // AliveNeighbors --> compter les voisins vivants (cité avant)
{
    int nombre = 0;
    int rows = grille.size();
    int cols = grille[0].size();

    for (int i = x - 1; i <= x + 1; i++)
    { 
        for (int j = y - 1; j <= y + 1; j++)
        {
            int grille_torique_X = (i + rows) % rows; 
            int grille_torique_Y = (j + cols) % cols; 
            if (grille[grille_torique_X][grille_torique_Y].getEtat() == 1 || grille[grille_torique_X][grille_torique_Y].getEtat() == 3)
            {
                nombre++;
            }
        }
    }

    return nombre - grille[x][y].getEtat(); 
}

int Grille::getLongueur() // getLongueur --> Obtenir la longueur de la grille
{
    return this->grille.size();
}

int Grille::getLargeur() // getLargeur --> Obtenir la largeur de la grille
{
    return this->grille[0].size();
}

bool Grille::etatSimulation() // etatSimulation --> On vérifie si la simulation est active ou pas
{
    return this->Simulation;
}

void Grille::run() // Méthode pour exécuter une itération de la simulation
{
    vector<vector<Cellule>> grille_new = grille;
    for (int i = 0; i < grille.size(); i++)
    {
        for (int j = 0; j < grille[0].size(); j++)
        {
            if (grille[i][j].getEtat() == 1)
            {
                grille_new[i][j] = Cellule(AliveNeighbors(i, j) == 2 || AliveNeighbors(i, j) == 3);
            }
            else if (grille[i][j].getEtat() == 0)
            {
                grille_new[i][j] = Cellule(AliveNeighbors(i, j) == 3);
            }
        }
    }
    if (grille == grille_new)
    {
        Simulation = false;
    }

    grille = grille_new;
}