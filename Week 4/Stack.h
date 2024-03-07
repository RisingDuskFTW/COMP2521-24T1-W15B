// Interface for a Stack ADT

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack *Stack;

// Creates a new empty stack
Stack StackNew(void);

// Frees memory allocated to the stack
void StackFree(Stack s);

// Pushes an item onto the stack
void StackPush(Stack s, int item);

// Pops an item from the stack and returns it
// Assumes that the stack is not empty
int StackPop(Stack s);

// Returns the item on top of the stack, without removing it
int StackTop(Stack s);

// Returns the number of items on the stack
int StackSize(Stack s);

// Returns if the stack is empty
bool StackIsEmpty(Stack s);

#endif
