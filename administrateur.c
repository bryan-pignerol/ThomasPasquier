#include <stdio.h>
#include <string.h>
#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"
#define FICHIER_ARTICLES "bdd/articles.dat"
#define ADMIN 1
#define JOUEUR 0
#define OUI 1
#define NON 0

//Vérifier la correspondance arguments prototype/fonction
void menu_admin(UTILISATEUR profil);//A terme, mettre autre chose que le struct en argument
void menu_edition_utilisateur(UTILISATEUR profil); //Idem
void menu_edition_sauvegarde(UTILISATEUR profil);//A completer
void creation_utilisateur(FILE* utilisateurs);
void renommer_utilisateur(FILE* utilisateurs);
void changer_permission(FILE* utilisateurs);
void supprimer_utilisateur(UTILISATEUR profil, FILE* utilisateurs);
void afficher_liste_utilisateurs(FILE* utilisateurs);
void rechercher_utilisateur();//A completer
void selection_utilisateur(FILE* utilisateurs, char* nom);
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void afficher_pnjs(FILE* fic);
void creer_article(FILE* fic);
void modifier_article(FILE* fic);
void afficher_article(FILE* fic);


// MENU
void menu_admin(UTILISATEUR profil)//A terme, mettre autre chose que le struct en argument
{
    //char nom_profil[TAILLE_NOM] = profil_courant //Profil courant à rajouter
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
        printf("MODIFIER PROFIL D'UN UTILISATEUR..: 2\n\n");//Place le curseur au bon endroit dans le fichier utilisateurs
        printf("-----------BASE DE DONNEES-----------\n");
        printf("CREATION PNJ......................: 3\n");
        printf("MODIFIER PNJ......................: 4\n");
        printf("AFFICHER PNJs.....................: 5\n\n");
        printf("CREER ARTICLE.....................: 6\n");
        printf("MODIFIER ARTICLE..................: 7\n");
        printf("AFFICHER ARTICLES.................: 10\n\n");
        printf("QUITTER...........................: 9\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 0: //Créer utilisateur
                fic = fopen(FICHIER_UTILISATEURS, "a+");
                creation_utilisateur(fic);
                fclose(fic);
                break;

            case 1: //Modifier profil courant
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                // menu_edition_utilisateur(nom);
                fclose(fic);
                break;
                
            case 2: //Modifier autre profil
                fic = fopen(FICHIER_UTILISATEURS, "r+");
                printf("Selectionner le profil à modifier :\n");
                // scanf("%s", nom);//Rajouter variable nom
                //selection_utilisateur(utilisateurs, nom);
                //menu_edition_utilisateur(nom);
                fclose(fic);
                break;
                
            case 3: //Creation PNJ
                fic = fopen(FICHIER_PNJ, "a+");
                creation_pnj(fic);
                fclose(fic);
                break;
            
            case 4: //Modifier PNJ
                fic = fopen(FICHIER_PNJ, "r+");
                fseek(fic, 0, SEEK_SET);
                modifier_pnj(fic);
                fclose(fic);
                break;
            
            case 5: //Afficher PNJ
                fic = fopen(FICHIER_PNJ, "r");
                afficher_pnjs(fic);
                fclose(fic);
                break;

            case 6: //Quitter
                printf("Retour au menu principal\n");//Penser à modifier si on refait la partie menu & auth
                break;

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 6);
}

void menu_edition_utilisateur(UTILISATEUR profil)//Mettre autre chose que le struct en argument
{
    int choix;
    do
    {
        printf("---------MODIFIER UTILISATEUR--------\n");
        printf("RENOMMER..........................: 0\n");
        printf("CHANGER PERMISSIONS...............: 1\n");
        printf("SUPPRIMER.........................: 2\n\n");
        printf("EDITER FICHIER SAUVEGARDE.........: 3\n\n");
        printf("QUITTER...........................: 4\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 0: //Renommer
                // renommer_utilisateur(fic);
                break;

            case 1: //Changer permissions
                // changer_permission(fic);
                break;
                
            case 2: //Supprimer
                /* if (strcmp(fichier_courant, profil.nom) == 0)
                {
                    int nb_admin = 0;
                    while (fread(&profil, sizeof(profil), 1, utilisateurs) != 0 && nb_admin < 2)
                    {
                        if (profil.permissions == ADMIN)
                        {
                            nb_admin++;
                        }
                    }
                    if (nb_admin < 2)
                    {
                        printf("Action interdite : vous êtes le dernier administrateur !\n");
                    }
                    else supprimer_utilisateur(profil);
                }
                else supprimer_utilisateur(profil); */
                break;
                
            case 3: //Editer fichier sauvegarde
                FILE* save;
                // save = fopen(nom_sauvegarde, "r+");//vient de profil.sauvegarde
                //menu_edition_sauvegarde(); //A faire
                fclose(save);
                break;
            
            case 4: //Quitter
                printf("Retour au menu admin\n");
                break;

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 4);
}

// UTILISATEURS
void renommer_utilisateur(FILE* utilisateurs) //Clean
{
    UTILISATEUR profil;
    printf("Veuillez entrer un nom d'utilisateur : ");
    scanf("%s", profil.nom);
    fwrite(&profil, sizeof(profil), 1, utilisateurs);
    fseek(utilisateurs, -sizeof(profil), SEEK_CUR);
}

void creation_utilisateur(FILE* utilisateurs) //Clean, 1 FILE à bouger peut être
{
    UTILISATEUR profil;
    FILE* new_save; //Est-ce qu'on bouge la déclaration ailleurs ?
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
    strcat(profil.sauvegarde, profil.nom);//De là
    strcat(profil.sauvegarde, SUFFIXE_FICHIER_SAUVEGARDE);
    new_save = fopen(profil.sauvegarde, "a+");
    fclose(new_save);//A là, fonction creation_fichier_sauvegarde
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
    if(1)
    {
        int confirmation;
        printf("Etes vous sur de vouloir supprimer votre profil ? Cela vous ramènera au menu principal\n");
        scanf("%s", confirmation);
        if (confirmation == 1)
        {
            //code pour supprimer
        }
    }
    else
    {
        int confirmation;
        printf("Etes vous sur de vouloir supprimer ce profil : %s ?\n", profil.nom); //probablement pas profil.nom
        scanf("%s", confirmation);
        if (confirmation == 1)
        {
            //code pour supprimer
        }
    }
    //fseek(utilisateurs, -sizeof(profil), SEEK_CUR);
}

void afficher_liste_utilisateurs(FILE* utilisateurs)
{
    UTILISATEUR profil;
    printf("Utilisateurs :\n");
    fseek(utilisateurs, 0, SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, utilisateurs) != 0)
	{
		printf("* %s (%d)\n",profil.nom, profil.permissions);
	}
}

void selection_utilisateur(FILE* utilisateurs, char* nom)
{
    UTILISATEUR profil;
    fseek(utilisateurs, 0, SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, utilisateurs) != 0)
	{
		if (strcmp(nom, profil.nom) == 0)
        {
            fseek(utilisateurs, -sizeof(profil), SEEK_CUR);
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
