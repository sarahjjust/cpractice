#include <stdlib.h>
#include <stdio.h>

struct node {
  int val;
  struct node *next;
};

struct node *add(int value, struct node *head)
{
  struct node *toadd = malloc(sizeof(struct node));
  if (toadd == NULL) return NULL;
  toadd->val = value;
  toadd->next = NULL;

  if (head == NULL) {
    head = toadd;
    return head;
  }

  struct node *end = head;
  while (end->next != NULL) {
    end = end->next;
  }
  end->next = toadd;
  return head;
}

struct node *find(int value, struct node *head)
{
  while (head != NULL && head->val != value) head = head->next;
  return head;
}

int main(void)
{
  struct node *list = add(0, NULL);
  for (int i = 1; i <= 5; i++) {
    add(i, list);
  }
  struct node *curr = list;
  while(curr != NULL) {
    printf("%d\n", curr->val);
    curr = curr->next;
  }
  if(find(2, list) == list->next->next)
    printf("Happy Day!\n");
}
