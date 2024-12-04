#include <stdio.h>
#include <string.h>
#define FICHIER_UTILISATEURS "bdd/utilisateurs.dat"
#define FICHIER_PNJ "bdd/pnj.dat"
#define FICHIER_ARTICLES "bdd/articles.dat"
#define FICHIER_DICTIONNAIRE "bdd/dictionnaire.dat"
#define FICHIER_HISTORIQUE "text.txt"
#define ADMIN 1
#define JOUEUR 0
#define OUI 1
#define NON 0

//Vérifier la correspondance arguments prototype/fonction
void menu_admin(UTILISATEUR profil);
void menu_edition_utilisateur(UTILISATEUR profil);
void menu_edition_sauvegarde(UTILISATEUR profil);//A completer
void creation_utilisateur(FILE* liste_utilisateurs);
void renommer_utilisateur(FILE* liste_utilisateurs);
void changer_permission(FILE* liste_utilisateurs);
void supprimer_utilisateur(UTILISATEUR profil, FILE* liste_utilisateurs);
void afficher_liste_utilisateurs(FILE* liste_utilisateurs);
void rechercher_utilisateur();//A completer
void selection_utilisateur(FILE* liste_utilisateurs, char* utilisateur_cible);
void creation_pnj(FILE* fic);
void modifier_pnj(FILE* fic);
void afficher_pnjs(FILE* fic);
void creer_article(FILE* fic);
void modifier_article(FILE* fic);
void afficher_article(FILE* fic);
void ajouter_mot_dictionnaire(FILE* fic);


// MENU
void menu_admin(UTILISATEUR profil)
{
    int choix;
    if(profil.permissions != ADMIN)
    {
        printf("ERREUR : Vous n'avez pas les permissions nécessaires pour accéder au menu administrateur.\n");
    }
    else
    {
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
            printf("AFFICHER ARTICLES.................: 8\n\n");
            printf("AJOUTER/SUPPRIMER MOTS CHATBOT....: 9\n\n");
            printf("QUITTER...........................: 10\n\n");
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
                    menu_edition_utilisateur(profil.nom);
                    fclose(fic);
                    break;
                    
                case 2: //Modifier autre profil
                    fic = fopen(FICHIER_UTILISATEURS, "r+");
                    printf("Selectionner le profil à modifier :\n");
                    scanf("%s", utilisateur_cible);
                    selection_utilisateur(liste_utilisateurs, utilisateur_cible);
                    menu_edition_utilisateur(utilisateur_cible);
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

                case 6: //Créer article

                case 7: //Modifier article

                case 8: //Afficher article

                case 9: // ajouter / supprimer mots chatbot
                    fic = fopen(FICHIER_DICTIONNAIRE, "a");
                    ajouter_mot_dictionnaire(fic);
                    fclose(fic);
                    break;

                case 10: //Quitter
                    printf("Retour au menu principal\n");//Penser à modifier si on refait la partie menu & auth
                    break;

                default:
                    printf("ERREUR : Commande non reconnue\n\n");
                    break;
            }
        } while (choix != 10);
    }
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
                    while (fread(&profil, sizeof(profil), 1, liste_utilisateurs) != 0 && nb_admin < 2)
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
                printf("");
                fclose(save);
                break;
            
            case 4: //Quitter
                printf("Retour au menu admin\n");
                break;

            default:
                printf("ERREUR : Commande non reconnue\n\n");
                break;
        }
    } while (choix != 4); //S'assurer que la fonction supprimer sort aussi d'ici
}

// UTILISATEURS
void renommer_utilisateur(FILE* liste_utilisateurs) //Clean
{
    UTILISATEUR profil;
    printf("Veuillez entrer un nom d'utilisateur : ");
    scanf("%s", profil.nom);
    fwrite(&profil, sizeof(profil), 1, liste_utilisateurs);
    fseek(liste_utilisateurs, -sizeof(profil), SEEK_CUR);
}

void creation_utilisateur(FILE* liste_utilisateurs) //Clean, 1 FILE à bouger peut être
{
    UTILISATEUR profil;
    FILE* new_save;
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
    fwrite(&profil, sizeof(UTILISATEUR), 1, liste_utilisateurs);
}

void changer_permission(FILE* liste_utilisateurs)
{
    UTILISATEUR profil;
    int changer;
    printf("Statut actuel : %s. Changer statut ? OUI/NON", profil.permissions);
    scanf("%s", changer);
    if(changer == OUI & profil.permissions == ADMIN) profil.permissions = JOUEUR;
    else if(changer == OUI & profil.permissions == JOUEUR) profil.permissions = ADMIN;
    fwrite(&profil, sizeof(profil), 1, liste_utilisateurs);
}

