#include "Common.h"
#define QUEUE_ELEMENT_TYPE int

/* 队列节点结构体 */
typedef struct node {
    /* 存放节点数据 */
    QUEUE_ELEMENT_TYPE data;

    /* 后继节点指针 */
    struct node *next;
} QueueNode;

/* 链式队列结构体 */
typedef struct {
    /* 队头指针 */
    QueueNode *front;

    /* 队尾指针 */
    QueueNode *rear;

    /* 队列长度 */
    int length;
} LinkQueue;

void InitQueue(LinkQueue *Q);
int IsEmpty(LinkQueue *Q);
int EnQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE value);
int DeQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE *value);
int GetFront(LinkQueue *Q, QUEUE_ELEMENT_TYPE *value);
void TestLinkQueue();