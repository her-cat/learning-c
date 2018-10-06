#include <stdio.h>
#include <malloc.h>
#include "includes/LinkQueue.h"

/**
 * 初始化链式队列
 * @param Q
 */
void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

/**
 * 队列是否为空
 * @param Q
 * @return
 */
int IsEmpty(LinkQueue *Q)
{
    if (Q->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 入队
 * @param Q
 * @param value
 * @return
 */
int EnQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE value)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL) {
        return FALSE;
    }

    node->data = value;
    node->next = NULL;

    if (Q->rear != NULL) {
        Q->rear->next = node;
    }
    Q->rear = node;

    if (Q->front == NULL) {
        Q->front = node;
    }

    Q->length++;

    return TRUE;
}

/**
 * 出队
 * @param Q
 * @param value
 * @return
 */
int DeQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE *value)
{
    if (IsEmpty(Q) == TRUE) {
        return FALSE;
    }

    *value = Q->front->data;
    Q->front = Q->front->next;
    Q->length--;

    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    return TRUE;
}

/**
 * 获取队头元素
 * @param Q
 * @param value
 * @return
 */
int GetFront(LinkQueue *Q, QUEUE_ELEMENT_TYPE *value)
{
    if (IsEmpty(Q) == TRUE) {
        return FALSE;
    }

    *value = Q->front->data;

    return TRUE;
}

/**
 * 测试链式队列
 */
void TestLinkQueue() {
    LinkQueue Q;
    QUEUE_ELEMENT_TYPE value;

    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);

    GetFront(&Q, &value);
    printf("QueueFront:%d \n", value);
    printf("QueueLength:%d \n", Q.length);

    printf("DeQueue: \n");
    while (DeQueue(&Q, &value) == TRUE) {
        printf("data:%d length:%d\n", value, Q.length);
    }
}