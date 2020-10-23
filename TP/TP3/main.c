#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "stack.h"
#include "calculator.h"

void execute(Stack *stack, char *cmd) {
    char *feedback = NULL;
    int cmdFeedback = 1;
    int value = (int) strtol(cmd, &feedback, 10);

    if (feedback != cmd) {
        offer(stack, value);
    } else {
        if (!strcmp(cmd, "+"))
            cmdFeedback = sAdd(stack);
        else if (!strcmp(cmd, "-"))
            cmdFeedback = sSub(stack);
        else if (!strcmp(cmd, "*"))
            cmdFeedback = sMul(stack);
        else if (!strcmp(cmd, "/"))
            cmdFeedback = sDiv(stack);
        else if (!strcmp(cmd, "%"))
            cmdFeedback = sMod(stack);
        else if (!strcmp(cmd, "!"))
            cmdFeedback = sFact(stack);
        else if (!strcmp(cmd, "^"))
            cmdFeedback = sExp(stack);
        else if (!strcmp(cmd, "p"))
            print(*stack);
        else if (!strcmp(cmd, "c"))
            clear(stack);
        else if (!strcmp(cmd, "a"))
            all(*stack);
        else if (!strcmp(cmd, "r"))
            reverse(stack);
        else if (!strcmp(cmd, "?")) {
            printf("<nombre> : empiler un entier\n");
            printf("q : quitter le programme\n");
            printf("p : afficher la valeur en tête de pile\n");
            printf("c : vider la pile\n");
            printf("a : afficher toute la pile\n");
            printf("r : inverser les deux dernières valeurs\n");
            printf("? : afficher l'aide\n");
        } else if (strcmp(cmd, "q") != 0)
            printf("Erreur : instruction non reconnue !\n");
    }

    switch (cmdFeedback) {
        case ERR_ZERO_DIVISION:
            printf("Erreur : division par 0 impossible !\n");
            break;
        case ERR_EMPTY_STACK:
            printf("Erreur: la pile est vide !\n");
            break;
        case ERR_NOT_ENOUGH_OPERANDS:
            printf("Erreur: nombre insuffisant d'opérandes !\n");
            break;
        case 0:
            printf("Erreur: erreur d'allocation !\n");
            break;
        default:
            break;
    }
}

int main(void) {
    Stack stack = NULL;
    char *cmd, *token, *rest;

    do {
        rest = cmd = readline("> ");
        while ((token = strtok_r(rest, " ", &rest))) {
            add_history(token);
            execute(&stack, token);
        }
        free(rest);
    } while (strcmp(cmd, "q") != 0);
    free(token);
    free(cmd);
    clear(&stack);

    all(stack);

    clear_history();
    return 0;
}
