#ifndef sum_h
#define sum_h

typedef struct sNode {
  int data;
  struct sNode *next;
  struct sNode *prev;
} Node;

typedef struct sList{
  Node *init;
  Node *end;
} List;

void initList( List *l );
void printList( List *l );
void insertElement( List *l, int d );
Node *search( List *l, int d );

#endif
