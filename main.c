#include <stdio.h>
#include <string.h>
#include "structures.c"
#include "save.c"
#include "events.c"
#include "administrateur.c"

void initialiser();
UTILISATEUR connexion();
void menu(UTILISATEUR profil);
void nouvelle_partie(UTILISATEUR profil);
void menu_jeu(SAVE sauvegarde);

int main(int argc, char* argv)
{
    UTILISATEUR utilisateur_courant;
    printf(" _____ _   _  ___  __  __    _    ____    ____   _    ____   ___  _   _ ___ _____ ____  \n");
    printf("|_   _| | | |/ _ \\|  \\/  |  / \\  / ___|  |  _ \\ / \\  / ___| / _ \\| | | |_ _| ____|  _ \\ \n");
    printf("  | | | |_| | | | | |\\/| | / _ \\ \\___ \\  | |_) / _ \\ \\___ \\| | | | | | || ||  _| | |_) |\n");
    printf("  | | |  _  | |_| | |  | |/ ___ \\ ___) | |  __/ ___ \\ ___) | |_| | |_| || || |___|  _ < \n");
    printf("  |_| |_| |_|\\___/|_|  |_/_/   \\_\\____/  |_| /_/   \\_\\____/ \\__\\_ \\___/|___|_____|_| \\_\\\n");
    printf("    ░█░░░█▀▀░░░█▀▀░█░█░█▀█░█▄█░█▀▀░█░█░█▀▄░░░█▀▄░█▀▀░░░█░░░▀░█▀▀░█▀▀░█▀█░█▀█░█▀▀░█▀▀\n");
    printf("    ░█░░░█▀▀░░░█░░░█▀█░█░█░█░█░█▀▀░█░█░█▀▄░░░█░█░█▀▀░░░█░░░░░█▀▀░▀▀█░█▀▀░█▀█░█░░░█▀▀\n");
    printf("    ░▀▀▀░▀▀▀░░░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░░░▀▀░░▀▀▀░░░▀▀▀░░░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀▀▀\n\n");
    
    initialiser();
    printf("CONNEXION UTILISATEUR\n");
    utilisateur_courant = connexion();
    menu(utilisateur_courant);
    return 0;
}


void initialiser()
{
    // OUVRE TOUS LES FICHIERS
    FILE* fic;
    fic = fopen(FICHIER_UTILISATEURS, "a+");
    fclose(fic);
    fic = fopen(FICHIER_PNJ, "a+");
    fclose(fic);
}


UTILISATEUR connexion()
{
    UTILISATEUR utilisateur;
    int sortie = 0;
    FILE* fic_utilisateur = fopen(FICHIER_UTILISATEURS, "r+");
    char nom[TAILLE_NOM];
    while(sortie == 0)
    {
        printf("Entrez votre nom d'utilisateur : ");
        scanf("%s", nom);
        printf("%s\n", nom);
        while(fread(&utilisateur, sizeof(UTILISATEUR), 1, fic_utilisateur) != 0)
        {
            if(!strcmp(nom, utilisateur.nom))
            {
                fclose(fic_utilisateur);
            }
        }
        if(strcmp(nom, utilisateur.nom))
        {
            printf("ERREUR : Utilisateur non trouvé. Recommencez.\n");
            fseek(fic_utilisateur, 0, SEEK_SET);
        }
        else
        {
            sortie =  1;
        }
    }
    return utilisateur;
}


void menu(UTILISATEUR profil)
{
    SAVE sauvegarde;
    int choix;
    do {
        printf("1. Nouvelle partie\n");
        printf("2. Charger sauvegarde\n");
        printf("3. Menu admin\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix :  ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            nouvelle_partie(profil);
            //demande a l utilisateur d entrer un nom et cree un fichier de sauvegarde et un profil (+erreur deja pris)
            break;
        case 2:
            // charger_sauvegarde();//recupere le nom du fichier de sauvegarde dans le profil et le charge (+erreur si non trouve)
            menu_jeu(sauvegarde);
            break;
        case 3:
            menu_admin(profil);
            break;
        
        case 4:
            break;

        default:
            printf("Erreur, commande non trouvée...");
        }
    } while(choix != 4);

    // fclose(fichier);  // Fermer le fichier a la fin du programme

}


