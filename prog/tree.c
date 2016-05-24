#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node * left;
  struct node * right;
};
typedef struct node tree;


tree * new_tree(int value)
{
  tree * present = (tree*)malloc(sizeof(tree));
  present->value = value;
  present->left = present->right = NULL;
  return present;
}

tree * insert(int value, tree * current)
{
  if (current == NULL) return new_tree(value);
  if (value <= current->value)
    current->left  = insert(value, current->left);
  else
    current->right = insert(value, current->right);
  return current;
} 

tree * inorder(tree* current)
{
  if (current == NULL) return NULL;
  inorder(current->left);
  printf("%i\n", current->value);
  inorder(current->right);
}

int main(int argc, char ** argv)
{
  int i;
  tree * root = NULL;
  for (i = 0; i < 20; i++)
    root = insert((2 * i) % 7, root);

  inorder(root);
  return 0;
}
