#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

void initList( List *l ) {
  l->init = NULL;
  l->end = NULL;
}

void printList( List *l ) {
  Node *p;
  printf("[");
  for (p = l->init; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("]\n");
}

void insertElement( List *l, int d ) {
  Node *p;
  p = (Node *) malloc(sizeof(Node));
  p->prev = NULL;
  p->data = d;
  p->next = l->init;
  if (l->init != NULL) {
    l->init->prev = p;
  } else {
    l->end = p;
  }
  l->init = p;
}

Node *search( List *l, int d ) {
  Node *p;
  for (p = l->init; p != NULL; p = p->next) {
    if (p->data == d) {
      return p;
    }
  }
  return NULL;
}

int main( int argc, const char *argv[] ) {
  List *resultList;
  Node *p;
  int sumElements;
  int i, length = 5;

  resultList = (List *) malloc(sizeof(List));
  initList(resultList);

  insertElement(resultList, 1);
  insertElement(resultList, 2);
  insertElement(resultList, 3);
  insertElement(resultList, 4);
  insertElement(resultList, 5);
  printList(resultList);

  sumElements = 0;
  for (p = resultList->init; p != NULL; p = p->next){
    sumElements = sumElements + p->data;
  }

  printf("\nSoma: %d\n", sumElements);
  return 0;
}
