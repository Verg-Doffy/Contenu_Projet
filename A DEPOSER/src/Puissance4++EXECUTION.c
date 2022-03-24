#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/Puissance4++.h"

#define LIGNE 16
#define COLONNE 16

int main(){

    matrice_t Matrice[LIGNE][COLONNE];

    int continuer = 1;
    int mode = 1;
    decs_t j1, j2, j3, j4;

    attribuer(&j1);
    attribuer(&j2);
    attribuer(&j3);
    attribuer(&j4);

    init_matrice(Matrice);
    afficher_matrice(Matrice);


    while(continuer){

      Joueur1(Matrice, &j1);
      afficher_matrice(Matrice);
      victoire(Matrice, &continuer);
      aucun_vainqueur(Matrice, &continuer);
      if(continuer == 0){
        return EXIT_SUCCESS;
      }

      Joueur2(Matrice, &j2);
      afficher_matrice(Matrice);
      victoire(Matrice, &continuer);
      aucun_vainqueur(Matrice, &continuer);
      if(continuer == 0){
        return EXIT_SUCCESS;
      }

      Joueur3(Matrice, &j3);
      afficher_matrice(Matrice);
      victoire(Matrice, &continuer);
      aucun_vainqueur(Matrice, &continuer);
      if(continuer == 0){
        return EXIT_SUCCESS;
      }

      Joueur4(Matrice, &j4);
      afficher_matrice(Matrice);
      victoire(Matrice, &continuer);
      aucun_vainqueur(Matrice, &continuer);
      if(continuer == 0){
        return EXIT_SUCCESS;
      }

    }

}
