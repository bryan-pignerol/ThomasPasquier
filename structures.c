#include <stdio.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_ROLE 10


typedef struct
{
    char nom[TAILLE_NOM];
    int permissions; // 0 --> UTILISATEUR | 1 --> ADMIN
} UTILISATEUR;

typedef struct
{
    int pomme;
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
    char nom[TAILLE_NOM];
    char role[TAILLE_ROLE];
    int faim;
    int soif;
} PNJ;
