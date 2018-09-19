typedef struct LinkNode
{
    int value;
    struct LinkNode *next;
} LinkNode, *LinkList;

void headInsert(LinkList l, int value);
void tailInsert(LinkList l, int value);
LinkNode findByIndex(LinkList l, int value);
void insertByIndex(LinkList l, int index, int value);
void deleteByIndex(LinkList l, int index);
void popFirst(LinkList l);
void popLast(LinkList l);
void print(LinkList l);
void testSinglyLinkedList();