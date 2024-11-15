#include <stdio.h>
#include <string.h>
#include "structures.c"
#include "save.c"
#include "administrateur.c"
#include "events.c"

void initialiser();
UTILISATEUR connexion();
void menu(UTILISATEUR profil);
void nouvelle_partie(FILE* fic);
void menu_jeu(SAVE sauvegarde);

int main(int argc, char* argv)
{
    UTILISATEUR utilisateur_courant;
    printf(" _____ _   _  ___  __  __    _    ____    ____   _    ____   ___  _   _ ___ _____ ____  \n");
    printf("|_   _| | | |/ _ \\|  \\/  |  / \\  / ___|  |  _ \\ / \\  / ___| / _ \\| | | |_ _| ____|  _ \\ \n");
    printf("  | | | |_| | | | | |\\/| | / _ \\ \\___ \\  | |_) / _ \\ \\___ \\| | | | | | || ||  _| | |_) |\n");
    printf("  | | |  _  | |_| | |  | |/ ___ \\ ___) | |  __/ ___ \\ ___) | |_| | |_| || || |___|  _ < \n");
    printf("  |_| |_| |_|\\___/|_|  |_/_/   \\_\\____/  |_| /_/   \\_\\____/ \\__\\_ \\___/|___|_____|_| \\_\\\n");
    printf("░█░░░█▀▀░░░█▀▀░█░█░█▀█░█▄█░█▀▀░█░█░█▀▄░░░█▀▄░█▀▀░░░█░░░▀░█▀▀░█▀▀░█▀█░█▀█░█▀▀░█▀▀\n");
    printf("░█░░░█▀▀░░░█░░░█▀█░█░█░█░█░█▀▀░█░█░█▀▄░░░█░█░█▀▀░░░█░░░░░█▀▀░▀▀█░█▀▀░█▀█░█░░░█▀▀\n");
    printf("░▀▀▀░▀▀▀░░░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░░░▀▀░░▀▀▀░░░▀▀▀░░░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀▀▀\n\n");
    
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
            FILE *fichier = fopen(SUFFIXE_FICHIER_SAUVEGARDE, "a+");
            //demande a l utilisateur d entrer un nom et cree un fichier de sauvegarde et un profil (+erreur deja pris)
            break;
        case 2:
            // charger_sauvegarde();//recupere le nom du fichier de sauvegarde dans le profil et le charge (+erreur si non trouve)
            break;
        case 3:
            menu_admin(profil);
            break;
        
        case 4:
            break;

        default:
            printf("Erreur, commande non trouvee...");
        }
    } while(choix != 4);

    // fclose(fichier);  // Fermer le fichier a la fin du programme

}


void nouvelle_partie(FILE* fic)
{
    return;
}


// JEU
void menu_jeu(SAVE sauvegarde)
{
    int en_jeu = 1;
    while(en_jeu == 1)
    {
        int jour = sauvegarde.jour;
        int actions = 3;
        char input[30];
        printf("Entrez votre commande : ");
        scanf("%s", input);
        
    }
}
