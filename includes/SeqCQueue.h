#include "Common.h"
#define QUEUE_SIZE 100
#define QUEUE_ELEMENT_TYPE int

/* 循环队列结构体 */
typedef struct
{
    /*存放队列元素的一维数组 */
    QUEUE_ELEMENT_TYPE queue[QUEUE_SIZE];

    /* 队头指针 */
    int front;

    /* 队尾指针 */
    int rear;

    /* 队列长度 */
    int length;
} SeqCQueue;

void InitQueue(SeqCQueue *Q);
int IsEmpty(SeqCQueue *Q);
int IsFull(SeqCQueue *Q);
int EnQueue(SeqCQueue *Q, QUEUE_ELEMENT_TYPE value);
int DeQueue(SeqCQueue *Q, QUEUE_ELEMENT_TYPE *value);
int GetFront(SeqCQueue *Q, QUEUE_ELEMENT_TYPE *value);
void TestSeqCQueue();