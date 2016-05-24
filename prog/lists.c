#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list
{
  int value;
  struct list * next;
};
typedef struct list node;

node * new_node(int value)
{
  node * present = (node*)malloc(sizeof(node));
  present->value = value;
  present->next  = NULL;
  return present;
}

node * insert(int value, node * tail)
{
  node * new = new_node(value);
  new->next  = tail;
  return new;
}

node * reverse(node * head)
{
  if (head == NULL) return head;
  if (head->next == NULL) return head;

  return reverse(head->next)->next = head;
}

int main(int argc, char ** argv)
{
  int i;
  node * head = NULL;
  for (i = 0; i < 10; i++)
    head = insert(i, head);

  node * curr = head;
  do {
    printf("%i\n", curr->value);
    if (curr->next == NULL) break;
    curr = curr->next;
  } while (true);

  reverse(head)->next = NULL;
  head = curr;

  for (curr = head; curr != NULL; curr = curr->next)
    printf("%i\n", curr->value);
  return 0;
}

