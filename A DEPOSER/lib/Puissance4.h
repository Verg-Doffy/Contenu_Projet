#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNE 8
#define COLONNE 8

/*INITIALISATION DU CONTENU DE LA MATRICE DU DAMIER PAR LA CARACTERE ESPACE */

void init_matrice(char A[LIGNE][COLONNE]);

/*AFFICHAGE DE LA MATRICE - FONCTION GRAPHIQUE D'AFFICHAGE SUR CONSOLE*/

void afficher_matrice(char A[LIGNE][COLONNE]);

/*JOUEUR 1*/

char Joueur1(char A[LIGNE][COLONNE]);

/*JOUEUR 2*/

char Joueur2(char A[LIGNE][COLONNE]);

/*FONCTION QUI TEST SI LES COORDONNEES RECU SONT BIEN VALIDE DANS LA MATRICE*/

int dans_matrice(int i, int j);

/*FONCTION QUI PERMET DE DEFINIR QUI EST LE VAINQUEUR DE LA PARTIE*/

int victoire(char A[LIGNE][COLONNE], int *pointeur);

/*FONCTION QUI PERMET D'ARRETER LA PARTIE QUAND LE DAMIER EST REMPLIE*/

int aucun_vainqueur(char A[LIGNE][COLONNE], int *pointeur);

/*FONCTION QUI PERMET DE TRIER DANS L'ORDRE CROISSANT UNE TABLE AVEC UNE STRUCTURE COMPOSE DE 2 NOMBRE */

void tri_tableau(int tab1[COLONNE], int tab2[COLONNE]);

/*FONCTION QUI PERMET DE CONNAITRE LE POTENTIEL DE VICTOIRE D'UNE CASE*/

void potentiel_choix_colonne(char A[LIGNE][COLONNE], int *potentiel_case, int i, int j);

/*FONCTION QUI PERMET A L'ORDINATEUR DE PLACER SA PIECE*/

char tour_ordinateur_debut(char A[LIGNE][COLONNE]);

/*FONCTION QUI PERMET A L'ORDINATEUR DE DETERMINER DANS QUEL COLONNE, IL DEVRAIT JOUER AFIN DE GAGNER*/

int intelligence_artificielle(char A[LIGNE][COLONNE]);

/* FONCTION QUI PERMET A L'ORDINATEUR DE JOUER SANS ETRE PENALISER LORS DES PREMIERS ECHANGES DE COUPS*/
/* CETTE FONCTION COMBLE LE SEULE DEFAULT DE L'INTELLIGENCE ARTIFICIELLE DE L'ORDINATEUR*/

void tour_debut_ordinateur(char A[LIGNE][COLONNE]);