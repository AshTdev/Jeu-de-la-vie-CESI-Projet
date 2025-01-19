#ifndef VUE_H
#define VUE_H
#include <SFML/Graphics.hpp>
#include "Grille.h"

class Vue
{
public:
    void renderGrid(sf::RenderWindow &window, Grille &grille); // Affichage de la grille
    sf::RenderWindow *initWindow(int longueur, int largeur); // Initialisation de la fenêtre
    void renderInterface(sf::RenderWindow &window, int longueur, int largeur, int delai, Grille &grille); // Affichage de l'interface
    void afficherConsole(Grille &grille); // Affichage de la grille pour le mode console
};

#endif 