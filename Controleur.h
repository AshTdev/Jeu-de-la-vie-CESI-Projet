#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include "Vue.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Controleur
{
public:
    Vue vue; // Instance de la classe Vue
    Controleur(Vue vue); // Constructeur
    void run(); // run --> exécuter la simulation
    void dossier_nettoyage(const string &cheminDossier); // Méthode qui permet le nettoyage d'un dossier
};

#endif 