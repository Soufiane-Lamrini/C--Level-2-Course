
#include <iostream>
#include "LireNombre.h"
#include "AfficherNombre.h"
#include "MathFonction.h"

using namespace std;

int main()
{
    float Nombre = LireNombre::LireNombreDansRange("Saisir un nombre entre 1 et 100", 1, 100);
    float NombreAvecMathFonction = MathFonction::sqrtfonction(Nombre);
    AfficherNombre::AfficherNombre(NombreAvecMathFonction);

}

