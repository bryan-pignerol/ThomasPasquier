#include <stdio.h>
#include <string.h>

#define VRAI 1
#define FAUX 0

void salutation(){
    printf("Bonjour xxx, bienvenu dans l aventure, que souhaitez vous faire ?");
}

// Fonction pour analyser la question de l'utilisateur et répondre
void reponse(char *input) {
    // Exemples de réponses basées sur des mots-clés
    if (strstr(input, "bonjour") != NULL || strstr(input, "salut") != NULL) {
        printf("Bonjour ! Comment puis-je vous aider ?\n");
    }
}
int main(int argc, char* argv)
{
    char input[100];
    salutation();

    // Boucle de conversation
    while (1) {
        printf("\nVous : ");
        fgets(input, 100, stdin); // Lecture de l'entrée utilisateur
        input[strcspn(input, "\n")] = 0; // Suppression du saut de ligne final

        // Vérification pour quitter la conversation
        if (strcmp(input, "exit") == 0 || strcmp(input, "au revoir") == 0) {
            printf("Chatbot : Au revoir !\n");
            break;
        }

        // Réponse du chatbot
        printf("Chatbot : ");
        reponse(input);
    }

    return 0;
}