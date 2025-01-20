#include "Cellule.h"
#include <iostream>
#include <cassert>

using namespace std;

void testConstructeur() {
    Cellule c;
    if (c.getEtat() == 0) {
        cout << "[OK] Default constructor works" << endl;
    } else {
        cout << "[FAILURE] Default constructor doesn't work" << endl;
    }
}

void testConstructeurP() {
    Cellule c(1);
    if (c.getEtat() == 1) {
        cout << "[OK] Constructor with parameters works" << endl;
    } else {
        cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
    }
}

void testSetEtat() {
    Cellule c;
    c.setEtat(1);
    if (c.getEtat() == 1) {
        cout << "[OK] Le setEtat fonctionne" << endl;
    } else {
        cout << "[FAILURE] Le setEtat ne fonctionne pas" << endl;
    }
}

void testOperatorEgal() {
    Cellule c1(1);
    Cellule c2(1);
    Cellule c3(0);
    if (c1 == c2) {
        cout << "[OK] l'opérateur d'égalité fonctionne pour les cellules" << endl;
    } else {
        cout << "[FAILURE] l'opérateur d'égalité ne fonctionne pas pour les cellules" << endl;
    }
    if (!(c1 == c3)) {
        cout << "[OK] l'opérateur d'égalité fonctionne pour deux cellules qui n'ont pas le même résultat" << endl;
    } else {
        cout << "[FAILURE] l'opérateur d'égalité ne fonctionne pas pour deux cellules qui n'ont pas le même résultat" << endl;
    }
}

int main() {
    testConstructeur();
    testConstructeurP();
    testSetEtat();
    testOperatorEgal();
    cout << "Le test unitaire fonctionne" << endl;
    return 0;
}
