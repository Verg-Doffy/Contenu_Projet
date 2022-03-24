#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNE 16
#define COLONNE 16

/* PERMETTERA DE DONNER UN NOMBRE DE PIECE DEFINIE POUR CHAQUE TYPE */
/*
  JE CHOISIS DE REGULARISER L'ATTRIBUTION DES PIECES POUR CHAQUE JOUEUR.
  CHAQUE JOUEUR AURA :
    - 40 PIECES PLEINES
    - 40 PIECES CREUSES
    - 10 PIECES BLOQUANTES
*/
typedef struct decs{
  int piecePleine;
  int pieceCreuse;
  int pieceBloquante;
}decs_t;


/* LE DAMIER DU JEU SERA COMPOSE DU TYPE DE LA PIECE AINSI QUE SA COULEUR QUI DEFINIRA LE JOUEUR*/
typedef struct matrice{
  char couleur;   /* Identificateur du joueur --> Algorithmiquement se traduira par des nombres */
  char type;      /* Type de la pieces --> Pleine, Creuse, Bloquante */
  char couleurfusion; /* Couleur de la fusion produit par les pièces pleines, creuses */
}matrice_t;

/*FONCTION D'ATTRIBUTION DES TYPES DE PIECES POUR UN JOUEUR*/

void attribuer(decs_t *joueur);

/*INITIALISATION DU CONTENU DE LA MATRICE DU DAMIER PAR LA CARACTERE ESPACE */

void init_matrice(matrice_t A[LIGNE][COLONNE]);

/*AFFICHAGE DE LA MATRICE - FONCTION GRAPHIQUE D'AFFICHAGE SUR CONSOLE*/

void afficher_matrice(matrice_t A[LIGNE][COLONNE]);

/* FONCTION QUI PERMET DE GERER LES SPECIFICITES DE CHAQUE PIECE INSERER DANS LE DAMIER */

int gestion_piece(matrice_t A[LIGNE][COLONNE], int position, char type_piece, char joueur);

/*JOUEUR 1 AVEC LE SIGNE 1 */

char Joueur1(matrice_t A[LIGNE][COLONNE], decs_t *joueur);

/*JOUEUR 2 AVEC LE SIGNE 2 */

char Joueur2(matrice_t A[LIGNE][COLONNE], decs_t *joueur);
/*JOUEUR 3 AVEC LE SIGNE 3 */

char Joueur3(matrice_t A[LIGNE][COLONNE], decs_t *joueur);

/*JOUEUR 4 AVEC LE SIGNE 4 */

char Joueur4(matrice_t A[LIGNE][COLONNE], decs_t *joueur);

/*FONCTION QUI TEST SI LES COORDONNEES RECU SONT BIEN VALIDE DANS LA MATRICE*/

int dans_matrice(int i, int j);

/*FONCTION QUI PERMET DE DEFINIR QUI EST LE VAINQUEUR DE LA PARTIE*/

int victoire(matrice_t A[LIGNE][COLONNE], int *pointeur);

/*FONCTION QUI PERMET D'ARRETER LA PARTIE QUAND LE DAMIER EST REMPLIE*/

int aucun_vainqueur(matrice_t A[LIGNE][COLONNE], int *pointeur);
