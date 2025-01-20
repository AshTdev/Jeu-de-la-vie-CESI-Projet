#include "Vue.h"
#include <iostream>

using namespace std;

const int Taille_Cellule = 12;

void Vue::renderGrid(sf::RenderWindow &window, Grille &grille) 
{
    int longueur = grille.getLongueur();
    int largeur = grille.getLargeur();

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(Taille_Cellule - 1.0f, Taille_Cellule - 1.0f));
    for (int x = 0; x < longueur; ++x)
    {
        for (int y = 0; y < largeur; ++y)
        {
            if (grille.getValue(x, y) > 0)
            {
                cell.setFillColor(sf::Color::Yellow);
                cell.setPosition(y * Taille_Cellule, x * Taille_Cellule);
                if (grille.getValue(x, y) == 2)
                {
                    cell.setFillColor(sf::Color::Red);
                }
                if (grille.getValue(x, y) == 3)
                {
                    cell.setFillColor(sf::Color::Green);
                }
                window.draw(cell);
            }
        }
    }
}

sf::RenderWindow *Vue::initWindow(int longueur, int largeur) // Initialisation de la fenêtre
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(Taille_Cellule * largeur,Taille_Cellule * longueur), "Jeu de la vie");
    return window;
}

void Vue::afficherConsole(Grille &grille){
    grille.print();
} // Affichage de la grille + itérations dans le mode console
