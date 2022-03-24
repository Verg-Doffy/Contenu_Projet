#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNE 8
#define COLONNE 8

/*INITIALISATION DU CONTENU DE LA MATRICE DU DAMIER PAR LA CARACTERE ESPACE */

void init_matrice(char A[LIGNE][COLONNE]){
    int i,j;

    for(i=0; i<LIGNE ;i++){
        for(j=0; j<COLONNE ; j++){
            A[i][j]=' ';
        }
    }
}

/*AFFICHAGE DE LA MATRICE - FONCTION GRAPHIQUE D'AFFICHAGE SUR CONSOLE*/

void afficher_matrice(char A[LIGNE][COLONNE]){
    int i,j;

  printf("\n\n");
	printf("                  Puissance 4 :      \n");
	printf("     --------------------------------------\n");
	printf("\n\n");


  for(i=0; i<LIGNE ;i++){
    printf("+----+----+----+----+----+----+----+----+\n");
		printf("|");

    for(j=0; j<COLONNE ; j++){
        printf("  %c |", A[i][j]);
		}
    printf("\n");
    }

  printf("+----+----+----+----+----+----+----+----+\n");
  printf("   1    2    3    4    5    6    7    8");
  printf("\n\n");
}

/*JOUEUR 1*/

char Joueur1(char A[LIGNE][COLONNE]){
    int i,j;
    int position;


    printf("posisitionner votre pion joueur 1:");
    scanf("%i",&position);
    position--;
    if(A[0][position] != ' '){
        printf("Jouer sur une autre colonne mon reuf, tu vois bien que c'est rempli ptn !!!\n\n");
    }

    else{
        for(i=LIGNE; i>= 0 ; i--){

            if(A[i][position]== ' '){
               A[i][position]='X';
                    i=0;
            }
        }
    }

}

/*JOUEUR 2*/

