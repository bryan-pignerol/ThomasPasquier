#include <stdio.h>
#include <string.h>
#include "structures.c"
#include "save.c"
#include "administrateur.c"

void initialiser();
UTILISATEUR connexion();
void menu();
void nouvelle_partie(FILE* fic);

int main(int argc, char* argv)
{
    UTILISATEUR utilisateur_courant;
    utilisateur_courant = connexion();
    initialiser();
    menu();
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
    FILE* fic_utilisateur = fopen(FICHIER_UTILISATEURS, "r+");
    char nom[TAILLE_NOM];
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", utilisateur.nom);
    while(fread(&utilisateur, sizeof(UTILISATEUR), 1, fic_utilisateur) != 0)
    {
        if(!strcmp(nom, utilisateur.nom))
        {
            fclose(fic_utilisateur);
            return utilisateur;
        }
    }
}


void menu()
{
        int choix;
        do {
            printf("1. Nouvelle partie\n");
            printf("2. Charger sauvegarde\n");
            printf("3. Menu admin\n");
            printf("4. Quitter\n");
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
                menu_admin();
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
