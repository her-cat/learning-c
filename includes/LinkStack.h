#include "Common.h"
#define STACK_ELEMENT_TYPE int

typedef struct node {
    STACK_ELEMENT_TYPE data;
    struct node *next;
} LinkStackNode;

typedef struct {
    LinkStackNode *top;
    int length;
} LinkStack;

void InitStack(LinkStack *S);
int IsEmpty(LinkStack *S);
int Push(LinkStack *S, STACK_ELEMENT_TYPE value);
int Pop(LinkStack *S, STACK_ELEMENT_TYPE *value);
void TestLinkStack();