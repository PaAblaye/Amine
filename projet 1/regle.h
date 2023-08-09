#ifndef regle
#define regle
 
#define max 100

typedef struct {
         char prenom[30];
         char Nom[20];
         char sexe;
         char Metier[30];
         int Annee;
         int salaire;
}employer;

typedef struct {
         int nbr_empl;
         employer tab_empl[max];
}entreprise;

void addemp(char *filename,employer empy);
entreprise * init(char *filename);
void affich_ent(entreprise ent);
void affich_emp(employer emp);

#endif