char Joueur2(char A[LIGNE][COLONNE]){
    int i,j;
    int position;


    printf("posisitionner votre pion Joueur 2:");
    scanf("%i",&position);
    position--;

    if(A[0][position] != ' '){
        printf("Jouer sur une autre colonne mon reuf, tu vois bien que c'est rempli ptn !!!\n\n");
    }

    else{
        for(i=LIGNE; i>= 0 ; i--){

            if(A[i][position]== ' '){
              A[i][position]='O';
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

int victoire(char A[LIGNE][COLONNE], int *pointeur){
  int i,j;

  /*JOUEUR AVEC JETON OU PIECES "X" */

  /*ANALYSE EN LIGNE*/
  for(i=0;i<LIGNE;i++){
    for(j=0;j<COLONNE;j++){
      if(A[i][j]=='X'){
        if(dans_matrice(i,j+1) && dans_matrice(i,j+2) && dans_matrice(i,j+3)){
          if(A[i][j+1] == 'X' && A[i][j+2] == 'X' && A[i][j+3] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison à l'horisontale.\n");
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
      if(A[i][j]=='X'){
        if(dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
          if(A[i+1][j] == 'X' && A[i+2][j] == 'X' && A[i+3][j] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison à la verticale.\n");
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
      if(A[i][j]=='X'){
        if(dans_matrice(i-1,j-1) && dans_matrice(i-2,j-2) && dans_matrice(i-3,j-3)){
          if(A[i-1][j-1] == 'X' && A[i-2][j-2] == 'X' && A[i-3][j-3] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3)){
          if(A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && A[i+3][j+3] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3)){
          if(A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && A[i-3][j+3] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i+1,j-1) && dans_matrice(i+2,j-2) && dans_matrice(i+3,j-3)){
          if(A[i+1][j-1] == 'X' && A[i+2][j-2] == 'X' && A[i+3][j-3] == 'X'){
            printf("Le joueur avec les pièces de la forme X à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
      }
    }
  }

  /*JOUEUR AVEC JETON OU PIECES "O" */


  /*ANALYSE EN LIGNE*/
  for(i=0;i<LIGNE;i++){
    for(j=0;j<COLONNE;j++){
      if(A[i][j]=='O'){
        if(dans_matrice(i,j+1) && dans_matrice(i,j+2) && dans_matrice(i,j+3)){
          if(A[i][j+1] == 'O' && A[i][j+2] == 'O' && A[i][j+3] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison à l'horisontale.\n");
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
      if(A[i][j]=='O'){
        if(dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
          if(A[i+1][j] == 'O' && A[i+2][j] == 'O' && A[i+3][j] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison à la verticale.\n");
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
      if(A[i][j]=='O'){
        if(dans_matrice(i-1,j-1) && dans_matrice(i-2,j-2) && dans_matrice(i-3,j-3)){
          if(A[i-1][j-1] == 'O' && A[i-2][j-2] == 'O' && A[i-3][j-3] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3)){
          if(A[i+1][j+1] == 'O' && A[i+2][j+2] == 'O' && A[i+3][j+3] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3)){
          if(A[i-1][j+1] == 'O' && A[i-2][j+2] == 'O' && A[i-3][j+3] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
        else if(dans_matrice(i+1,j-1) && dans_matrice(i+2,j-2) && dans_matrice(i+3,j-3)){
          if(A[i+1][j-1] == 'O' && A[i+2][j-2] == 'O' && A[i+3][j-3] == 'O'){
            printf("Le joueur avec les pièces de la forme O à remporté la partie avec une combinaison en diagonale.\n");
            *pointeur = 0;
            return EXIT_SUCCESS;
          }
        }
      }
    }
  }
}

/*FONCTION QUI PERMET D'ARRETER LA PARTIE QUAND LE DAMIER EST REMPLIE*/

int aucun_vainqueur(char A[LIGNE][COLONNE], int *pointeur){
  int j;
  for(j=0; j<COLONNE; j++){
    if(A[0][j] == ' '){
      return EXIT_SUCCESS;
    }
  }
  printf("Le damier est remplie et aucun des joueurs à reussi à former une combinaison\n");
  printf("La partie est à égalité\n");
  *pointeur = 0;
  return EXIT_SUCCESS;
}

/*FONCTION QUI PERMET A L'ORDINATEUR DE CONTRE ATTAQUER UNE COMBINAISON QUE LE JOUEUR PEUT POTENTIELLEMENT EFFECTUER OU FINIR LA PARTIE AVEC UNE COMBINAISON GAGNANTE*/

int contre_attaque(char A[LIGNE][COLONNE], int *pointeur){
  int i, j;

  for(j=0;j<COLONNE;j++){
    for(i=0;i<LIGNE;i++){
      if((A[i][j] == ' ' && (A[i+1][j] != ' ' || !(dans_matrice(i+1,j))))){ // Case vide, colonne non pleine, en bas, il y a quelque chose ou c'est le bord

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON VERTICALE DU JOUEUR*/

        if(A[i+1][j] == 'X' && A[i+2][j] == 'X' && A[i+3][j] == 'X' && dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
          A[i][j] = 'X';
          printf("\n\n PASSER MON REUF \n\n");
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON VERTICALE DU JOUEUR*/

        if((A[i][j-1] == 'X' && A[i][j+1] == 'X' && A[i][j+2] == 'X' && dans_matrice(i,j-1) && dans_matrice(i,j+1) && dans_matrice(i,j+2)) || (A[i][j-2] == 'X' && A[i][j-1] == 'X' && A[i][j+1] == 'X' && dans_matrice(i,j-2) && dans_matrice(i,j-1) && dans_matrice(i,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i][j-3] == 'X' && A[i][j-2] == 'X' && A[i][j-1] == 'X' && dans_matrice(i,j-3) && dans_matrice(i,j-2) && dans_matrice(i,j-1)) || (A[i][j+1] == 'X' && A[i][j+2] == 'X' && A[i][j+3] == 'X' && dans_matrice(i,j+3) && dans_matrice(i,j+2) && dans_matrice(i,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "DECROISSANT" DU JOUEUR*/

        if((A[i-1][j-1] == 'X' && A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2)) || (A[i-2][j-2] == 'X' && A[i-1][j-1] == 'X' && A[i+1][j+1] == 'X' && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i-3][j-3] == 'X' && A[i-2][j-2] == 'X' && A[i-1][j-1] == 'X' && dans_matrice(i-3,j-3) && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1)) || (A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && A[i+3][j+3] == 'X' && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "CROISSANT" DU JOUEUR*/

        if((A[i+2][j-2] == 'X' && A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1)) || (A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i+3][j-3] == 'X' && A[i+2][j-2] == 'X' && A[i+1][j-1] == 'X' && dans_matrice(i+3,j-3) && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1)) || (A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && A[i-3][j+3] == 'X' && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }
      }
    }
  }


  for(j=0;j<COLONNE;j++){
    for(i=0;i<LIGNE;i++){
      if((A[i][j] == ' ' && (A[i+1][j] != ' ' || !(dans_matrice(i+1,j))))){ // Case vide, colonne non pleine, en bas, il y a quelque chose ou c'est le bord

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON VERTICALE DU JOUEUR*/

        if(A[i+1][j] == 'O' && A[i+2][j] == 'O' && A[i+3][j] == 'O' && dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON VERTICALE DU JOUEUR*/

        if((A[i][j-1] == 'O' && A[i][j+1] == 'O' && A[i][j+2] == 'O' && dans_matrice(i,j-1) && dans_matrice(i,j+1) && dans_matrice(i,j+2)) || (A[i][j-2] == 'O' && A[i][j-1] == 'O' && A[i][j+1] == 'O' && dans_matrice(i,j-2) && dans_matrice(i,j-1) && dans_matrice(i,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i][j-3] == 'O' && A[i][j-2] == 'O' && A[i][j-1] == 'O' && dans_matrice(i,j-3) && dans_matrice(i,j-2) && dans_matrice(i,j-1)) || (A[i][j+1] == 'O' && A[i][j+2] == 'O' && A[i][j+3] == 'O' && dans_matrice(i,j+3) && dans_matrice(i,j+2) && dans_matrice(i,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "DECROISSANT" DU JOUEUR*/

        if((A[i-1][j-1] == 'O' && A[i+1][j+1] == 'O' && A[i+2][j+2] == 'O' && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2)) || (A[i-2][j-2] == 'O' && A[i-1][j-1] == 'O' && A[i+1][j+1] == 'O' && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i-3][j-3] == 'O' && A[i-2][j-2] == 'O' && A[i-1][j-1] == 'O' && dans_matrice(i-3,j-3) && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1)) || (A[i+1][j+1] == 'O' && A[i+2][j+2] == 'O' && A[i+3][j+3] == 'O' && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }

        /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "CROISSANT" DU JOUEUR*/

        if((A[i+2][j-2] == 'O' && A[i+1][j-1] == 'O' && A[i-1][j+1] == 'O' && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1)) || (A[i+1][j-1] == 'O' && A[i-1][j+1] == 'O' && A[i-2][j+2] == 'O' && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else if((A[i+3][j-3] == 'O' && A[i+2][j-2] == 'O' && A[i+1][j-1] == 'O' && dans_matrice(i+3,j-3) && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1)) || (A[i-1][j+1] == 'O' && A[i-2][j+2] == 'O' && A[i-3][j+3] == 'O' && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3))){
          A[i][j] = 'X';
          *pointeur = 1;
          return EXIT_SUCCESS;
        }
        else{
          /*NE RIEN FAIRE*/
        }
      }
    }
  }
}

/*FONCTION QUI PERMET DE TRIER DANS L'ORDRE CROISSANT UNE TABLE AVEC UNE STRUCTURE COMPOSE DE 2 NOMBRE */

void tri_tableau(int tab1[COLONNE], int tab2[COLONNE]){
  int tampon, i, j;

  for (i=0; i<COLONNE; i++){
    for(j=i; j<COLONNE; j++){
      if(tab1[j]>tab1[i]){ /* si on inverse le signe d'inégalité on aura le trie croissant */
        tampon = tab1[i];
        tab1[i] = tab1[j];
        tab1[j] = tampon;
        tampon = tab2[i];
        tab2[i] = tab2[j];
        tab2[j] = tampon;
      }
    }
  }
}

/*FONCTION QUI PERMET DE CONNAITRE LE POTENTIEL DE VICTOIRE D'UNE CASE*/

void potentiel_choix_colonne(char A[LIGNE][COLONNE], int *potentiel_case, int i, int j){
  int k;
  int valeur_case = 1;

  if(A[0][j] != ' '){
    *potentiel_case = 0;
  }

  /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON VERTICALE*/

  else{

    if(A[i+1][j] == 'X' && A[i+2][j] == 'X' && A[i+3][j] == 'X' && dans_matrice(i+1,j) && dans_matrice(i+2,j) && dans_matrice(i+3,j)){
      valeur_case = 30;
    }
    else if(A[i+1][j] == 'X' && A[i+2][j] == 'X' && dans_matrice(i+1,j) && dans_matrice(i+2,j)){
      valeur_case = 20;
    }
    else if(A[i+1][j] == 'X' && dans_matrice(i+1,j)){
      valeur_case = 10;
    }
    else{
      valeur_case = 0;
    }

    *potentiel_case = valeur_case;

    /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON HORISONTALE*/

    if((A[i][j-1] == 'X' && A[i][j+1] == 'X' && A[i][j+2] == 'X' && dans_matrice(i,j-1) && dans_matrice(i,j+1) && dans_matrice(i,j+2)) || (A[i][j-2] == 'X' && A[i][j-1] == 'X' && A[i][j+1] == 'X' && dans_matrice(i,j-2) && dans_matrice(i,j-1) && dans_matrice(i,j+1))){
      valeur_case = 30;
    }
    else if((A[i][j-3] == 'X' && A[i][j-2] == 'X' && A[i][j-1] == 'X' && dans_matrice(i,j-3) && dans_matrice(i,j-2) && dans_matrice(i,j-1)) || (A[i][j+1] == 'X' && A[i][j+2] == 'X' && A[i][j+3] == 'X' && dans_matrice(i,j+3) && dans_matrice(i,j+2) && dans_matrice(i,j+1))){
      valeur_case = 30;
    }
    else if((A[i][j-1] == 'X' && A[i][j+1] == 'X' && dans_matrice(i,j-1) && dans_matrice(i,j+1)) || (A[i][j+1] == 'X' && A[i][j+2] == 'X' && dans_matrice(i,j+1) && dans_matrice(i,j+2)) || (A[i][j-1] == 'X' && A[i][j-2] == 'X' && dans_matrice(i,j-1) && dans_matrice(i,j-2))){
      valeur_case = 20;
    }
    else if((A[i][j-1] == 'X' && dans_matrice(i,j-1)) || (A[i][j+1] == 'X'&& dans_matrice(i,j+1))){
      valeur_case = 10;
    }
    else{
      valeur_case = 0;
    }

    if(*potentiel_case < valeur_case){
      *potentiel_case = valeur_case;
    }

    /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "DECROISSANT" */

    if((A[i-1][j-1] == 'X' && A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2)) || (A[i-2][j-2] == 'X' && A[i-1][j-1] == 'X' && A[i+1][j+1] == 'X' && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1))){
      valeur_case = 30;
    }
    else if((A[i-3][j-3] == 'X' && A[i-2][j-2] == 'X' && A[i-1][j-1] == 'X' && dans_matrice(i-3,j-3) && dans_matrice(i-2,j-2) && dans_matrice(i-1,j-1)) || (A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && A[i+3][j+3] == 'X' && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2) && dans_matrice(i+3,j+3))){
      valeur_case = 30;
    }
    else if((A[i-1][j-1] == 'X' && A[i+1][j+1] == 'X' && dans_matrice(i-1,j-1) && dans_matrice(i+1,j+1)) || (A[i+1][j+1] == 'X' && A[i+2][j+2] == 'X' && dans_matrice(i+1,j+1) && dans_matrice(i+2,j+2)) || (A[i-1][j-1] == 'X' && A[i-2][j-2] == 'X' && dans_matrice(i-1,j-1) && dans_matrice(i-2,j-2))){
      valeur_case = 20;
    }
    else if((A[i-1][j-1] == 'X' && dans_matrice(i-1,j-1)) || (A[i+1][j+1] == 'X' && dans_matrice(i+1,j+1))){
      valeur_case = 10;
    }
    else{
      valeur_case = 0;
    }

    if(*potentiel_case < valeur_case){
      *potentiel_case = valeur_case;
    }

    /*CAS DU POTENTIEL DE VICTOIRE PAR UNE COMBINAISON EN DIAGONALE "CROISSANT" */

    if((A[i+2][j-2] == 'X' && A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1)) || (A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2))){
      valeur_case = 30;
    }
    else if((A[i+3][j-3] == 'X' && A[i+2][j-2] == 'X' && A[i+1][j-1] == 'X' && dans_matrice(i+3,j-3) && dans_matrice(i+2,j-2) && dans_matrice(i+1,j-1)) || (A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && A[i-3][j+3] == 'X' && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2) && dans_matrice(i-3,j+3))){
      valeur_case = 30;
    }
    else if((A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && dans_matrice(i+1,j-1) && dans_matrice(i-1,j+1)) || (A[i+1][j-1] == 'X' && A[i+2][j-2] == 'X' && dans_matrice(i+1,j-1) && dans_matrice(i+2,j-2)) || (A[i-1][j+1] == 'X' && A[i-2][j+2] == 'X' && dans_matrice(i-1,j+1) && dans_matrice(i-2,j+2))){
      valeur_case = 20;
    }
    else if((A[i+1][j-1] == 'X' && dans_matrice(i+1,j-1)) || (A[i-1][j+1] == 'X') && dans_matrice(i-1,j+1)){
      valeur_case = 10;
    }
    else{
      valeur_case = 0;
    }

    if(*potentiel_case < valeur_case){
      *potentiel_case = valeur_case;
    }
  }
}

/*FONCTION QUI PERMET A L'ORDINATEUR DE PLACER SA PIECE*/

char tour_ordinateur(char A[LIGNE][COLONNE], int tab1[COLONNE], int tab2[COLONNE]){
  int j;
  int indice_position = 0;
  int compteur = 1;
  int deja_jouer = 0;

  tri_tableau(tab1, tab2);
  for(j=0;j<COLONNE;j++){
    if(tab2[j] > tab2[j+1]){
      /* INITIALISATION DU GENERATEUR DE NOMBRE PSEUDO-ALEATOIRE */
      srand(time(NULL));
      indice_position = rand() % compteur;
      printf("%d\n", indice_position);
      j = LIGNE;
    }
    else{
      compteur++;
    }
  }

  while(deja_jouer != 1){
    if(A[0][tab2[indice_position]+1] != ' '){
        indice_position = rand() % compteur;
    }
    else{
      for(j=LIGNE-1; j>= 0 ; j--){
        if(A[j][tab2[indice_position]] == ' '){
          A[j][tab2[indice_position]]='X';
          j=0;
          deja_jouer=1;
        }
      }
    }
  }

}

/*FONCTION QUI PERMET A L'ORDINATEUR DE DETERMINER DANS QUEL COLONNE, IL DEVRAIT JOUER AFIN DE GAGNER*/

int intelligence_artificielle(char A[LIGNE][COLONNE]){
  int i, j;
  int potentiel_case_valeur[COLONNE];
  int potentiel_case_indice[COLONNE] = {0,1,2,3,4,5,6,7};
  int contre = 0;

  contre_attaque(A, &contre);

  if(contre == 1){
    /*PION DEJA PLACER*/
  }

  else{
    for(j=0;j<COLONNE;j++){
      for(i=0;i<LIGNE;i++){
        if((A[i][j] == ' ' && A[0][j] == ' ' && (A[i+1][j] != ' ' || !(dans_matrice(i+1,j))))){ // Case vide, colonne non pleine, en bas, il y a quelque chose ou c'est le bord
          potentiel_choix_colonne(A, &potentiel_case_valeur[j], i, j);
          i = LIGNE;
        }
      }
    }

    tour_ordinateur(A, potentiel_case_valeur, potentiel_case_indice);
  }
}
void tour_ordinateur_debut(char A[LIGNE][COLONNE]){
  if(A[7][3] == ' '){
    A[7][3] = 'X';
  }
  else{
    A[7][4] = 'X';
  }
}
