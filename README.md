# 单链表公共结点查找（408 数据结构算法）

> 经典“Y 字形”链表问题 —— 求两个单链表的第一个公共结点。

## 功能说明

- 给定两个带头结点的单链表 `A` 和 `B`，若它们从某个结点开始重合（形成 Y 型），返回第一个公共结点的指针；否则返回 `NULL`。
- 算法时间复杂度 **O(m+n)**，空间复杂度 **O(1)**，满足考研算法题要求。

## 核心算法（C 语言）

```c
LNode* FindCommon(LinkList A, LinkList B) {
    int lenA = Length(A), lenB = Length(B);
    LNode *p = A->next, *q = B->next;
    // 长链表先走，使二者到链表尾部的距离相等
    while (lenA > lenB) { p = p->next; lenA--; }
    while (lenB > lenA) { q = q->next; lenB--; }
    // 同步移动，直到相遇或同时到达 NULL
    while (p != NULL && p != q) {
        p = p->next;
        q = q->next;
    }
    return p;   // 要么是公共结点，要么是 NULL
}
