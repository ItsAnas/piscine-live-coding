#include <stdlib.h>
#include "list-node.h"

struct ListNode *list_init(int arr[], int size)
{
    struct ListNode *res = malloc(sizeof(struct ListNode));
    res->val = arr[0];

    for (int i = 1; i < size; i++)
    {
	struct ListNode *new_node = malloc(sizeof(struct ListNode));
	new_node->val = arr[i];
	new_node->next = res;
	res = new_node;
    }

    return res;
}
