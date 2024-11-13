#include <stdio.h>
#include <string.h>

#define SUFFIXE_FICHIER_SAUVEGARDE "_save.dat"

typedef struct {
    JOUEUR joueur;
    PNJ *pnj;
    ARTICLE *article;
} SAVE;

SAVE nouvelle_sauvegarde();
SAVE charger_sauvegarde(FILE* save);
SAVE sauvegarder(FILE* save);

