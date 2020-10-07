#pragma once

struct ListNode {
  int val;
  struct ListNode *next;
};


struct ListNode *list_init(int arr[], int size);
