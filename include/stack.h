#ifndef __STACK_H
#define __STACK_H
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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
/*
*   This is the struct for the stack element and 
*   contains a reference for the next element in the stack. 
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
struct stack_elem {
    struct stack_elem *next;
};

/*
*   This is the struct for the stack and contains a 
*   top element for reference to the top of the stack. 
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
struct stack {
    struct stack_elem top;
};

/*
*   This macro converts the pointer to the stack element 
*   to the pointer for the struct containing the stack element. To use 
*   this macro, supply the name of the outer structure STRUCT and the 
*   member name MEMBER of the stack element in the struct.
*
*   @author Brennan Hurst
*   @version 10/05/2021 
*/
#define stack_entry(STACK_ELEM, STRUCT, MEMBER)   \
        ((STRUCT *) ((uint8_t *) &(STACK_ELEM)->next          \
                    - offsetof(STRUCT, MEMBER.next)))

/*
*   This function initializes a stack to have no entries.
*
*   @param stack - a stack struct you wish to initialize.    
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
void stack_init(struct stack *stack);

/*
*   This function inserts a new stack element at the top of the stack.
*
*   @param stack - the stack struct you wish to manipulate 
*   @param stack_elem - a stack_elem* you want to insert into the stack.
*
*   @author Brennan Hurst
*   @version 10/05/2021
*/
void stack_push(struct stack *stack, struct stack_elem *stack_elem);

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
struct stack_elem* stack_pop(struct stack *stack);

/*
*   This function returns the top element in the stack without removing it.
*
*   @param stack - the stack struct you wish to manipulate
*   @returns stack_elem* if peek is successful, NULL if peek is not successful
*/
struct stack_elem* stack_peek(struct stack *stack);

#endif
