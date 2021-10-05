#include "../include/singly_linked_list.c"
#include "../include/stack.c"
#include <stdlib.h>
#include <stdio.h>

struct singly_linked_list list;
struct my_test {
    struct singly_linked_list_elem elem;
    int data;
};

struct stack s;
struct my_stack_entry {
    struct stack_elem elem;
    int data;
};

int main()
{
    stack_init(&s);

    struct my_stack_entry *stack_entry1 = malloc(sizeof(struct my_stack_entry));
    stack_entry1->data = 14;
    stack_push(&s, &stack_entry1->elem);

    struct my_stack_entry *stack_entry2 = malloc(sizeof(struct my_stack_entry));
    stack_entry2->data = 15;
    stack_push(&s, &stack_entry2->elem);
    printf("Stack Peek: %d\n", stack_entry(stack_peek(&s), struct my_stack_entry, elem)->data);
    printf("Stack Pop: %d\n", stack_entry(stack_pop(&s), struct my_stack_entry, elem)->data);
    printf("Stack Peek: %d\n", stack_entry(stack_peek(&s), struct my_stack_entry, elem)->data);
    printf("Stack Pop: %d\n", stack_entry(stack_pop(&s), struct my_stack_entry, elem)->data);
    printf("Stack Pop: %d\n", stack_entry(stack_pop(&s), struct my_stack_entry, elem) == NULL); //check null
    singly_linked_list_init(&list);
    struct my_test *test = malloc(sizeof(struct my_test));
    test->data = 44;
    singly_linked_list_insert_front(&list, &test->elem);
    struct singly_linked_list_elem *testelem = singly_linked_list_remove_front(&list);
    struct my_test *test2 = singly_linked_list_entry(testelem, struct my_test, elem);
    printf("Test1: %d\n", test2->data);
    singly_linked_list_insert_index(&list, &test->elem, 0);
    struct my_test *test3 = malloc(sizeof(struct my_test));
    test3->data = 3;
    singly_linked_list_insert_index(&list, &test3->elem, 1);
    struct singly_linked_list_elem *testelem2 = singly_linked_list_remove_index(&list, 1);
    struct my_test *test4 = singly_linked_list_entry(testelem2, struct my_test, elem);
    printf("Test2: %d\n", test4->data);
    struct singly_linked_list_elem *testelem3 = singly_linked_list_remove_front(&list);
    struct my_test *test5 = singly_linked_list_entry(testelem3, struct my_test, elem);
    printf("Test3: %d\n", test5->data);
    for (int i = 0; i < 10; i++)
    {
        struct my_test *test6 = malloc(sizeof(struct my_test));
        test6->data = i;
        singly_linked_list_insert_front(&list, &test6->elem);
    }

    testelem3 = singly_linked_list_remove_index(&list, 0);
    test5 = singly_linked_list_entry(testelem3, struct my_test, elem);
    printf("Test4: %d\n", test5->data);
}