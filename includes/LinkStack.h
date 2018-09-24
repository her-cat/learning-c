#include "Common.h"
#define STACK_ELEMENT_TYPE int

/* 链栈节点 */
typedef struct node {
    STACK_ELEMENT_TYPE data;
    struct node *next;
} LinkStackNode;

/* 链栈结构 */
typedef struct {
    LinkStackNode *top;
    int length;
} LinkStack;

void InitStack(LinkStack *S);
int IsEmpty(LinkStack *S);
int Push(LinkStack *S, STACK_ELEMENT_TYPE value);
int Pop(LinkStack *S, STACK_ELEMENT_TYPE *value);
int GetTop(LinkStack *S, STACK_ELEMENT_TYPE *value);
void TestLinkStack();