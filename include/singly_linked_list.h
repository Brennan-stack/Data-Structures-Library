#ifndef __SINGLY_LINKED_LISH_H
#define __SINGLY_LINKED_LIST_H
/*
*   The singly_linked_list.h file is the header file for an implementation
*   of a singly linked list. The implementation takes advantage of a 
*   structure which provides the ability to have a linked list without
*   it being dynamically allocated. The correct usage of this linked
*   list implementation is as follows:
*
*   1. define a singly_linked_list:
*       
*       struct singly_linked_list *list;
*
*   2. initialize the singly linked list:
*       
*       init_singly_linked_list(list);
*   
*   3. create a struct to store the data you want and create a 
*       field for singly_linked_list_elem inside of the struct:
*       
*       struct foo {
*           int bar;
*           struct singly_linked_list_elem elem;
*       }
*
*   4. use the methods provided by this script to modify the entries of 
*       the linked list and use the singly_linked_list_entry macro to get
*       a pointer to list entries.
*
*   If you find yourself confused on how to use any of the functions in this 
*   file, feel free to reference the comments describing what they do. If 
*   that is not sufficient for helping you understand underlying functionality,
*   feel free to reach out to the author of the specific function.  
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
/*
*   This is the struct for the singly linked list element and 
*   contains a reference for the next element in the list. 
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem {
    struct singly_linked_list_elem *next;
};

/*
*   This is the struct for the singly_linked_list and contains a 
*   head element for reference to the head. 
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list {
    struct singly_linked_list_elem head;
};

/*
*   This macro converts the pointer to the singly linked list element 
*   to the pointer for the struct containing the list element. To use 
*   this macro, supply the name of the outer structure STRUCT and the 
*   member name MEMBER of the singly_linked_list element in the struct.
*
*   @author Brennan Hurst
*   @version 10/02/2021 
*/
#define singly_linked_list_entry(SINGLY_LINKED_LIST_ELEM, STRUCT, MEMBER)   \
        ((STRUCT *) ((uint8_t *) &(SINGLY_LINKED_LIST_ELEM)->next          \
                    - offsetof(STRUCT, MEMBER.next)))

/*
*   This function initializes a singly linked list to have no entries.
*
*   @param list - a singly linked list struct you want to initialize.    
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
void singly_linked_list_init(struct singly_linked_list *list);

/*
*   This function inserts a new list element at the front of the linked list.
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @param list_elem - a singly_linked_list_elem* you want to insert into the list
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
void singly_linked_list_insert_front(struct singly_linked_list *list, struct singly_linked_list_elem *list_elem);

/*
*   This function inserts a new list element at a specified index of the linked 
*   list. 
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @param list_elem - a singly_linked_list_elem* you want to insert at the specific
*                       index.
*   @param index - the index you wish to insert the element at. Note: the index 
*                       insertion will push all elements after the index to higher
*                       indexies. 
*
*   @returns integer representing the status of the insertion. 0 if successful, 
*                       -1 if index is out of bounds and insertion failed.
*    
*   @author Brennan Hurst
*   @version 10/02/2021
*/
int singly_linked_list_insert_index(struct singly_linked_list *list, struct singly_linked_list_elem *list_elem, int index);

/*
*   This function returns the next singly linked list element in the list. 
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @param list_elem - a singly_linked_list_elem* which you want the next element of.
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem* singly_linked_list_next(struct singly_linked_list_elem *list_elem);

/*
*   This function removes the first element in the singly_linked_list and returns a pointer 
*   to it. 
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @returns singly_linked_list_elem* if removal is successful, NULL if removal is not successful.
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem* singly_linked_list_remove_front(struct singly_linked_list *list);

/*
*   This funciton removes the element at a specific index in the list and returns it.  
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @returns singly_linked_list_elem* if removal is successful, NULL if removal is not successful.
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem* singly_linked_list_remove_index(struct singly_linked_list *list, int index);
#endif
