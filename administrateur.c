#include <stdio.h>
#include <string.h>

#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"
#define ADMIN 1
#define JOUEUR 0
#define OUI 1
#define NON 0

void menu_admin(UTILISATEUR profil);
void menu_edition_utilisateur(UTILISATEUR profil);
void creation_utilisateur(FILE* utilisateurs);
void renommer_utilisateur(FILE* utilisateurs);
void changer_permission(FILE* utilisateurs);
void supprimer_utilisateur(UTILISATEUR profil, FILE* utilisateurs);
void afficher_liste_utilisateurs(FILE* utilisateurs);
void selection_utilisateur(FILE* utilisateurs);
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void afficher_pnjs(FILE* fic);


// MENU
void menu_admin(UTILISATEUR profil)
{
    int choix;
    /* if(profil.permissions != ADMIN)
    {
        printf("ERREUR : Vous n'avez pas les permissions nécessaires pour accéder au menu administrateur.\n");
        return;
    } */
    do
    {
        FILE* fic;
        printf("-------------UTILISATEUR-------------\n");
        printf("CREER UTILISATEUR.................: 0\n");
        printf("MODIFIER PROFIL COURANT...........: 1\n");
        printf("MODIFIER PROFIL D'UN UTILISATEUR..: 2\n\n");
        printf("-----------BASE DE DONNEES-----------\n");
        printf("CREATION PNJ......................: 3\n");
        printf("MODIFIER PNJ......................: 4\n");
        printf("AFFICHER PNJs.....................: 5\n\n");
        printf("QUITTER...........................: 6\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 0:
                fic = fopen(FICHIER_UTILISATEURS, "a+");
                creation_utilisateur(fic);
                fclose(fic);
                break;

            case 1:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                void menu_edition_utilisateur(UTILISATEUR profil);
                fclose(fic);
                break;
                
            case 2:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                //selection utilisateur
                void menu_edition_utilisateur(UTILISATEUR profil);
                fclose(fic);
                break;
                
            case 3:
                fic = fopen(FICHIER_PNJ, "a+");
                creation_pnj(fic);
                fclose(fic);
                break;
            
            case 4:
                fic = fopen(FICHIER_PNJ, "r+");
                fseek(fic, 0, SEEK_SET);
                modifier_pnj(fic);
                fclose(fic);
                break;
            
            case 5:
                fic = fopen(FICHIER_PNJ, "r");
                afficher_pnjs(fic);
                fclose(fic);
                break;

            case 6:
                printf("Retour au menu principal\n");
                break;

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 6);
}

void menu_edition_utilisateur(UTILISATEUR profil)
{
    int choix;
    do
    {
        FILE* fic;
        printf("----------MODIFIER UTILISATEUR---------\n");
        printf("RENOMMER............................: 0\n");
        printf("CHANGER PERMISSIONS.................: 1\n");
        printf("SUPPRIMER...........................: 2\n\n");
        printf("EDITER FICHIER SAUVEGARDE...........: 3\n\n");
        printf("QUITTER.............................: 4\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 0:
                fic = fopen(FICHIER_UTILISATEURS, "a+");
                renommer_utilisateur(fic);
                fclose(fic);
                break;

            case 1:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                changer_permission(fic);
                fclose(fic);
                break;
                
            case 2:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                //supprimer
                fclose(fic);
                break;
                
            case 3:
                fic = fopen(FICHIER_PNJ, "a+");
                //menu edition sauvegarde
                fclose(fic);
                break;
            
            case 4:
                printf("Retour au menu principal\n");
                break;

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 4);
}

// UTILISATEURS (penser à rajouter les prototypes)
void renommer_utilisateur(FILE* utilisateurs)
{
    UTILISATEUR profil;
    //fseek(utilisateurs, 0, SEEK_SET); //
    printf("Veuillez entrer un nom d'utilisateur : ");
    scanf("%s", profil.nom);
    fwrite(&profil, sizeof(profil), 1, utilisateurs);
}

void creation_utilisateur(FILE* utilisateurs) //utilisé par le menu principal & le mode admin
{
    UTILISATEUR profil;

    printf("Entrez le nom d'utilisateur : ");
    scanf("%s", profil.nom);
    do
    {
        printf("Entrez sa permission (0 - JOUEUR | 1 - ADMIN) : ");
        scanf("%d", profil.permissions);
        if(profil.permissions != JOUEUR && profil.permissions != ADMIN)
        {
            printf("ERREUR : Permission non valide. Recommencez.");
        }
    } while(profil.permissions != JOUEUR && profil.permissions != ADMIN);

    //Associer un fichier de sauvegarde
    fwrite(&profil, sizeof(UTILISATEUR), 1, utilisateurs);
}

void changer_permission(FILE* utilisateurs)
{
    UTILISATEUR profil;
    int changer;
    printf("Statut actuel : %s. Changer statut ? OUI/NON", profil.permissions);
    scanf("%s", changer);
    if(changer == OUI & profil.permissions == ADMIN) profil.permissions = JOUEUR;
    else if(changer == OUI & profil.permissions == JOUEUR) profil.permissions = ADMIN;
    fwrite(&profil, sizeof(profil), 1, utilisateurs);
}

void supprimer_utilisateur(UTILISATEUR profil, FILE* utilisateurs)
{
    fseek(utilisateurs, 0, SEEK_SET);

}

void afficher_liste_utilisateurs(FILE* utilisateurs)
{
    UTILISATEUR profil;
    printf("Utilisateurs :\n");
    fseek(utilisateurs,0,SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, utilisateurs) != 0)
	{
		printf("* %s (%d)\n",profil.nom, profil.permissions);
	}
}

void selection_utilisateur(FILE* utilisateurs, char nom)
{
    UTILISATEUR profil;
    fseek(utilisateurs, 0, SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, utilisateurs) != 0)
	{
		if (strcmp(nom, profil.nom) == 0)
        {
            
        }
    }
}

// SAUVEGARDE


// BDD
/// PNJ
void creation_pnj(FILE* fic)
{
    PNJ pnj;
    printf("Entrez le prénom du PNJ : ");
    scanf("%s", pnj.prenom);
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
            printf("Entrez le prénom du PNJ : ");
            scanf("%s", pnj.prenom);
            printf("Entrez le nom du PNJ : ");
            scanf("%s", pnj.nom);
            printf("Entrez son rôle : ");
            scanf("%s", pnj.role);
            pnj.faim = 100;
            pnj.soif = 100;
            fseek(fic, -sizeof(PNJ), SEEK_CUR);
            fwrite(&pnj, sizeof(PNJ), 1, fic);
            printf("PNJ modifié\n");
            return;
        }
    }
    printf("ERREUR : PNJ non trouvé");
}

void afficher_pnjs(FILE* fic)
{
    PNJ pnj;
    fseek(fic, 0, SEEK_SET);
    if(fread(&pnj, sizeof(PNJ), 1, fic) == 0)
    {
        printf("Il n'y a aucun PNJ de créé\n");
        return;
    }

    printf("Prénom : %s\n", pnj.prenom);
    printf("Nom : %s\n", pnj.nom);
    printf("Rôle : %s\n\n", pnj.role);
    while(fread(&pnj, sizeof(PNJ), 1, fic) != 0)
    {
        printf("Prénom : %s\n", pnj.prenom);
        printf("Nom : %s\n", pnj.nom);
        printf("Rôle : %s\n\n", pnj.role);
    }
}
