#include "list-node.h"

struct ListNode *list_init(int arr[], int size)
{
    struct ListNode *first = malloc(sizeof(struct ListNode));
    struct ListNode *sentinelle = first;
    first->val = arr[0];

    for (int i = 1; i < size; i++)
    {
	sentinelle->next = malloc(sizeof(struct ListNode));
	sentinelle = sentinelle->next;

	
    }
}