#include "llist.h"

static node_t * list_make_node_t(node_t *list, long value) {
    node_t *node_t = malloc(sizeof(node_t));
    node_t->value = (int)value;
    node_t->next = list;

    list = node_t;

    return list;
}

static void list_free(node_t **list) {
    node_t *p = NULL;
    while (*list) {
        p = *list;
        *list = (*list)->next;
        free(p);
    }
}

int main(int argc, char **argv) {
    size_t count = 20;

    node_t *list = NULL;
    while (count--)
        list = list_make_node_t(list, random() % 1024);

    list_display(list);
    quicksort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}   