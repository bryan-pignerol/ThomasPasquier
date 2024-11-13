#include <stdio.h>
#include <string.h>

#define VRAI 1
#define FAUX 0

void salutation(){
    printf("Bonjour xxx, bienvenu dans l aventure, que souhaitez vous faire ?");
}

// Fonction pour analyser la question de l'utilisateur et répondre
void reponse(char *choix) {

        if (strstr(choix, "bonjour") != NULL || strstr(choix, "salut") != NULL) {
            printf("Bonjour ! Comment puis-je vous aider ?\n");
        }
        else if (strstr(choix, "comment ca va") != NULL) {
            printf("Je vais bien, merci ! Et vous ?\n");
        }        else if (strstr(choix, "ton nom") != NULL) {
            printf("Je suis un chatbot sans nom, mais je suis là pour vous aider.\n");
        }        else if (strstr(choix, "heure") != NULL) {
            printf("Désolé, je ne peux pas donner l'heure exacte.\n");
        }
        else if (strstr(choix, "au revoir") != NULL) {
            printf("Au revoir ! Passez une bonne journée.\n");
        }
        else {
            printf("Je ne comprends pas votre question. Pouvez-vous reformuler ?\n");
        }

}

int main()
{
    char choix[100];
    salutation();

    // Boucle de conversation
    while (strcmp(choix, "quit") !=0) {
        printf("\nVous : ");

        fgets(choix, 100, stdin); // Lecture de l'entrée utilisateur
        choix[strcspn(choix, "\n")] = 0; // Suppression du saut de ligne final
        // Vérification pour quitter la conversation
        if (strcmp(choix, "exit") == 0 || strcmp(choix, "au revoir") == 0) {
            printf("Chatbot : Au revoir !\n");
            break;
        }
        // Réponse du chatbot
        printf("Chatbot : ");
        reponse(choix);
    }
    return 0;
}