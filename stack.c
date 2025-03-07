#include <stdlib.h>
#include <stdio.h>

struct node {
  int val;
  struct node *next;
};

struct node *push(int value, struct node **head)
{
  struct node *toadd = malloc(sizeof(struct node));
  if (toadd == NULL) return NULL;
  toadd->val = value;
  toadd->next = *head;
  *head = toadd;
  return *head;
}

struct node *init(void)
{
  struct node *head = NULL;
  struct node *eos = push(-1, &head);
  return eos;
}

int pop(struct node **head)
{
  if (*head == NULL || (*head)->next == NULL) return -1;

  int result = (*head)->val;
  struct node *next = (*head)->next;
  free(*head);
  *head = next;
  return result;
}

int peek(int index, struct node *head)
{
  if (head == NULL || head->next == NULL || index < 0) return -1;
  for (int i = 0; i < index && head != NULL; i++) {
    head = head->next;
  }
  if (head == NULL) return -1;
  return head->val;
}
