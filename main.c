#include <stdio.h>
#include "list-node.h"
#include <stdlib.h>

int add_node(struct ListNode* l1, struct ListNode* l2)
{
    int l1_value = 0;
    if (l1)
	l1_value = l1->val;
    
    int l2_value = 0;
    if (l2)
	l2_value = l2->val;
        
    int add_result = l1_value + l2_value;

    return add_result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = malloc(sizeof(struct ListNode));
    if (!result)
	return NULL;
    struct ListNode *sentinelle = result;

    result->val = 0; // In case both are null
    int carry = 0;
    
    if (l1 || l2)
    {
        int add_result = add_node(l1, l2);        
        sentinelle->val = (add_result + carry) % 10;
	carry = (add_result + carry) > 9; 

	if (l1)
	    l1 = l1->next;
	if (l2)
	    l2 = l2->next;        
    }
          
    while (l1 || l2 || carry)
    {
        sentinelle->next = malloc(sizeof(struct ListNode));
	if (!sentinelle->next)
	    return NULL; // Should call something like list_destroy(), but you have it in your exercices, so I can't give it to you
        sentinelle = sentinelle->next;
        
        int add_result = add_node(l1, l2);
        sentinelle->val = (add_result + carry) % 10;
        
	carry = (add_result + carry) > 9; 
	
	if (l1)
	    l1 = l1->next;
	if (l2)
	    l2 = l2->next;        
    }
    
    return result;
}

void print_ListNode_rec(struct ListNode *l)
{
    if (!l)
	return;
    print_ListNode_rec(l->next);
    printf("%d->", l->val);
}

void print_ListNode(struct ListNode *l)
{
    if (!l)
	return;
    print_ListNode_rec(l->next);
    printf("%d\n", l->val);
}

int main(void)
{
    int arr1[] = {4,5,2,2,9,3,8,9,2};
    int arr2[] = {0,7,6,1,6,5,0,6,7};

    struct ListNode *l1 = list_init(arr1, 9);
    struct ListNode *l2 = list_init(arr2, 9);
    struct ListNode *result = addTwoNumbers(l1, l2);
  
    print_ListNode(l1);
    print_ListNode(l2);
    print_ListNode(result);
  
    return 0;
}
