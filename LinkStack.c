#include <malloc.h>
#include <stdio.h>
#include "includes/LinkStack.h"

/**
 * 初始化栈
 * @param top
 */
void InitStack(LinkStack *S)
{
    S->top = NULL;
    S->length = 0;
}

/**
 * 是否为空栈
 * @param S
 * @return
 */
int IsEmpty(LinkStack *S)
{
    if (S->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 入栈
 * @param top
 * @param value
 * @return
 */
int Push(LinkStack *S, STACK_ELEMENT_TYPE value)
{
    LinkStackNode *temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (temp == NULL) {
        // 申请空间失败
        return FALSE;
    }

    temp->data = value;
    temp->next = S->top;
    // 将新元素作为栈顶指针
    S->top = temp;
    // 链栈长度加一
    S->length++;

    return TRUE;
}

/**
 * 出栈
 * @param top
 * @param value
 * @return
 */
int Pop(LinkStack *S, STACK_ELEMENT_TYPE *value)
{
    if (IsEmpty(S) == TRUE) {
        // 空栈
        return FALSE;
    }

    LinkStackNode *temp = S->top;
    if (temp == NULL) {
        // 申请空间失败
        return FALSE;
    }

    // 移动栈顶指针
    S->top = temp->next;
    // 链栈长度减一
    S->length--;
    // 将链栈元素返回
    *value = temp->data;
    // 释放temp空间
    free(temp);

    return TRUE;
}

/**
 * 获取栈顶元素
 * @param S
 * @return
 */
int GetTop(LinkStack *S, STACK_ELEMENT_TYPE *value)
{
    if(IsEmpty(S) == TRUE) {
        return FALSE;
    }

    *value = S->top->data;

    return TRUE;
}

/**
 *
 */
void TestLinkStack()
{
    LinkStack S;
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