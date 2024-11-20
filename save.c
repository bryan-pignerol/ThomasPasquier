#include <stdio.h>
#include <string.h>

#define PREFIXE_FICHIER_SAUVEGARDE "saves/"
#define SUFFIXE_FICHIER_SAUVEGARDE "_save.dat"

typedef struct { //Bouger dans structures.c quand j'aurai fini
    JOUEUR joueur;
    PNJ *pnj; //Ca marche comment cette ligne ?
    ARTICLE article[5]; //Et ça ?
    int jour;
    //Rajouter le suivi du lieu (plus tard)
    //Bonne recette/mauvaise recette trouvée
} SAVE;


// FORMAT SAUVEGARDE : saves/{nom_du_joueur}_save.dat

SAVE nouvelle_sauvegarde(UTILISATEUR profil);
SAVE charger_sauvegarde(FILE* save);
SAVE sauvegarder(FILE* save);

SAVE nouvelle_sauvegarde(UTILISATEUR profil) //profil = utilisateur_courant
{
    FILE* new_save;
    SAVE fichier_sauvegarde;
    printf("Entrez un nom pour le personnage (défaut : Thomas Pasquier)");
    scanf(%s, fichier_sauvegarde.joueur);
    // profil.nom
    for(int i = 0; i < TAILLE_FICHIER_SAUVEGARDE; i++)
    {
        profil.sauvegarde[i] = "";
    }
    
    strcat(profil.sauvegarde, PREFIXE_FICHIER_SAUVEGARDE);
    strcat(profil.sauvegarde, profil.nom);
    strcat(profil.sauvegarde, SUFFIXE_FICHIER_SAUVEGARDE);
    printf("%s\n", profil.sauvegarde);
    new_save = fopen(profil.sauvegarde, "w");
    fclose(new_save);
}

/*typedef struct
{
    int levure; // MAX = 50
    int farine; // MAX = 500
    int eau; // MAX : 10
    int nourriture; // MAX : 10
    int ingredient_special; // MAX 1
} INVENTAIRE;

typedef struct
{
    char nom[TAILLE_NOM];
    int faim;
    int soif;
    INVENTAIRE inventaire;
} JOUEUR;*/