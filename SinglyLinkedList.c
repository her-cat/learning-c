#include <stdio.h>
#include <malloc.h>
#include "includes/SinglyLinkedList.h"

/**
 * 头插法
 * @param l
 * @param value
 */
void headInsert(LinkList l, int value)
{
    LinkList p = (LinkList)malloc(sizeof(LinkNode));
    p->value = value;
    p->next = l->next;
    l->next = p;
}

/**
 * 尾插法
 * @param l
 * @param value
 */
void tailInsert(LinkList l, int value)
{
    LinkList p = (LinkList)malloc(sizeof(LinkNode));
    p->value = value;
    p->next = NULL;
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = p;
}

/**
 * 根据序号查找元素
 * @param l
 * @param index
 * @return
 */
LinkNode findByIndex(LinkList l, int index)
{
    LinkNode p;
    int i = 0;
    while (l != NULL && i <= index) {
        if (i == index) {
            p = *l;
            break;
        }
        i++;
        l = l->next;
    }

    return p;
}

/**
 * 在指定位置插入数据
 * @param l
 * @param index
 * @param value
 */
void insertByIndex(LinkList l, int index, int value)
{
    LinkList p = (LinkList)malloc(sizeof(LinkNode));
    p->value = value;
    int i = 0;
    while (l != NULL && i <= index) {
        if (i == index) {
            p->next = l->next;
            l->next = p;
            break;
        }
        i++;
        l = l->next;
    }
}

/**
 * 删除指定位置数据
 * @param l
 * @param index
 */
void deleteByIndex(LinkList l, int index)
{
    LinkList p;
    int i = 0;
    while (l != NULL && i <= index) {
        if (i == index) {
            p = l->next;
            l->next = p->next;
            free(p);
            break;
        }
        i++;
        l = l->next;
    }
}

/**
 * 移除第一个元素
 * @param l
 */
void popFirst(LinkList l)
{
    LinkList p = l->next;
    l->next = p->next;
    free(p);
}

/**
 * 移除最后一个元素
 * @param l
 */
void popLast(LinkList l)
{
    while (l->next->next != NULL) {
        l = l->next;
    }

    l->next = NULL;
}

/**
 * 打印链表
 * @param l
 */
void print(LinkList l)
{
    while (l != NULL) {
        printf("%d \n", l->value);
        l = l->next;
    }

    printf("---------\n");
}

void testSinglyLinkedList()
{
    LinkList l = (LinkList)malloc(sizeof(LinkNode));
    l->value = -1;
    l->next = NULL;
    headInsert(l, 1);
    headInsert(l, 2);
    headInsert(l, 3);
    tailInsert(l, 4);
    print(l);
    printf("%d \n---------\n", findByIndex(l, 2).value);
    insertByIndex(l, 2, 8);
    print(l);
    deleteByIndex(l, 2);
    print(l);
    popFirst(l);
    print(l);
    popLast(l);
    print(l);
}