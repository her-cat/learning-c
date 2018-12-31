#include <stdio.h>
#include <malloc.h>

/**
 * 结构体
 */
struct PerNode {
    // 序号
    int m_iNumber;
    // 下一个元素的指针
    struct PerNode * m_pNextPer;
};

/*
**函数功能：采用malloc函数动态地创建并初始化一个单向链表
**入口参数：iLstLen为拟创建链表的结点数
**返回值：新创建链表的头结点的指针
*/
struct PerNode * crtPrLst(int iLstLen) {
    // 生成头节点
    struct PerNode *headNode = malloc(sizeof(struct PerNode));

    struct PerNode * perNode = headNode;
    perNode->m_pNextPer = NULL;

    // 用于存放临时生成的元素
    struct PerNode *temp;

    // 创建链表
    for (int i = iLstLen; i >= 1 ; i--) {
        temp = malloc(sizeof(struct PerNode));
        temp->m_iNumber = i;
        temp->m_pNextPer = perNode->m_pNextPer;
        perNode->m_pNextPer = temp;
    }

    return headNode;
}

/**
 * 删除并返回链表的第一个元素
 * @param pTmp
 * @return
 */
struct PerNode * pop(struct PerNode * pTmp) {
    if (pTmp == NULL) {
        return NULL;
    }

    // 取出第一个元素
    struct PerNode * temp = pTmp->m_pNextPer;

    if (temp == NULL) {
        return NULL;
    }

    // 移除第一个元素
    pTmp->m_pNextPer = temp->m_pNextPer;

    return temp;
}

/**
 * 向链表的末尾添加一个元素
 * @param pTmp
 * @param value
 */
void push(struct PerNode * pTmp, int value) {
    struct PerNode * l = pTmp->m_pNextPer;

    // 遍历到最后一个元素
    while (l != NULL && l->m_pNextPer != NULL) {
        l = l->m_pNextPer;
    }

    // 新建一个元素
    struct PerNode * node = malloc(sizeof(struct PerNode));
    node->m_iNumber = value;
    node->m_pNextPer = NULL;

    // 如果最后一个元素不为空则插入到它的后面
    if (l != NULL) {
        l->m_pNextPer = node;
    }
}

struct PerNode * josephus(struct PerNode *pTmp) {
    // 计数器，用来报数
    int i = 0;
    // 最后留在圈子中的元素
    struct PerNode * p;

    while (1) {
        // 模拟报数
        i++;
        // 取出一个元素
        struct PerNode * node = pop(*&pTmp);
        // 如果元素为 NULL，则说明没有人了
        if (node == NULL) {
            break;
        }

        // 如果这个人报数不是 3，则放回链表尾部
        if (i % 3 != 0) {
            push(*&pTmp, node->m_iNumber);
        }

        // 记录当前的元素
        p = node;
    }

    return p;
}

/**
 * 打印链表
 * @param l
 */
void printLink(struct PerNode * l)
{
    while (l != NULL) {
        printf("%d \n", l->m_iNumber);
        l = l->m_pNextPer;
    }

    printf("---------\n");
}

int main() {
    // 创建一个长度为13的链表
    struct PerNode *pHead = crtPrLst(13);
    // 找出最后在圈子中的人
    pHead = josephus(pHead);
    // 打印它的序号
    printf("%d \n", pHead->m_iNumber);

    return 0;
}