void supprimer_utilisateur(UTILISATEUR profil, FILE* liste_utilisateurs)//profil => char nom
{/*
    if(0)//strcmp(profil_courant, nom)==0
    {
        int confirmation;
        printf("Etes vous sur de vouloir supprimer votre profil ? Cela vous ramènera au menu principal\n");
        scanf("%s", confirmation);
        if (confirmation == 1)
        {
            FILE* tampon;
            UTILISATEUR profil;
            tampon = fopen("tampon_suppression.dat", "w");
            while (fread(&profil, sizeof(profil), 1, liste_utilisateurs) != 0) //Ecriture du nouveau fichier utilisateur dans le fichier tampon
	        {
                if (strcmp("nom", profil.nom) != 0)
                {
                    fwrite(&profil, sizeof(profil), 1, tampon);
                }
            }
            fclose (liste_utilisateurs);
            fopen (".dat", "w");
            while (fread(&profil, sizeof(profil), 1, tampon) != 0) //Remplacer l'ancien fichier utilisateur par le nouveau
	        {
                if (strcmp("nom", profil.nom) != 0)
                {
                    fwrite(&profil, sizeof(profil), 1, liste_utilisateurs);
                }
            }
            fclose(tampon);
            fclose (liste_utilisateurs);
            fopen(".dat", "r+");
        }
        //fseek(liste_utilisateurs, -sizeof(profil), SEEK_CUR); => retourner à la position du profil courant ?
    }
    else
    {
        int confirmation;
        printf("Etes vous sur de vouloir supprimer ce profil : %s ?\n", profil.nom); //probablement pas profil.nom
        scanf("%s", confirmation);
        if (confirmation == 1)
        {
            FILE* tampon;
            UTILISATEUR profil;
            tampon = fopen("tampon_suppression.dat", "w");
            while (fread(&profil, sizeof(profil), 1, liste_utilisateurs) != 0) //Ecriture du nouveau fichier utilisateur dans le fichier tampon
	        {
                if (strcmp("nom", profil.nom) != 0)
                {
                    fwrite(&profil, sizeof(profil), 1, tampon);
                }
            }
            fclose (liste_utilisateurs);
            fopen (".dat", "w");
            while (fread(&profil, sizeof(profil), 1, tampon) != 0) //Remplacer l'ancien fichier utilisateur par le nouveau
	        {
                if (strcmp("nom", profil.nom) != 0)
                {
                    fwrite(&profil, sizeof(profil), 1, liste_utilisateurs);
                }
            }
            fclose(tampon);
            fclose (liste_utilisateurs);
            fopen(".dat", "r+");
        }
    }*/
    //fseek(liste_utilisateurs, -sizeof(profil), SEEK_CUR); => retourner à la position du profil courant ?
}

void afficher_liste_utilisateurs(FILE* liste_utilisateurs)
{
    UTILISATEUR profil;
    printf("Utilisateurs :\n");
    fseek(liste_utilisateurs, 0, SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, liste_utilisateurs) != 0)
	{
		printf("* %s (%d)\n",profil.nom, profil.permissions);
	}
}

void selection_utilisateur(FILE* liste_utilisateurs, char* utilsateur_cible)
{
    UTILISATEUR profil;
    fseek(liste_utilisateurs, 0, SEEK_SET);
    while (fread(&profil, sizeof(profil), 1, liste_utilisateurs) != 0)
	{
		if (strcmp(nom, profil.nom) == 0)
        {
            fseek(liste_utilisateurs, -sizeof(profil), SEEK_CUR);
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
        printf("Il n'y a aucun PNJ de créé.\n");
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

void creer_article(FILE* fic)
{
    ARTICLE article;
    printf("Entrez le nom de l'article : ");
    scanf("%s", article.nom);
    printf("Entrez le jour où se déclenchera l'article : ");
    scanf("%s", article.jour);
    printf("Entrez le contenu de l'article :\n");
    scanf("%s", article.contenu);
}

void afficher_articles(FILE* fic)
{
    ARTICLE article;
    fseek(fic, 0, SEEK_SET);
    if(fread(&article, sizeof(ARTICLE), 1, fic) == 0)
    {
        printf("Il n'y a aucun article de créé.\n");
        return;
    }
    printf("Nom de l'article : %s\n", article.nom);
    printf("Jour de l'article : %d\n", article.jour);
    printf("Contenu de l'article :\n%s\n\n", article.contenu);
    while(fread(&article, sizeof(ARTICLE), 1, fic) != 0)
    {
        printf("Nom de l'article : %s\n", article.nom);
        printf("Jour de l'article : %d\n", article.jour);
        printf("Contenu de l'article :\n%s\n\n", article.contenu);
    }
}

void ajouter_mot_dictionnaire(FILE* fic)
{
    char mot[TAILLE_NOM];
    printf("Entrez votre mot : ");
    scanf("%s", mot);
    fwrite(mot, TAILLE_NOM, 1, fic);
}
