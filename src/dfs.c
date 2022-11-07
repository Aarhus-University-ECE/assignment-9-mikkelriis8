/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"

void DFT (node * root) {
  struct stack *runtimeStack = malloc(sizeof(stack)); // implementing runtime stack
  runtimeStack->node = root; // assigning the first element of the stack to the tree's root

  printf("The output is: ");
  while(isEmpty(runtimeStack) == false) { // looping through tree until every node has been visited
    struct node *tempNode = top(runtimeStack); // creating temporary node and assigning top node
    runtimeStack = pop(runtimeStack); // removing top element from the stack
    printf("%d", tempNode->num); // printing visited node
    if(tempNode->rchild) { // checking if node has a right child
      runtimeStack = push(runtimeStack, tempNode->rchild); // pushing right child to stack
    }
    if(tempNode->lchild) { // checking if node has a left child
      runtimeStack = push(runtimeStack, tempNode->lchild); // pushing left child to stack
    }
    if(isEmpty(runtimeStack) == false) { // printing out ", " if stack is not empty
      printf(", ");
    }
  }
}

node *make_node (int num, node * left, node * right) {
	struct node *newNode;
  newNode = (node*) malloc(sizeof(node));
  newNode->num = num;
  newNode->lchild = left;
  newNode->rchild = right;
  return newNode;
}

void free_node (node * p) {
  free(p);
}

void print_node (node * p) {
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}

void print_tree (node * p, int depth) {
  for (int i = 0; i < depth; i = i + 1) {
    printf (" ");
  }
  printf ("| ");

  if (p == NULL) {
    printf ("NULL\n");
  } else {
    printf ("[%d]\n", p->num);
  }

  if (p->lchild) {
    print_tree (p->lchild, depth + 1);
  }

  if (p->rchild) {
    print_tree (p->rchild, depth + 1);
  }
}

stack *push (stack *topp, node *pushNode) {
  stack *temp = malloc(sizeof(stack));
  temp->node = pushNode;
  temp->next = topp;
  topp = temp;
  return topp;
}

bool isEmpty (stack * topp) {
  if(topp == NULL) {
    return true;
  } else {
    return false;
  }
}

node *top (stack * topp) {
  struct node *top = (node*) malloc(sizeof(node));
	top = topp->node;
  return top;
}

stack *pop (stack * topp) {
	if(topp->node == NULL) {
    printf("Stack is EMPTY - nothing left to pop");
  } else {
    topp = topp->next;
  }
  return topp;
}

void print_stack (stack * topp) {
  struct stack *temp = topp;

  while (temp != NULL) {
    print_node (temp->node);
    printf ("\n");
    temp = temp->next;
  }

  printf ("====\n");

  return;
}
