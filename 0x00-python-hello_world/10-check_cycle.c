#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks if a singly-linked list contains a cycle.
 * @list: A singly-linked list.
 *
 * Return: If there is no cycle - 0.
 *         If there is a cycle - 1.
 */
int check_cycle(listint_t *list) {
    listint_t *hansel, *gretel;

    if (list == NULL || list->next == NULL) {
        return (0); // empty list, no cycle
    }
    
    gretel = list;
    hansel = list;

    while (hansel != NULL && hansel->next != NULL) {
        gretel = gretel->next; // 1 step
        hansel = hansel->next->next; // 2 steps

        if (gretel == hansel) {
            return (1); // If 'gretel' and 'hansel' meet, a cycle is detected
        }
    }

    return (0); // no cycle
}
