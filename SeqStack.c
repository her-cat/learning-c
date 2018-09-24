#include <stdio.h>
#include "includes/SeqStack.h"

/**
 * 初始化栈
 * @param S
 */
void InitStack(SeqStack *S)
{
    /* top为-1表示空栈 */
    S->top = -1;
}

/**
 * 是否为空栈
 * @param S
 * @return
 */
int IsEmpty(SeqStack *S)
{
    if (S->top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 是否已满栈
 * @param S
 * @return
 */
int IsFull(SeqStack *S)
{
    if (S->top == STACK_SIZE - 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 入栈
 * @param S
 * @param value
 * @return
 */
int Push(SeqStack *S, STACK_ELEMENT_TYPE value)
{
    if (IsFull(S) == TRUE) {
        // 栈已满
        return FALSE;
    }

    // 修改栈顶指针
    S->top++;
    S->elem[S->top] = value;

    return TRUE;
}

/**
 * 出栈
 * @param S
 * @return
 */
int Pop(SeqStack *S, STACK_ELEMENT_TYPE *value)
{
    if(IsEmpty(S) == TRUE) {
        // 栈为空
        return FALSE;
    }

    *value = S->elem[S->top];
    // 修改栈顶指针
    S->top--;

    return TRUE;
}

/**
 * 获取栈顶元素
 * @param S
 * @return
 */
int GetTop(SeqStack *S, STACK_ELEMENT_TYPE *value)
{
    if(IsEmpty(S) == TRUE) {
        return FALSE;
    }

    *value = S->elem[S->top];

    return TRUE;
}

/**
 * 测试顺序栈
 */
void TestSeqStack()
{
    SeqStack S;
    InitStack(&S);
    printf("Push:%d \n", Push(&S, 1));
    printf("Push:%d \n", Push(&S, 2));
    printf("Push:%d \n", Push(&S, 3));
    STACK_ELEMENT_TYPE value;
    GetTop(&S, &value);
    printf("Top:%d \n", value);
    while (Pop(&S, &value) == TRUE) {
        printf("Pop:%d \n", value);
    }
}