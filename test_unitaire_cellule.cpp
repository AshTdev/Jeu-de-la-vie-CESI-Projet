#include "Cellule.h"
#include <iostream>
#include <cassert>

using namespace std;

// Constructeur par défaut
void testConstructeur() {
    Cellule c; 
    assert(c.getEtat() == 0); // Si getEtat == 0 alors --> OK
    cout << "Le constructeur est fonctionnel" << endl;
}
// Utilisation du constructeur paramétré
void testConstructeurP() {
    Cellule c(1); 
    assert(c.getEtat() == 1); // Si getEtat == 1 alors --> OK
    cout << "Le constructeur paramétré est fonctionnel" << endl;
}
// Utilisation du constructeur par défaut
void testSetEtat() {
    Cellule c; 
    c.setEtat(1); // on définit l'état de la cellule en 1
    assert(c.getEtat() == 1); // le getEtat va checker si l'état est en 1, si oui, alors --> OK
    std::cout << "Le setEtat a correctement été modifié" << std::endl;
}

int main() {
    // On fait appel aux trois méthodes, si tout est good --> OK
    testConstructeur();
    testConstructeurP();
    testSetEtat();
    cout << "Le test unitaire est positif" << endl;
    return 0;
}