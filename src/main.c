#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "../include/define.h"
#include "../include/fonctions.h"

int main(int argc, char argv[])
{
    int M[MAXLENGTH][MAXLENGTH];
    int NbEtapes = ConfigInit(M); // Remplissage du tableau
    srand(time(NULL));
    

    Imprime(M);
    printf("%d\n", nbVoisins(M, 1,MAXLENGTH-1));
    
    /*
    for (size_t i = 0; i < NbEtapes; i++)
    {
        ChangeEtat(M);
        Imprime(M);
    }*/
    

}