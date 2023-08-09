#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "regle.h"
//bonjour le monde

int main( int argc , char* argv[]){
    if(argc<2){
        printf("erreur : Nombre d'argument insuffisant\n");
        printf("Usage : %s nom_fichier",argv[0]);
        return 0;
    }

    entreprise *ent;
    ent = init(argv[1]);
    affich_ent(*ent);
     if(ent == NULL){
        return 0;
    }
    employer lay={
        .prenom="layezo",
        .Nom="ndiaye",
        .sexe='H',
        .Metier="inf...",
        .Annee=4,
        .salaire=1200000
    };

    addemp(argv[1],lay);
   
    affich_ent(*ent);
    if(ent == NULL){
        return 0;
    }
     free(ent);
     

    return 0;
}
