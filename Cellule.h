#ifndef CELLULE_H
#define CELLULE_H

class Cellule
{
public:
    Cellule(); // Constructeur par défaut
    Cellule(int etat); // Constructeur paramétré
    void setEtat(int etat); // setEtat --> définir l'état d'une cellule
    int getEtat() const; // getEtat --> obtenir l'état d'une cellule
    bool operator==(const Cellule &other) const; // Opérateur d'égalité pour comparer l'état entre deux cellules.

private:
    int etat; // Pour définir l'état de la cellule
};

#endif 