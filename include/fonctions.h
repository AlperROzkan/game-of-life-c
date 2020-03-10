#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <define.h>

/**
 * @brief 
 * 
 * @param tableau 
 * @return int 
 */
int ConfigInit(int tableau[MAXLENGTH][MAXLENGTH]);

/**
 * @brief 
 * 
 * @param tableau 
 * @return int 
 */
void ChangeEtat(int tableau[MAXLENGTH][MAXLENGTH], int nbEtapes);

/**
 * @brief 
 * 
 * @param tableau 
 */
void Imprime(int tableau[MAXLENGTH][MAXLENGTH]);

/**
 * @brief 
 * 
 * @param tab_avant 
 * @param tab_apres 
 */
void ImprimeDifference(int tab_avant[MAXLENGTH][MAXLENGTH], int tab_apres[MAXLENGTH][MAXLENGTH]);

/**
 * @brief 
 * 
 * @param tableau 
 * @param coordX 
 * @param coordY 
 * @return int 
 */
int nbVoisins(int tableau[MAXLENGTH][MAXLENGTH], int coordX, int coordY);

/**
 * @brief 
 * 
 * @return int 
 */
int BinRandom();

/**
 * @brief 
 * 
 * @param tableau 
 * @param coordX 
 * @param coordY 
 * @return int 
 */
int EstVivante(int tableau[MAXLENGTH][MAXLENGTH], int coordX, int coordY);



#endif