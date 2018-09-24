#include "Common.h"
#define STACK_SIZE 50
#define STACK_ELEMENT_TYPE int

/* 顺序栈结构体类型 */
typedef struct
{
    /* 用于存放栈中元素的一维数组 */
    STACK_ELEMENT_TYPE elem[STACK_SIZE];

    /* 用来存放栈顶元素的下标 */
    int top;
} SeqStack;

void InitStack(SeqStack *S);
int IsEmpty(SeqStack *S);
int IsFull(SeqStack *S);
int Push(SeqStack *S, STACK_ELEMENT_TYPE value);
int Pop(SeqStack *S, STACK_ELEMENT_TYPE *value);
int GetTop(SeqStack *S, STACK_ELEMENT_TYPE *value);
void TestSeqStack();