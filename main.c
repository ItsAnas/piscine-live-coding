#include <stdio.h>
#include "list-node.h"



void print_ListNode(struct ListNode *l)
{
    while (l)
    {
	printf("%d->", l->val);
	l = l->next;
    }
    printf("\n");
}

int main(void)
{

  int arr1[] = {4, 3, 2};
//  int arr2[] = {4, 6, 5};

  struct ListNode *l = list_init(arr1, 3);
  print_ListNode(l);
  
  return 0;
}
