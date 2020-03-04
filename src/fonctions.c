#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/define.h"
#include "../include/fonctions.h"


// Pas de gestion d'erreur
int ConfigInit(int tableau[MAXLENGTH][MAXLENGTH])
{
    int NbEtapes;
    scanf("%d", &NbEtapes);

    for (int coordX = 0; coordX < MAXLENGTH; coordX++)
    {
        for (int coordY = 0; coordY < MAXLENGTH; coordY++)
        {
            if (((coordX >= 0 && coordX < MAXLENGTH) && coordY == 0) ||
                ((coordY >= 0 && coordY < MAXLENGTH) && coordX == 0) ||
                ((coordY >= 0 && coordY < MAXLENGTH) && coordX == MAXLENGTH-1) ||
                ((coordX >= 0 && coordX < MAXLENGTH) && coordY == MAXLENGTH-1))
            {
                tableau[coordX][coordY] = 0;
            }
            else
            {
                tableau[coordX][coordY] = BinRandom();
            }
            
        }
    }

    return NbEtapes;
}

int ChangeEtat(int tableau[MAXLENGTH][MAXLENGTH])
{
}

int Imprime(int tableau[MAXLENGTH][MAXLENGTH])
{
    for (size_t i = 0; i < MAXLENGTH; i++)
    {
        for (size_t j = 0; j < MAXLENGTH; j++)
        {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
}

int nbVoisins(int tableau[MAXLENGTH][MAXLENGTH], int coordX, int coordY)
{
    if (((coordX >= 0 && coordX < MAXLENGTH) && coordY == 0) ||
        ((coordY >= 0 && coordY < MAXLENGTH) && coordX == 0) ||
        ((coordY >= 0 && coordY < MAXLENGTH) && coordX == MAXLENGTH) ||
        ((coordX >= 0 && coordX < MAXLENGTH) && coordY == MAXLENGTH))
    {
        printf("Ne pas selectionner le contour\n");
        return -1;
    }

    int nbVoisins = 0;

    if (tableau[coordX - 1][coordY] == 1)
    {
        nbVoisins++;
    }
    if (tableau[coordX][coordY - 1] == 1)
    {
        nbVoisins++;
    }
    if (tableau[coordX + 1][coordY] == 1)
    {
        nbVoisins++;
    }
    if (tableau[coordX][coordY + 1] == 1)
    {
        nbVoisins++;
    }

    return nbVoisins;
}

int BinRandom()
{
    return rand() & 1;
}