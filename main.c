#include <stdio.h>
#include <string.h>
#include "administrateur.c"
#include "structures.c"

#define FICHIER_SAUVEGARDE "save.dat"

void initialiser();
void menu(FILE* fic);
void nouvelle_partie(FILE* fic);

int main(int argc, char* argv)
{
    initialiser();
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


void menu(FILE* fic)
{
        int choix;
        while (choix != '3') {

            printf("1. Nouvelle partie");
            printf("2. Charger");
            printf("3. Quitter");
            scanf("%d", &choix);

            switch (choix) {
            case 1:
                FILE *fichier = fopen(FICHIER_SAUVEGARDE, "a+");
                //demande a l utilisateur d entrer un nom et cree un fichier de sauvegarde et un profil (+erreur deja pris)
                break;
            case 2:
                //recupere le nom du fichier de sauvegarde dans le profil et le charge (+erreur si non trouve)
                break;
            case 3:
                //Termine le programme
                break;

            default:
                printf("Erreur, commande non trouvee...");
            }
        }

    // fclose(fichier);  // Fermer le fichier a la fin du programme

}

