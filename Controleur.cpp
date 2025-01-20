#include "Controleur.h"
#include <iostream>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include "Fichier.h"
#include "Vue.h"

namespace syst = std::filesystem;
using namespace std;

const int Taille_Cellule = 12;

void Controleur::dossier_nettoyage(const string &cheminDossier) // Pour s'assurer que le dossier est vide avant de créer un dossier de sortie
{
    if (syst::exists(cheminDossier))
    {
        syst::remove_all(cheminDossier);
    }
    syst::create_directory(cheminDossier);
}

Controleur::Controleur(Vue vue) // Constructeur
{
    this->vue = vue;
}

void Controleur::run() 
{
    string nom_fichier;
    cout << "Veuillez entrer le nom du fichier en précisant l'extension txt.\n";
    cin >> nom_fichier;

    int delai = 10;

    if (!syst::exists(nom_fichier))
    {
        cerr << "Erreur, le fichier n'a pas été correctement saisi, veuillez réessayer" << endl;
        return;
    }

    Fichier fichier{nom_fichier};
    int longueur = fichier.getDimensions().first;
    int largeur = fichier.getDimensions().second;
    Grille grille;
    grille = fichier.creation_Grille();

    cout << "Veuillez sélectionner le mode :\n 1. Mode Console (sauvegarde comprise)  \n 2. Mode graphique \n";
    int choix;
    cin >> choix;

    if (choix == 1) // Mode Console
    {
        string resultat = nom_fichier + "_out";
        dossier_nettoyage(resultat);

        int iterations;
        cout << "Veuillez choisir le nombre d'itérations. \n";
        cin >> iterations;

        for (int i = 0; i < iterations && grille.etatSimulation(); ++i)
        {
            this->vue.afficherConsole(grille);

            fichier.sauvegarderEtat(grille, resultat, i);
            grille.run();
        }

        cout << "Fin de la simulation. Logs présents dans le dossier : " << resultat << endl;
    }
    else if (choix == 2) // Mode Graphique
    {
        sf::RenderWindow *window = vue.initWindow(longueur, largeur);
        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window->close();
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Right:
                        delai = min(delai + 1, 10);
                        break; 
                    case sf::Keyboard::Left:
                        delai = max(delai - 1, 1);
                        break;
                    default:
                        break;
                    }
                }
            }
            vue.renderGrid(*window, grille);
            if (grille.etatSimulation())
            {
                grille.run();
            }
            window->display();
            sf::sleep(sf::milliseconds(delai * 10));
        }
    }
    else
    {
        cerr << "Erreur. Veuillez choisir entre le mode console ou le mode graphique." << endl;
        return;
    }
}
