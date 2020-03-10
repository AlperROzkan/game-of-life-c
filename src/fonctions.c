#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <define.h>
#include <fonctions.h>

// Pas de gestion d'erreur
int ConfigInit(int tableau[MAXLENGTH][MAXLENGTH])
{
    int NbEtapes;

    printf("Nombre d'étapes :\n");
    scanf("%d", &NbEtapes);

    srand(time(NULL)); // On seed le generateur de nombres aléatoires avant d'utiliser BinRandom

    for (int coordX = 0; coordX < MAXLENGTH; coordX++)
    {
        for (int coordY = 0; coordY < MAXLENGTH; coordY++)
        {
            if (((coordX >= 0 && coordX < MAXLENGTH) && coordY == 0) ||
                ((coordY >= 0 && coordY < MAXLENGTH) && coordX == 0) ||
                ((coordY >= 0 && coordY < MAXLENGTH) && coordX == MAXLENGTH - 1) ||
                ((coordX >= 0 && coordX < MAXLENGTH) && coordY == MAXLENGTH - 1))
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

void ChangeEtat(int tableau[MAXLENGTH][MAXLENGTH], int nbEtapes)
{
    int tableau_avant[MAXLENGTH][MAXLENGTH];
    memcpy(tableau_avant, tableau, sizeof(int[MAXLENGTH][MAXLENGTH]));

    for (size_t t = 0; t < nbEtapes; t++)
    {
        memcpy(tableau_avant, tableau, sizeof(int[MAXLENGTH][MAXLENGTH]));

        for (size_t i = 0; i < MAXLENGTH; i++)
        {
            for (size_t j = 0; j < MAXLENGTH; j++)
            {
                if (((i >= 0 && i < MAXLENGTH) && j == 0) ||
                    ((j >= 0 && j < MAXLENGTH) && i == 0) ||
                    ((j >= 0 && j < MAXLENGTH) && i == MAXLENGTH - 1) ||
                    ((i >= 0 && i < MAXLENGTH) && j == MAXLENGTH - 1))
                {
                }
                else
                {
                    int nb_Voisins = nbVoisins(tableau, i, j);
                    tableau[i][j] = (nb_Voisins == 0 || nb_Voisins == 4) ? 0 : 1;
                }
            }
        }
        printf("ETAT A L'ETAPE %ld\n", t);
        // Imprime(tableau);
        printf("DIFFERENCES \n");
        ImprimeDifference(tableau_avant, tableau);
    }
}

void Imprime(int tableau[MAXLENGTH][MAXLENGTH])
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

void ImprimeDifference(int tab_avant[MAXLENGTH][MAXLENGTH], int tab_apres[MAXLENGTH][MAXLENGTH])
{
    for (size_t i = 0; i < MAXLENGTH; i++)
    {
        for (size_t j = 0; j < MAXLENGTH; j++)
        {
            if (tab_avant[i][j] != tab_apres[i][j])
            {
                printf("\033[0;31m");
                printf("%d ", tab_apres[i][j]);
                printf("\033[0m");
            }
            else
            {
                printf("%d ", tab_apres[i][j]);
            }
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

int EstVivante(int tableau[MAXLENGTH][MAXLENGTH], int coordX, int coordY)
{
    if (nbVoisins(tableau, coordX, coordY) == 0 || nbVoisins(tableau, coordX, coordY) == 4)
    {
        return 0;
    }
    else if (nbVoisins(tableau, coordX, coordY) > 0 || nbVoisins(tableau, coordX, coordY) < 4)
    {
        return 1;
    }
    else
    {
        printf("ERROR at EstVivante : not a valid number of neighbours");
        return -1;
    }
}