void nouvelle_partie(UTILISATEUR profil)
{
    nouvelle_sauvegarde(profil);
    return;
}


// JEU
void menu_jeu(SAVE sauvegarde)
{
    int en_jeu = 1;
    do
    {
        int jour = sauvegarde.jour;
        int actions = 3;
        printf("LIEU : CENTRE DE L'ISS\n");
        do
        {
            char input[30];
            printf("Quel action voulez-vous effectuer ? : ");
            fgets(input, 100, stdin);

            // ORDINATEUR CENTRAL
            if(strstr(input, "ordinateur") != NULL)
            {
                int ordinateur = 1;
                printf("LIEU : ORDINATEUR CENTRAL\n");
                do
                {
                    printf("Que faire ? : ");
                    fgets(input, 100, stdin);
                    if(strstr(input, "regarder") != NULL)
                    {
                        printf("Un ordinateur à la pointe de la technologie. Profitez-en, un chômeur comme vous n'en verra pas souvent.\n");
                    }
                    else if(strstr(input, "actualites") != NULL || strstr(input, "journal") != NULL|| strstr(input, "lire") != NULL)
                    {
                        lire_actualites(sauvegarde);
                    }
                    else if(strstr(input, "tinder") != NULL)
                    {
                        printf("Rencontre les aliens les plus proches de ta galaxie <3\n");
                    }
                    else if(strstr(input, "partir") != NULL  || strstr(input, "sortir") != NULL)
                    {
                        ordinateur = 0;
                    }
                } while(ordinateur == 1);
            }

            
            // PLACARD
            if(strstr(input, "placard") != NULL)
            {
                int placard = 1;
                printf("LIEU : PLACARD ETRANGE\n");
                do
                {
                    printf("Que faire ? : ");
                    fgets(input, 100, stdin);
                    if(strstr(input, "regarder") != NULL)
                    {
                        printf("Ce placard est loin d'être commode et n'est pas cohérent avec l'environnement spatial... Il y a un sac et des livres.\n");
                    }
                    else if(strstr(input, "ouvrir_sac") != NULL)
                    {

                    }
                    else if(strstr(input, "livre") != NULL)
                    {
                        printf("Vous trouvez une version marseillaise des Misérables de Victor Hugo ainsi qu'un livre de patisserie.\n");
                        printf("Quel livre lire ? : ");
                        fgets(input, 100, stdin);
                        if(strstr(input, "miserable"))
                        {
                            livre_miserables();
                        } 
                        else if (strstr(input, "patisserie"))
                        {
                            livre_cuisine();
                        }
                        else 
                        {
                            printf("");
                        }
                    }
                    else if(strstr(input, "partir") != NULL || strstr(input, "sortir") != NULL)
                    {
                        placard = 0;
                    }
                } while (placard == 1);
            }


            // COUCHETTE
            if(strstr(input, "couchette") != NULL || strstr(input, "dormir") != NULL)
            {
                int couchette = 1;
                printf("LIEU : COUCHETTE\n");
                do
                {
                    printf("Que faire ? : ");
                    fgets(input, 100, stdin);
                    if(strstr(input, "regarder") != NULL)
                    {
                        printf("C'est ici que tout le monde se repose. Vous avez aussi une baie vitrée avec vue sur la Voie Lactée et le centre Mayol. Attendez, c'est pas ma mère là-bas ?  Quand il n'y a plus de place, vous pouvez allez dormir dehors.");
                    }
                    else if (strstr(input, "journal") != NULL)
                    {
                        journal_intime();
                    }
                    else if(strstr(input, "partir") != NULL || strstr(input, "sortir") != NULL)
                    {
                        couchette = 0;
                    }

                } while (couchette == 1);
                
            }


            // SYSTEME
            if(strstr(input, "sauvegarder") != NULL)
            {}

            if(strstr(input, "quitter") != NULL)
            {}
        } while(actions != 3);
        
    } while(en_jeu == 1);
}
