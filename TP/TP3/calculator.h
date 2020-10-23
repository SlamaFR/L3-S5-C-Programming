#include "stack.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H

#define ERR_EMPTY_STACK -1
#define ERR_NOT_ENOUGH_OPERANDS -2
#define ERR_ZERO_DIVISION -3

int sAdd(Stack *stack);

int sSub(Stack *stack);

int sMul(Stack *stack);

int sDiv(Stack *stack);

int sMod(Stack *stack);

int sFact(Stack *stack);

int sExp(Stack *stack);

#endif /* CALCULATOR_H */
