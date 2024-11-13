#include <stdio.h>
#include <string.h>

#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"
#define ADMIN 1
#define JOUEUR 0
#define OUI 1
#define NON 0

void menu_admin();
void creation_utilisateur(FILE* user);
void changer_permission(FILE* utilisateurs);
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void afficher_pnjs(FILE* fic);


// MENU
void menu_admin()
{
    int choix;
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
        scanf("%d", choix);
        switch (choix)
        {
            case 0:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                creation_utilisateur(fic);
                fclose(fic);
                break;

            case 1:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                //menu edition
                fclose(fic);
                break;
                
            case 2:
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                //selection utilisateur
                //menu edition
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
                fseek(fic, 0, SEEK_SET);
                afficher_pnjs(fic);
                fclose(fic);
                
            case 6:
                //Ramène au menu joueur

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 6);
}


// UTILISATEURS (penser à rajouter les prototypes)
void renommer_utilisateur(FILE* utilisateurs)
{
    UTILISATEUR nouvelUtilisateur;
    //fseek(utilisateurs, 0, SEEK_SET); //
    printf("Veuillez entrer un nom d'utilisateur : ");
    scanf("%s", nouvelUtilisateur.nom);
    fwrite(&nouvelUtilisateur, sizeof(nouvelUtilisateur), 1, utilisateurs);
}

void creation_utilisateur(FILE* utilisateurs) //utilisé par le menu principal & le mode admin
{
    UTILISATEUR utilisateur;

    printf("Entrez le nom d'utilisateur : ");
    scanf("%s", utilisateur.nom);
    do
    {
        printf("Entrez sa permission (0 - JOUEUR | 1 - ADMIN) : ");
        scanf("%d", utilisateur.permissions);
        if(utilisateur.permissions != JOUEUR && utilisateur.permissions != ADMIN)
        {
            printf("ERREUR : Permission non valide. Recommencez.");
        }
    } while(utilisateur.permissions != JOUEUR && utilisateur.permissions != ADMIN);

    //Associer un fichier
    fwrite(&utilisateur, sizeof(UTILISATEUR), 1, utilisateurs);
}

void changer_permission(FILE* utilisateurs)
{
    UTILISATEUR utilisateur;
    int changer;
    printf("Statut actuel : %s. Changer statut ? OUI/NON", utilisateur.permissions);
    scanf("%s", changer);
    if(changer == OUI & utilisateur.permissions == ADMIN) utilisateur.permissions = JOUEUR;
    else if(changer == OUI & utilisateur.permissions == JOUEUR) utilisateur.permissions = ADMIN;
}

void supprimer_utilisateur(UTILISATEUR utilisateur, FILE* profil)
{
    fseek(profil, 0, SEEK_SET);

}

void afficher_liste_utilisateurs(FILE* utilisateurs)
{
    
}

void selection_utilisateur(FILE* utilisateurs)
{

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

    if(fread(&pnj, sizeof(PNJ), 1, fic) == 0)
    {
        printf("Il n'y a aucun PNJ de créé\n");
        return;
    }

    while(fread(&pnj, sizeof(PNJ), 1, fic) != 0)
    {
        printf("Nom : %s\n", pnj.nom);
        printf("Rôle : %s\n\n", pnj.role);
    }
}
