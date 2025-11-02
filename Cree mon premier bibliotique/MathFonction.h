#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib> // pour rand()

namespace MathFonction
{
    float sqrtfonction(float Nombre)
    {
        return (Nombre,0.5); // utilisation directe de sqrt
    }

    float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }

    int RoundFonction(float Number)
    {
        int IntPart = int(Number);
        float FractionsPart = GetFractionPart(Number);

        if (fabs(FractionsPart) >= 0.5f)
        {
            if (Number > 0)
                return IntPart + 1;
            else
                return IntPart - 1;
        }
        else
        {
            return IntPart;
        }
    }

    int CeilFonction(float Number)
    {
        if (GetFractionPart(Number) > 0)
        {
            return int(Number) + 1;
        }
        else
        {
            return int(Number);
        }
    }

    int FloorFonction(float Number)
    {
        if (GetFractionPart(Number) < 0)
        {
            return int(Number) - 1;
        }
        else
        {
            return int(Number);
        }
    }

    float ABSfonction(float Number)
    {
        return fabs(Number);
    }

    int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }
}
