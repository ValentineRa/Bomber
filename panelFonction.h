#ifndef PANELFONCTION_H_INCLUDED
#define PANELFONCTION_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <pthread.h>

#include <windows.h>

#define LIGNES 10
#define COLONNES 24

#define BOMBE 32

#define HAUT2 122
#define BAS2 115
#define DROITE2 100
#define GAUCHE2 113
#define BOMBE2 119

#define n 10 //nombre de bombe sur le terrain


typedef struct {
  char pseudo[20];
  int posLigne;
  int posColonne;
  int nbBombeUtilise;
}joueur;


// Prototypes de fonctions :
void afficher_plateau(char **plateau[LIGNES][COLONNES]);
void positionAlea(char **plateau[LIGNES][COLONNES]);
void *deplacementJoueur1(void *arg);
void *deplacementJoueur2(void *arg);
int placeLibre(char **plateau[LIGNES][COLONNES], int ligne, int colonne);
void clearScreen(void);
void *installeBombe1(void *arg);
void *installeBombe2(void *arg);
int exploBombe(char **plateau[LIGNES][COLONNES], int ligne, int colonne);
int toujoursLa (char **plateau[LIGNES][COLONNES], char b);
int score (int nbBombeUtilise, int *nbObExplose);
void terrain(char **plateau[LIGNES][COLONNES]);
void highscore(int score, char personnage);


#endif // PANELFONCTION_H_INCLUDED
