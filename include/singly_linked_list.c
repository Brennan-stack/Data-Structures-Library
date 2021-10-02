#include "singly_linked_list.h"
/*
*   This function initializes a singly linked list to have no entries.
*
*   @param list - a singly linked list struct you want to initialize.    
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
void singly_linked_list_init(struct singly_linked_list *list) {
    assert (list != NULL);
    list->head.next = NULL;
}

/*
*   This function inserts a new list element at the front of the linked list.
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @param list_elem - a singly_linked_list_elem* you want to insert into the list
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
void singly_linked_list_insert_front(struct singly_linked_list *list, struct singly_linked_list_elem *list_elem) {
    list_elem->next = list->head.next;
    list->head.next = list_elem;
}

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
int singly_linked_list_insert_index(struct singly_linked_list *list, struct singly_linked_list_elem *list_elem, int index) {
    
    assert (list != NULL);
    assert (list_elem != NULL);
    
    int count = 0;
    struct singly_linked_list_elem *current_node = &(list->head);
    while (count != index && current_node != NULL)
    {
        
        count++;
        current_node = current_node->next;
    }
    if (count != index)
    {
        return -1;
    }
    list_elem->next = current_node->next;
    current_node->next = list_elem;
    
    return 0;
}

/*
*   This function returns the next singly linked list element in the list. 
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @param list_elem - a singly_linked_list_elem* which you want the next element of.
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem* singly_linked_list_next(struct singly_linked_list_elem *list_elem)
{
    assert (list_elem != NULL);
    return list_elem->next;
}
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
struct singly_linked_list_elem* singly_linked_list_remove_front(struct singly_linked_list *list)
{
    struct singly_linked_list_elem* ret = (list->head.next);
    if (ret == NULL)
    {
        return NULL;
    }
    list->head.next = (ret->next);
    return ret;
}

/*
*   This funciton removes the element at a specific index in the list and returns it.  
*
*   @param list - the singly_linked_list you wish to manipulate 
*   @returns singly_linked_list_elem* if removal is successful, NULL if removal is not successful.
*
*   @author Brennan Hurst
*   @version 10/02/2021
*/
struct singly_linked_list_elem* singly_linked_list_remove_index(struct singly_linked_list *list, int index)
{
    assert (list != NULL);
    assert (index >= 0);
    struct singly_linked_list_elem* ret = &(list->head);
    struct singly_linked_list_elem* prev = NULL;
    int count = 0;
    while (count != (index + 1) && ret != NULL)
    {
        count++;
        ret = ret->next;
        if (count == index)
        {
            prev = ret;
        }
    }
    if (count != index + 1)
    {
        return NULL;
    }
    if (prev == NULL)
    {
        list->head.next = list->head.next->next;
        return ret;
    }
    prev->next = ret->next;
    return ret;
}