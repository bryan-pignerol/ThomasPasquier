#include <stdio.h>
#include <string.h>


void lire_actualites(SAVE sauvegarde); 
void livre_miserables();
void livre_cuisine();
void jounral_intime();


/*
Recette levure chimique : 
- 50g farine
- 50ml eau tiede
- 1 cuillère à café de sucre
- laisser reposer 24h à 25°C
*/

/// ORDINATEUR CENTRAL
void lire_actualites(SAVE sauvegarde)
{
    for(int i; i < 10; i++)
    {
        if(sauvegarde.jour == sauvegarde.article[i].jour)
        {
            printf("%s\n", sauvegarde.article[i].nom);
            printf("%s\n\n", sauvegarde.article[i].contenu);
            return;
        }
    }
    printf("Aucun article publié aujourd'hui...\n\n");
}


/// PLACARD ETRANGE
// LIVRES
void livre_miserables()
{
    printf("CHAPITRE 1\n\n");
    printf("Jean Valjean, enfin libre, sent le soleil de Marseille chauffer ses joues pour la première fois en dix-neuf ans. Dix-neuf ans ! Tout ça pour avoir piqué un bout de pain. Le type, il a des épaules larges comme la Méditerranée, mais y a une amertume dans ses yeux, comme quelqu'un qui a trop vu la noirceur du monde.\n");
    printf("Quand il sort, il cligne des yeux comme un hibou. Les pierres du Vieux-Port l’aveuglent presque, ça fait des années qu’il a pas vu la mer.\n");
    printf("« Alors c’est ça, la liberté, hein ? », qu’il se murmure.\n");
    printf("Il a un vieux baluchon sous le bras, avec deux trois babioles ramassées au fil des années au bagne. Le long de la Canebière, il passe comme un fantôme, regardé de travers par les commerçants. Dans son regard, y a la fatigue et la colère.\n");
    printf("Il cherche un endroit où passer la nuit, mais chaque porte qu’il toque se referme aussitôt. Des gens lui lancent des regards pleins de jugement.\n");
    printf("« T’as vu celui-là ? Avec sa tronche de taulard, on dirait qu’il sort direct des Baumettes ! » qu’il entend chuchoter.\n");
    printf("Les mots lui piquent la peau comme des épines. Finalement, épuisé et affamé, il erre jusqu’au quartier du Panier. Et là, il tombe sur une église, où un vieux prêtre au sourire large comme le Vieux-Port, Monseigneur Myriel, le remarque.\n");
    printf("« Oh, toi là ! Viens, viens pas rester dehors comme un chien. Ce soir, c’est toi mon invité », dit l’abbé en lui tapant sur l’épaule.\n");
    printf("Jean, il sait pas s’il doit se méfier ou pas, mais il a tellement faim qu’il suit le vieux sans broncher. À table, l’abbé sort le pastis et du pain frais. Les mains de Jean tremblent en coupant son morceau. Il avait presque oublié le goût du bon pain.\n\n");

    printf("Vous vous rendez compte que le livre est plus que médiocre et ne continuez pas votre lecture.\n\n");
}

void livre_cuisine()
{
    printf("Recette loukoums de Narnia");
    printf("Loukoums magiques :\nIngrédients\nFécule de maïs (maïzena) : 100 g\nEau : 350 ml\nJus de citron : 1 c. à soupe\nEau de rose (ou autre arôme comme fleur d’oranger, citron, ou vanille) : 1 c. à soupe\nColorant alimentaire (optionnel) : une goutte (rose ou rouge pour l'eau de rose)\nSucre glace : 50 g\nFécule de maïs supplémentaire : 50 g");
    printf("ps : Vous pouvez ajouter de la levure chimique industrielle ou fabriquer la votre :\nRecette levure chimique (ajuster les quantités au besoin) :\n- farine 100g \n- eau tiede 100ml\n- laisser reposer 24h-48h à 25°C\n\n");
}

void journal_intime()
{
    printf("20 novembre 2024\nCher journal,\nAujourd'hui, comme chaque matin, l'odeur du pain chaud s'est infiltrée dans ma chambre avant même que le soleil ne se lève. C’est Mamie qui fait son pain aux graines de tournesol, avec son ingrédient sucré. Rien de tel pour commencer la journée. Elle dit toujours que la boulangerie, c’est « l’art de nourrir le cœur et l’âme ». Si seulement je pouvais croire que j’ai ça en moi...\n");
}