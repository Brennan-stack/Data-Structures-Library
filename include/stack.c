#include "stack.h"
/*
*   The stack.h header file is the header file for an implementation of a
*   stack. The stack data structure operates as a LIFO data structure 
*   and is useful in a variety of settings. To use this implementation of 
*   a stack, follow the following instructions:
*
*   1. define a stack:
*       
*       struct stack *s;
*
*   2. initialize the stack:
*       
*       init_stack(s);
*   
*   3. create a struct to store the data you want and create a 
*       field for stack_elem inside of the struct:
*       
*       struct foo {
*           int bar;
*           struct stack_elem elem;
*       }
*
*   4. use the methods provided by this script to modify the stack.
*
*   If you find yourself confused on how to use any of the functions in this 
*   file, feel free to reference the comments describing what they do. If 
*   that is not sufficient for helping you understand underlying functionality,
*   please reach out to the author of the specific function.  
*/


/*
*   This function initializes a stack to have no entries.
*
*   @param _stack - a stack struct you wish to initialize.    
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
void stack_init(struct stack *stack) {
    assert (stack != NULL);
    stack->top.next = NULL;
}
/*
*   This function inserts a new stack element at the top of the stack.
*
*   @param stack - the stack struct you wish to manipulate 
*   @param stack_elem - a stack_elem* you want to insert into the stack.
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
void stack_push(struct stack *stack, struct stack_elem *stack_elem) {
    stack_elem->next = stack->top.next;
    stack->top.next = stack_elem;
}

/*
*   This function removes the top element in the stack and returns a pointer
*   to that element.
*
*   @param stack - the stack struct you wish to manipulate 
*   @returns stack_elem* if removal is successful, NULL if removal is not 
*   successful.
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
struct stack_elem* stack_pop(struct stack *stack) {
    struct stack_elem* ret = (stack->top.next);
    if (ret == NULL)
    {
        return NULL;
    }
    stack->top.next = (ret->next);
    return ret;
}

/*
*   This function returns the top element in the stack without removing it.
*
*   @param stack - the stack struct you wish to manipulate
*   @returns stack_elem* if peek is successful, NULL if peek is not successful
*/
struct stack_elem* stack_peek(struct stack *stack) {
    struct stack_elem* ret = (stack->top.next);
    if (ret == NULL)
    {
        return NULL;
    }
    return ret;
}
