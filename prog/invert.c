#include <stdio.h>
#include <stdlib.h>

typedef struct node_el {
  int value;
  struct node_el *left, *right;
} node;

node * createNode(int N) {
  node* tree = (node*)malloc(sizeof(node));
  tree->value = N;
  tree->left = NULL;
  tree->right = NULL;
  visit(tree);
  return tree;
}

node * add(int N, node * tree) {
  if (tree == NULL) return createNode(N);
  if (N < tree->value)
    tree->left = add(N, tree->left);
  else
    tree->right = add(N, tree->right);
  return tree;
}

int postorder(node * tree) {
  if (tree == NULL) return 1;
  postorder(tree->left);
  postorder(tree->right);
  visit(tree);
}

typedef struct element_el {
  int value;
  struct element_el *next;
} element;

element * createElm(int value) {
  element * el = (element*)malloc(sizeof(element));
  el->value = value;
  el->next = NULL;
  return el;
}

element * invertTree(node * tree) {
  element * current = createElm(tree->value);
  if (tree->left == tree->right)
    return current;

  element *ll, *lr;
  if (tree->left != NULL) {
    ll = invertTree(tree->left);
    ll->next = current;
  }
  if (tree->right != NULL) {
    lr = invertTree(tree->right);
    lr->next = current;
  }

  free(tree);
  return current;
}

int visit(node * tree) {
  if (tree == NULL) return printf("\n");
  printf(" :: %i ::\n", tree->value);
}

int main(void) {
  node * tree = NULL;
  int i = 0;
  for (i = 0; i < 10; i++)
    tree = add((i*7+5)%10, tree);

  visit(NULL);
  postorder(tree);
  return invertTree(tree)->value;
}
