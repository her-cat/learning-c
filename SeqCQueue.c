#include <stdio.h>
#include "includes/SeqCQueue.h"

/**
 * 初始化队列
 * @param Q
 */
void InitQueue(SeqCQueue *Q)
{
    Q->front = Q->rear = Q->length = 0;
}

/**
 * 队列是否为空
 * @param Q
 * @return
 */
int IsEmpty(SeqCQueue *Q)
{
    if (Q->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 队列是否已满
 * @param Q
 * @return
 */
int IsFull(SeqCQueue *Q)
{
    if (Q->length > 0 && Q->front == Q->rear) {
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
int EnQueue(SeqCQueue *Q, QUEUE_ELEMENT_TYPE value)
{
    if (IsFull(Q) == TRUE) {
        return FALSE;
    }

    Q->queue[Q->rear] = value;
    Q->rear = (Q->rear + 1) % QUEUE_SIZE;
    Q->length++;

    return TRUE;
}

/**
 * 出队
 * @param Q
 * @param value
 * @return
 */
int DeQueue(SeqCQueue *Q, QUEUE_ELEMENT_TYPE *value)
{
    if (IsEmpty(Q) == TRUE) {
        return FALSE;
    }

    *value = Q->queue[Q->front];
    Q->front = (Q->front + 1) % QUEUE_SIZE;
    Q->length--;

    return TRUE;
}

/**
 * 获取队头元素
 * @param Q
 * @param value
 * @return
 */
int GetFront(SeqCQueue *Q, QUEUE_ELEMENT_TYPE *value)
{
    if (IsEmpty(Q) == TRUE) {
        return FALSE;
    }

    *value = Q->queue[Q->front];

    return TRUE;
}

/**
 * 测试顺序循环队列
 */
void TestSeqCQueue()
{
    SeqCQueue Q;
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