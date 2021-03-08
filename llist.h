
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct __node {                   
    int value;
    struct __node *next;
} node_t;

bool list_is_ordered(node_t *list);
void list_display(node_t *list);
void quicksort(node_t **list);
