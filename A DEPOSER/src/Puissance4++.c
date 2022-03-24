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

void attribuer(decs_t *joueur){
  joueur->piecePleine = 40;
  joueur->pieceCreuse = 40;
  joueur->pieceBloquante = 10;
}

/*INITIALISATION DU CONTENU DE LA MATRICE DU DAMIER PAR LA CARACTERE ESPACE */

void init_matrice(matrice_t A[LIGNE][COLONNE]){
    int i,j;

    for(i=0; i<LIGNE ;i++){
        for(j=0; j<COLONNE ; j++){
            A[i][j].couleur = ' ';
            A[i][j].type = ' ';
            A[i][j].couleurfusion = ' ';
        }
    }
}

/*AFFICHAGE DE LA MATRICE - FONCTION GRAPHIQUE D'AFFICHAGE SUR CONSOLE*/

void afficher_matrice(matrice_t A[LIGNE][COLONNE]){
    int i,j;

  printf("\n\n");
	printf("                                                                      Puissance 4 :  MULTIJOUEUR        \n");
	printf("     --------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n");


  for(i=0; i<LIGNE ;i++){
    printf("+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
		printf("|");

    for(j=0; j<COLONNE ; j++){
        printf("  %c - %c  |", A[i][j].couleur, A[i][j].type);
		}
    printf("\n");
    }

  printf("+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
  printf("     1         2         3         4         5         6         7         8         9        10        11        12        13        14        15        16");
  printf("\n\n");
}

/* FONCTION QUI PERMET DE GERER LES SPECIFICITES DE CHAQUE PIECE INSERER DANS LE DAMIER */

int gestion_piece(matrice_t A[LIGNE][COLONNE], int position, char type_piece, char joueur){
  int i;
  int depart;
  int fin;
  int changement_effectuer = 0;

  if(A[15][position-1].couleur == ' '){
    return (changement_effectuer);
  }

  if(type_piece == 'P'){
    for(i=0; i<LIGNE; i++){
      if(A[i][position-1].type == ' '){
        // Ne rien faire
      }
      else if(A[i][position-1].type == 'B' || A[i][position-1].type == 'P' || A[i][position-1].type == 'F'){
        return(changement_effectuer); // Ajouter la piece de manière classique
      }
      else if(A[i][position-1].type == 'C'){
        if(A[i+1][position-1].type == 'C'){
          // Ne rien faire
        }
        else{
          A[i][position-1].type = 'B';                          // TRANSFORMATION BLOQUANR
          A[i][position-1].couleur = joueur;                    // CHANGEMENT COULEUR
          changement_effectuer = 1;
          return(changement_effectuer);
        }
      }
    }
  }
  else if(type_piece == 'C'){
    for(i=0; i<LIGNE; i++){
      if(A[i][position-1].type == ' '){
        // Ne rien faire
      }
      else if(A[i][position-1].type == 'B' || A[i][position-1].type == 'C' || A[i][position-1].type == 'F'){
        return(changement_effectuer); // Ajouter la piece de manière classique
      }
      else if(A[i][position-1].type == 'P'){
        if(A[i+1][position-1].type == 'P'){
          // Ne rien faire
        }
        else{
          A[i][position-1].type = 'F';
          A[i][position-1].couleurfusion = joueur;
          changement_effectuer = 1;
          return(changement_effectuer);
        }
      }
    }
  }
  else if(type_piece == 'B'){
    return(changement_effectuer);
  }
  // CAS IMPOSSIBLE
  else{
    return(changement_effectuer);
  }
}

/*JOUEUR 1 AVEC LE SIGNE 1 */

char Joueur1(matrice_t A[LIGNE][COLONNE], decs_t *joueur){
  int i,j;
  int position;
  int continuer = 1;
  char type_piece[2];
  int combo; /* Variable qui prendra la décision d'inserer une piece si il n'y a pas de fusion entre une piece creuses et pleine */
  printf("Posisitionner votre pion joueur 1: ");
  scanf("%d",&position);

  while ((position < 1 || position > 16) || A[0][position-1].couleur != ' '){
    if(position < 1 || position > 16){
      printf("Posisitionner votre pion joueur 1 (COMPRIS ENTRE 1 ET 16): ");
      scanf("%d",&position);
    }
    else{
      printf("Jouez sur une autre colonne, vous voyez bien que c'est rempli non !!!\n\n");
      scanf("%d",&position);
    }
  }
  printf("Choisi le type de ta pièce Joueur 1: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
  scanf("%s",type_piece);

  while(continuer){
    if(type_piece[0] == 'B' || type_piece[0] == 'C' || type_piece[0] == 'P'){
      if(type_piece[0] == 'B'){
        if(joueur->pieceBloquante <= 0){
          printf("Vous n'avez plus de pièce Bloqnante, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceBloquante--;
          continuer = 0;
          printf("cocococo\n");
          printf("%d\n", joueur->pieceBloquante);
        }
      }
      if(type_piece[0] == 'C'){
        if(joueur->pieceCreuse <= 0){
          printf("Vous n'avez plus de pièce Creuse, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceCreuse--;
          continuer = 0;
        }
      }
      if(type_piece[0] == 'P'){
        if(joueur->piecePleine <= 0){
          printf("Vous n'avez plus de pièce Pleine, jouer avec une autre pièce\n");
          scanf("%s",type_piece);
        }
        else{
          joueur->piecePleine--;
          continuer = 0;
        }
      }
    }
    else{
      printf("ERREUR SAISIE: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
      scanf("%s",type_piece);
    }
  }

  combo = gestion_piece(A, position, type_piece[0], '1');

  if(combo == 0){
    for(i=LIGNE; i>= 0 ; i--){
      if(A[i][position-1].couleur == ' '){
         A[i][position-1].couleur='1';
         A[i][position-1].type= type_piece[0];
         i=0;
      }
    }
  }

}

/*JOUEUR 2 AVEC LE SIGNE 2 */

char Joueur2(matrice_t A[LIGNE][COLONNE], decs_t *joueur){
  int i,j;
  int position;
  int continuer = 1;
  char type_piece[2];
  int combo; /* Variable qui prendra la décision d'inserer une piece si il n'y a pas de fusion entre une piece creuses et pleine */
  printf("Posisitionner votre pion joueur 2: ");
  scanf("%d",&position);
  while ((position < 1 || position > 16) || A[0][position-1].couleur != ' '){
    if(position < 1 || position > 16){
      printf("Posisitionner votre pion joueur 2 (COMPRIS ENTRE 1 ET 16): ");
      scanf("%d",&position);
    }
    else{
      printf("Jouez sur une autre colonne, vous voyez bien que c'est rempli non !!!\n\n");
      scanf("%d",&position);
    }
  }
  printf("Choisi le type de ta pièce Joueur 2: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
  scanf("%s",type_piece);

  while(continuer){
    if(type_piece[0] == 'B' || type_piece[0] == 'C' || type_piece[0] == 'P'){
      if(type_piece[0] == 'B'){
        if(joueur->pieceBloquante <= 0){
          printf("Vous n'avez plus de pièce Bloqnante, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceBloquante--;
          continuer = 0;
          printf("cocococo\n");
          printf("%d\n", joueur->pieceBloquante);
        }
      }
      if(type_piece[0] == 'C'){
        if(joueur->pieceCreuse <= 0){
          printf("Vous n'avez plus de pièce Creuse, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceCreuse--;
          continuer = 0;
        }
      }
      if(type_piece[0] == 'P'){
        if(joueur->piecePleine <= 0){
          printf("Vous n'avez plus de pièce Pleine, jouer avec une autre pièce\n");
          scanf("%s",type_piece);
        }
        else{
          joueur->piecePleine--;
          continuer = 0;
        }
      }
    }
    else{
      printf("ERREUR SAISIE: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
      scanf("%s",type_piece);
    }
  }

  combo = gestion_piece(A, position, type_piece[0], '2');

  if(combo == 0){
    for(i=LIGNE; i>= 0 ; i--){
      if(A[i][position-1].couleur == ' '){
         A[i][position-1].couleur='2';
         A[i][position-1].type= type_piece[0];
         i=0;
      }
    }
  }
}

/*JOUEUR 3 AVEC LE SIGNE 3 */

char Joueur3(matrice_t A[LIGNE][COLONNE], decs_t *joueur){
  int i,j;
  int position;
  int continuer = 1;
  char type_piece[2];
  int combo; /* Variable qui prendra la décision d'inserer une piece si il n'y a pas de fusion entre une piece creuses et pleine */
  printf("Posisitionner votre pion joueur 3: ");
  scanf("%d",&position);
  while ((position < 1 || position > 16) || A[0][position-1].couleur != ' '){
    if(position < 1 || position > 16){
      printf("Posisitionner votre pion joueur 3 (COMPRIS ENTRE 1 ET 16): ");
      scanf("%d",&position);
    }
    else{
      printf("Jouez sur une autre colonne, vous voyez bien que c'est rempli non !!!\n\n");
      scanf("%d",&position);
    }
  }
  printf("Choisi le type de ta pièce Joueur 3: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
  scanf("%s",type_piece);

  while(continuer){
    if(type_piece[0] == 'B' || type_piece[0] == 'C' || type_piece[0] == 'P'){
      if(type_piece[0] == 'B'){
        if(joueur->pieceBloquante <= 0){
          printf("Vous n'avez plus de pièce Bloqnante, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceBloquante--;
          continuer = 0;
          printf("cocococo\n");
          printf("%d\n", joueur->pieceBloquante);
        }
      }
      if(type_piece[0] == 'C'){
        if(joueur->pieceCreuse <= 0){
          printf("Vous n'avez plus de pièce Creuse, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceCreuse--;
          continuer = 0;
        }
      }
      if(type_piece[0] == 'P'){
        if(joueur->piecePleine <= 0){
          printf("Vous n'avez plus de pièce Pleine, jouer avec une autre pièce\n");
          scanf("%s",type_piece);
        }
        else{
          joueur->piecePleine--;
          continuer = 0;
        }
      }
    }
    else{
      printf("ERREUR SAISIE: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
      scanf("%s",type_piece);
    }
  }

  combo = gestion_piece(A, position, type_piece[0], '3');

  if(combo == 0){
    for(i=LIGNE; i>= 0 ; i--){
      if(A[i][position-1].couleur == ' '){
         A[i][position-1].couleur='3';
         A[i][position-1].type= type_piece[0];
         i=0;
      }
    }
  }
}

/*JOUEUR 4 AVEC LE SIGNE 4 */

char Joueur4(matrice_t A[LIGNE][COLONNE], decs_t *joueur){
  int i,j;
  int position;
  int continuer = 1;
  char type_piece[2];
  int combo; /* Variable qui prendra la décision d'inserer une piece si il n'y a pas de fusion entre une piece creuses et pleine */
  printf("posisitionner votre pion joueur 4: ");
  scanf("%d",&position);
  while ((position < 1 || position > 16) || A[0][position-1].couleur != ' '){
    if(position < 1 || position > 16){
      printf("Posisitionner votre pion joueur 4 (COMPRIS ENTRE 1 ET 16): ");
      scanf("%d",&position);
    }
    else{
      printf("Jouez sur une autre colonne, vous voyez bien que c'est rempli non !!!\n\n");
      scanf("%d",&position);
    }
  }
  printf("Choisi le type de ta pièce Joueur 4: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
  scanf("%s",type_piece);

  while(continuer){
    if(type_piece[0] == 'B' || type_piece[0] == 'C' || type_piece[0] == 'P'){
      if(type_piece[0] == 'B'){
        if(joueur->pieceBloquante <= 0){
          printf("Vous n'avez plus de pièce Bloqnante, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceBloquante--;
          continuer = 0;
          printf("cocococo\n");
          printf("%d\n", joueur->pieceBloquante);
        }
      }
      if(type_piece[0] == 'C'){
        if(joueur->pieceCreuse <= 0){
          printf("Vous n'avez plus de pièce Creuse, jouer avec une autre pièce :");
          scanf("%s",type_piece);
        }
        else{
          joueur->pieceCreuse--;
          continuer = 0;
        }
      }
      if(type_piece[0] == 'P'){
        if(joueur->piecePleine <= 0){
          printf("Vous n'avez plus de pièce Pleine, jouer avec une autre pièce\n");
          scanf("%s",type_piece);
        }
        else{
          joueur->piecePleine--;
          continuer = 0;
        }
      }
    }
    else{
      printf("ERREUR SAISIE: Choississez entre une pièce Bloquante (B), Creuse (C) ou Pleine (P) ");
      scanf("%s",type_piece);
    }
  }

  combo = gestion_piece(A, position, type_piece[0], '4');

  if(combo == 0){
    for(i=LIGNE; i>= 0 ; i--){
      if(A[i][position-1].couleur == ' '){
         A[i][position-1].couleur='4';
         A[i][position-1].type= type_piece[0];
         i=0;
      }
    }
  }
}

/*FONCTION QUI TEST SI LES COORDONNEES RECU SONT BIEN VALIDE DANS LA MATRICE*/

int dans_matrice(int i, int j){
    return(i>=0 && i<LIGNE && j>=0 && j<COLONNE);
}

/*FONCTION QUI PERMET DE DEFINIR QUI EST LE VAINQUEUR DE LA PARTIE*/

int victoire(matrice_t A[LIGNE][COLONNE], int *pointeur){
  int i,j,tourJoueur;
  char couleurjoueur = '1';

  for(tourJoueur = 1; tourJoueur < 4; tourJoueur++){

    /*ANALYSE EN LIGNE*/
    for(i=0;i<LIGNE;i++){
      for(j=0;j<COLONNE;j++){
        if(A[i][j].couleur==couleurjoueur){
          if(dans_matrice(i,j+1) && dans_matrice(i,j+2) && dans_matrice(i,j+3)){
            if(((A[i][j+1].couleur == couleurjoueur || A[i][j+1].couleurfusion == couleurjoueur)) && (A[i][j+2].couleur == couleurjoueur || A[i][j+2].couleurfusion == couleurjoueur) && (A[i][j+3].couleur == couleurjoueur || A[i][j+3].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison à l'horisontale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
        }
      }
    }

    /*ANALYSE EN COLONNE*/
    for(j=0;j<COLONNE;j++){
      for(i=0;i<LIGNE;i++){
        if(A[i][j].couleur==couleurjoueur){
          if(dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
            if((A[i+1][j].couleur == couleurjoueur || A[i+1][j].couleurfusion == couleurjoueur) && (A[i+2][j].couleur == couleurjoueur  || A[i+2][j].couleurfusion == couleurjoueur) && (A[i+3][j].couleur == couleurjoueur || A[i+3][j].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison à la verticale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
        }
      }
    }


    /*ANALYSE EN DIAGONALE*/
    for(i=0; i<LIGNE; i++){
      for(j=0; j<COLONNE; j++){
        if(A[i][j].couleur==couleurjoueur){
          if(dans_matrice(i-1,j-1) && dans_matrice(i-2,j-2) && dans_matrice(i-3,j-3)){
            if((A[i-1][j-1].couleur == couleurjoueur || A[i-1][j-1].couleurfusion == couleurjoueur) && (A[i-2][j-2].couleur == couleurjoueur || A[i-2][j-2].couleurfusion == couleurjoueur) && (A[i-3][j-3].couleur == couleurjoueur || A[i-3][j-3].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison en diagonale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
          else if(dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3)){
            if((A[i+1][j+1].couleur == couleurjoueur || A[i+1][j+1].couleurfusion == couleurjoueur) && (A[i+2][j+2].couleur == couleurjoueur  || A[i+2][j+2].couleurfusion == couleurjoueur) && (A[i+3][j+3].couleur == couleurjoueur  || A[i+3][j+3].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison en diagonale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
          else if(dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3)){
            if((A[i-1][j+1].couleur == couleurjoueur  || A[i-1][j+1].couleurfusion == couleurjoueur) && (A[i-2][j+2].couleur == couleurjoueur || A[i-2][j+2].couleurfusion == couleurjoueur) && (A[i-3][j+3].couleur == couleurjoueur || A[i-3][j+3].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison en diagonale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
          else if(dans_matrice(i+1,j-1) && dans_matrice(i+2,j-2) && dans_matrice(i+3,j-3)){
            if((A[i+1][j-1].couleur == couleurjoueur  || A[i+1][j-1].couleurfusion == couleurjoueur) && (A[i+2][j-2].couleur == couleurjoueur || A[i+2][j-2].couleurfusion == couleurjoueur) && (A[i+3][j-3].couleur == couleurjoueur  || A[i+3][j-3].couleurfusion == couleurjoueur)){
              printf("Le joueur avec les pièces de la forme %c à remporté la partie avec une combinaison en diagonale.\n", couleurjoueur);
              *pointeur = 0;
              return EXIT_SUCCESS;
            }
          }
        }
      }
    }
    couleurjoueur++;
  }
}

/*FONCTION QUI PERMET D'ARRETER LA PARTIE QUAND LE DAMIER EST REMPLIE*/

int aucun_vainqueur(matrice_t A[LIGNE][COLONNE], int *pointeur){
  int j;
  for(j=0; j<COLONNE; j++){
    if(A[0][j].couleur == ' '){
      return EXIT_SUCCESS;
    }
  }
  printf("Le damier est remplie et aucun des joueurs à reussi à former une combinaison\n");
  printf("La partie est à égalité\n");
  *pointeur = 0;
  return EXIT_SUCCESS;
}
