#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_ROLE 30
#define TAILLE_FICHIER_SAUVEGARDE 36

#define TAILLE_CONTENU_ARTICLE 500


typedef struct
{
    char nom[TAILLE_NOM];
    int permissions; // 0 --> UTILISATEUR | 1 --> ADMIN
    char sauvegarde[TAILLE_FICHIER_SAUVEGARDE]; //Faudrait faire un PREFIXE_FICHIER_SAUVEGARDE mais je trouve plus où est rangé le suffixe
} UTILISATEUR;

typedef struct
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
} JOUEUR;

typedef struct
{
    char prenom[TAILLE_NOM];
    char nom[TAILLE_NOM];
    char role[TAILLE_ROLE];
    int faim;
    int soif;
} PNJ;

typedef struct
{
    char nom[TAILLE_NOM];
    char contenu[TAILLE_CONTENU_ARTICLE];
    int jour;
} ARTICLE;
