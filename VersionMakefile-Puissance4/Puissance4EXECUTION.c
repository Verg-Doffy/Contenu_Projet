#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Puissance4.h"

#define LIGNE 8
#define COLONNE 8

int main(){
    char Matrice[LIGNE][COLONNE];
    int compt=0;
    int continuer = 1;
    int mode;

    init_matrice(Matrice);
    afficher_matrice(Matrice);

    printf("Quel mode voulez vous jouer ? \n Entrer 1 pour le mode solo contre l'ordinateur \n Entrer 2 pour le mode duo avec un ami\n");
    scanf("%d",&mode);
    while(mode < 1 || mode > 2){
      printf("\n\nVous avez entrer un nombre invalide, je répète :\n\n");
      printf("Quel mode voulez vous jouer ? \n Entrer 1 pour le mode solo contre l'ordinateur \n Entrer 2 pour le mode duo avec un ami\n");
      scanf("%d",&mode);
    }

    if(mode == 1){
      Joueur2(Matrice);
      tour_ordinateur_debut(Matrice);
      afficher_matrice(Matrice);
      while(continuer){
          if(continuer){
            Joueur2(Matrice);
            afficher_matrice(Matrice);
            victoire(Matrice, &continuer);
            aucun_vainqueur(Matrice, &continuer);
          }
          if(continuer){
            intelligence_artificielle(Matrice);
            afficher_matrice(Matrice);
            victoire(Matrice, &continuer);
            aucun_vainqueur(Matrice, &continuer);
          }
      }
    }

    else if(mode == 2){
      while(continuer){
          if(continuer){
            Joueur1(Matrice);
            afficher_matrice(Matrice);
            victoire(Matrice, &continuer);
            aucun_vainqueur(Matrice, &continuer);
          }
          if(continuer){
            Joueur2(Matrice);
            afficher_matrice(Matrice);
            victoire(Matrice, &continuer);
            aucun_vainqueur(Matrice, &continuer);
          }
      }
    }
}
