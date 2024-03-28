#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Fonction pour initialiser les bornes personnalisées
void BorneToBeWild(int *min, int *max, int *numOfTry) {
    printf("Borne minimum : ");
    scanf("%d", min);
    printf("Borne maximum : ");
    scanf("%d", max);
    printf("Nombre d'essais : ");
    scanf("%d", numOfTry);
}

// Fonction pour saisir un caractère valide parmi une liste de caractères autorisés
char saisirCaractere(char *allowedChars, int taille) {
    char reponse;
    do {
        scanf(" %c", &reponse); // L'espace avant %c permet de consommer les éventuels caractères blancs restants dans le buffer
        int valide = 0;
        for (int i = 0; i < taille; i++) {
            if (reponse == allowedChars[i]) {
                valide = 1;
                break;
            }
        }
        if (!valide) {
            printf("Réponse invalide. Veuillez entrer un caractère valide : ");
        }
    } while (!valide);
    return reponse;
}

int main() {
    char allowedAnswer[] = { 'y', 'Y', 'n', 'N' };
    char answerRetry;
    char answerCustom;
    
    while (1) {
        srand(time(NULL));
        int min = 0;
        int max = 100;
        int numOfTry = 5;
        int randNum = min + rand() % (max + 1 - min);

        while (1) {
            printf("Voulez-vous la version custom ? (y/n) : ");
            answerCustom = saisirCaractere(allowedAnswer, 4);

            if (answerCustom == 'y' || answerCustom == 'Y') {
                BorneToBeWild(&min, &max, &numOfTry);
                randNum = min + rand() % (max + 1 - min);
                break;
            } else if (answerCustom == 'n' || answerCustom == 'N') {
                // Mode normal
                break;
            } else {
                printf("Réponse inconnue.\n");
            }
        }

        for (int i = 0; i < numOfTry; i++) {
            int guessNumber;
            printf("Devinez le nombre aléatoire : ");
            scanf("%d", &guessNumber);

            if (guessNumber == randNum) {
                printf("Bravo ! Vous avez deviné le nombre mystère en %d essais.\n", i + 1);
                break;
            } else if (guessNumber < randNum) {
                printf("C'est plus !\n");
            } else {
                printf("C'est moins !\n");
            }

            printf("Il vous reste %d essais.\n", numOfTry - i - 1);
        }

        printf("Le nombre mystère était : %d\n", randNum);

        printf("Voulez-vous rejouer ? (y/n) : ");
        answerRetry = saisirCaractere(allowedAnswer, 4);

        if (answerRetry == 'n' || answerRetry == 'N') {
            printf("Au revoir !\n");
            break;
        }
    }

    return 0;
}
