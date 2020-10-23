#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int offer(Stack *stack, int i) {
    Stack tmp = malloc(sizeof(struct sStack));

    if (tmp == NULL) return 0;

    tmp->value = i;
    tmp->next = *stack;
    *stack = tmp;
    return 1;
}

int pop(Stack *stack, int *res) {
    Stack next;

    if (*stack == NULL) return 0;

    if (res != NULL) *res = (*stack)->value;
    next = (*stack)->next;
    free(*stack);
    *stack = next;
    return 1;
}

int size(Stack stack) {
    Stack tmp;
    int size = 0;
    for (tmp = stack; tmp; tmp = tmp->next) size++;
    return size;
}

void print(Stack stack) {
    if (stack == NULL) return;
    printf("%d\n", stack->value);
}

void clear(Stack *stack) {
    while (*stack) {
        pop(stack, NULL);
    }
}

void all(Stack stack) {
    Stack tmp;
    if (stack == NULL) return;
    for (tmp = stack; tmp != NULL; tmp = tmp->next) {
        printf("%d ", tmp->value);
    }
    printf("\n");
}

int reverse(Stack *stack) {
    int s = size(*stack);
    Stack tmp;
    if (s < 2) return 0;

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
    return 1;
}
