#include <stdio.h>
#include <string.h>
#include "structures.c"

#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"
#define ADMIN "1"
#define JOUEUR "0"
#define OUI "1"
#define NON "0"

void menu_admin();
void creation_utilisateur(FILE* user);
void changer_permission(UTILISATEUR utilisateur);
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void afficher_pnjs(FILE* fic);


// MENU
void menu_admin()
{
    int choix;
    do
    {
        printf("-------------UTILISATEUR-------------\n");
        printf("MODIFIER PROFIL COURANT...........: 1\n");
        printf("MODIFIER PROFIL D'UN UTILISATEUR..: 2\n\n");
        printf("-----------BASE DE DONNEES-----------\n");
        printf("AJOUTER PNJ.......................: 3\n");
        printf("MODIFIER PNJ......................: 4\n");
        printf("AFFICHER PNJs.....................: 5\n\n");
        printf("QUITTER...........................: 0\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", choix);
        switch (choix)
        {
        case 3:
            FILE* fic = fopen(FICHIER_PNJ, "a+");
            creation_pnj(fic);
            fclose(fic);
            break;
        
        case 4:
            FILE* fic = fopen(FICHIER_PNJ, "r+");
            fseek(fic, 0, SEEK_SET);
            modifier_pnj(fic);
            fclose(fic);
            break;
        
        case 5:
            FILE* fic = fopen(FICHIER_PNJ, "r");
            fseek(fic, 0, SEEK_SET);
            afficher_pnjs(fic);
            fclose(fic);

        default:
            break;
        }
    } while (choix != 0);
}


// UTILISATEURS (penser à rajouter les prototypes)
void renommer_utilisateur(UTILISATEUR utilisateur)
{
    printf("Veuillez entrer un nom");
    scanf("%s", utilisateur.nom);
}

void creation_utilisateur(FILE* user) //utilisé par le menu principal & le mode admin
{
    UTILISATEUR utilisateur;
    utilisateur.permissions = JOUEUR;
    renommer_utilisateur(utilisateur);
    //user = fopen("FICHIER_UTILISATEURS", "a+");
    fwrite(&utilisateur, sizeof(utilisateur), 1, user);
}

void changer_permission(UTILISATEUR utilisateur)
{
    int changer;
    printf("Statut actuel : %s. Changer statut ? OUI/NON", utilisateur.permissions);
    scanf("%s", changer);
    if(changer == "OUI" & utilisateur.permissions == "ADMIN") utilisateur.permissions = "JOUEUR";
    else if(changer == "OUI" & utilisateur.permissions == "JOUEUR") utilisateur.permissions = "ADMIN";
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
            printf("Entrez le nom du PNJ : ");
        scanf("%s", pnj.nom);
        printf("Entrez son rôle : ");
        scanf("%s", pnj.role);
        pnj.faim = 100;
        pnj.soif = 100;
        fseek(fic, -sizeof(PNJ), SEEK_CUR);
        fwrite(&pnj, sizeof(PNJ), 1, fic);
        printf("PNJ modifié\n");
        }
    }
}

void afficher_pnjs(FILE* fic)
{
    PNJ pnj;

    if(fread(&pnj, sizeof(PNJ), 1, fic) == 0)
    {
        printf("Il n'y a aucun PNJ de créé\n");
        return;
    }

    while(fread(&pnj, sizeof(PNJ), 1, fic) != 0)
    {
        prinft("Nom : %s\n", pnj.nom);
        printf("Rôle : %s\n\n", pnj.role);
    }
}
