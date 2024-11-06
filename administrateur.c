#include <stdio.h>
#include <string.h>
#include "structures.c"

#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"

void menu_admin();
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void creation_utilisateur(FILE* user);


// MENU
void menu_admin()
{
    char choix[15];
    do
    {
        scanf("%s", choix);
        if(!strcmp(choix, "creation_pnj"))
        {
            FILE* fic = fopen(FICHIER_PNJ, "a+");
            creation_pnj(fic);
            fclose(fic);
        }
    } while (!strcmp(choix, "quitter") || !strcmp(choix, "q"));
}


// UTILISATEURS
void creation_utilisateur(FILE* user) //utilisé par le menu principal & le mode admin
{
    UTILISATEUR utilisateur;
    utilisateur.permissions = 0;
    printf("Veuillez entrer un nom");
    scanf("%s", utilisateur.nom);
    user = fopen("FICHIER_UTILISATEURS", "a+");
    fwrite(&utilisateur, sizeof(utilisateur), 1, user);
}

void changer_permission(UTILISATEUR utilisateur)
{
    if(utilisateur.permissions==0) statut = 
    printf("Statut actuel : %s. Changer statut ?", )
}

// SAUVEGARDE


// BDD
/// PNJ
void creation_pnj(FILE* fic)
{
    PNJ pnj;
    printf("Entrez le nom du PNJ : ");
    scanf("%s", pnj.nom);
    printf("Entrez son rôle : ");
    scanf("%s", pnj.role);
    pnj.faim = 100;
    pnj.soif = 100;
    fwrite(&pnj, sizeof(PNJ), 1, fic);
    printf("PNJ créé\n");
}

void modifier_pnj(FILE *fic)
{
    PNJ pnj;
    char pnj_recherche[TAILLE_NOM];
    printf("Entrez le nom du PNJ recherché : ");
    scanf("%s", pnj_recherche);
    while(fread(&pnj, sizeof(PNJ), 1, fic) != 0)
    {
        if(!strcmp(pnj.nom, pnj_recherche))
        {
            printf("PNJ trouvé : Voulez-vous le modifier ? ");
            
        }
    }
}
