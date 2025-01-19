#include "Controleur.h"
#include "Vue.h"

int main()
{
    // On sollicite le View et le Controller pour gérer la simulation
    Vue vue; 

    Controleur controleur{vue};

    controleur.run(); // On exécute  la simulation

    return 0; 
}