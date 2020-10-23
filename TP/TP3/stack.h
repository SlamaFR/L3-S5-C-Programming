#ifndef STACK_H
#define STACK_H

typedef struct sStack {
    int value;
    struct sStack *next;
} *Stack;

int offer(Stack *stack, int i);

int pop(Stack *stack, int *res);

int size(Stack stack);

void print(Stack stack);

void clear(Stack *stack);

void all(Stack stack);

int reverse(Stack *stack);

#endif /* STACK_H */
