#include <stdlib.h>
#include <math.h>
#include "calculator.h"
#include "stack.h"

int fact(int x) {
    if (x == 1) return x;
    return x * fact(x - 1);
}

int sAdd(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    return offer(stack, a + b);
}

int sSub(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    return offer(stack, a - b);
}

int sMul(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    return offer(stack, a * b);
}

int sDiv(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    if (b == 0) {
        offer(stack, a);
        offer(stack, b);
        return ERR_ZERO_DIVISION;
    }

    return offer(stack, a / b);
}

int sMod(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    return offer(stack, a % b);
}

int sFact(Stack *stack) {
    int x;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 1) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &x);
    return offer(stack, fact(x));
}

int sExp(Stack *stack) {
    int a, b;
    if (stack == NULL || *stack == NULL) return ERR_EMPTY_STACK;
    if (size(*stack) < 2) return ERR_NOT_ENOUGH_OPERANDS;

    pop(stack, &b);
    pop(stack, &a);
    return offer(stack, (int) pow(a, b));
}
