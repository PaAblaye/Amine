#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "regle.h"

entreprise * init(char *filename){
    entreprise *e;
    FILE *fic;
    fic=fopen(filename,"r");

    e=calloc(1,sizeof(entreprise));


    if(fic==NULL){
        printf("erreur d'ouverture du fichier\n");
        return NULL;
    }
    int i=0;
    int res;
    e->nbr_empl=0;
    do{
        res=fscanf(fic,"%s%s %c%s%d%d",
                    e->tab_empl[i].prenom,
                    e->tab_empl[i].Nom,
                    &(e->tab_empl[i].sexe),
                    e->tab_empl[i].Metier,
                    &(e->tab_empl[i].Annee),
                    &(e->tab_empl[i].salaire));
        if(res>0){
            e->nbr_empl++;
            i++;
        }
        else if (ferror(fic)){
            perror("erreur lors de la lecture\n");
            return NULL;
        }
    }while(!feof(fic));

    fclose(fic);
   
    return e;
}

void affich_emp(employer emp){
     printf("%s   %s %c  %s  %d   %d\n",
                          emp.prenom,
                          emp.Nom,
                          emp.sexe,
                          emp.Metier,
                          emp.Annee,
                          emp.salaire);
}

void affich_ent(entreprise ent ){
    int i;
    entreprise et=ent;
    for(i=0;i<(et.nbr_empl);i++){
      affich_emp(et.tab_empl[i]);
    }
}

void addemp(char *filename,employer empy){
     FILE *fic;
    fic=fopen(filename,"a");

    if(fic==NULL){
        printf("erreur d'ouverture du fichier\n");
        return ;
    }
 printf("\n");
    int res;
    res=fprintf(fic,"%s %s %c %s %d %d\n",
                                        empy.prenom,
                                        empy.Nom,
                                        empy.sexe,
                                        empy.Metier,
                                        empy.Annee,
                                        empy.salaire);
    if(res<=0){
        perror("erreur lors de l'ajout\n");
    }
    else
        printf("ajout avec succes\n");
}

