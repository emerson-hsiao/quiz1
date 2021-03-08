#include "llist.h"

bool list_is_ordered(node_t *list) {
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

void list_display(node_t *list) {
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

/*
 * purpose : insert a node at front of a list 
 * note :
 *  1. node_t and list should not be NULL
 *  2. *list could be NULL
*/
static inline void list_add_node_t(node_t **list, node_t *node_t) {
    node_t->next = *list;
    *list = node_t;
}

/*
 * purpose : append a node/list at tail of a list 
 * note :
 *  1. left chould be NULL
*/
static inline void list_concat(node_t **left, node_t *right) {
    while (*left)
        left = &((*left)->next); 

    *left = right;
    left = NULL;
}

/*
 * how :
 *  1. choose a pivot
 *  2. divide the rest of list by comparing values with the pivots'
*/
void quicksort(node_t **list)
{
    if (!*list)
        return;

    node_t *pivot = *list; // the first mode
    int value = pivot->value; 
    node_t *p = pivot->next; // save pivot's next ==> new first node
    pivot->next = NULL; // set pivot's next as NULL ==> a pivot and a list with new head 

    node_t *left = NULL, *right = NULL;
    while (p) {
        node_t *n = p;
        p = p->next;
        list_add_node_t(n->value > value ? &right : &left, n);
    }

    quicksort(&left);
    quicksort(&right);

    node_t *result = NULL;
    list_concat(&result, left);
    list_concat(&result, pivot);
    list_concat(&result, right);
    
    *list = result;
}
