#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <define.h>
#include <fonctions.h>

int main(int argc, char *argv[])
{
    int M[MAXLENGTH][MAXLENGTH];
    int NbEtapes = ConfigInit(M); // Remplissage du tableau

    printf("Impression de l'état initial :\n");
    Imprime(M);

    printf("Nombre de voisins de M[1][%d] :\n", MAXLENGTH-1);
    printf("%d\n", nbVoisins(M, 1,MAXLENGTH-1));
    
    ChangeEtat(M, NbEtapes);
    

}