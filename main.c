#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demo1_basic() {
    printf("------Pointer Using------\n");
    int a = 10;
    int* p;
    p = &a;
    printf("a:%d\n", a);
    printf("&a:%p\n", &a);
    printf("p:%p\n", p);
    printf("*p:%d\n", *p);
    *p = 20;
    printf("After changing *p to 20, a becomes:%d\n", a);
    printf("\n");
}

void demo2_array() {
    printf("------Pointers & Array------\n");
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* p = arr;
    printf("arr[0]=%d\n", arr[0]);
    printf("*p=%d\n", *p);
    printf("*(p+1)=%d\n", *(p + 1));
    printf("*(p+2)=%d\n", *(p + 2));
    printf("arr[3]=%d, *(arr+3)=%d\n", arr[3], *(arr + 3)); 
    printf("Traversing an array using a pointer: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i)); 
    }
    printf("\n\n");
}

// Wrong example:
void swap_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Right example:
void swap_right(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demo3_swap() {
    printf("------Pointers & Function Parameters------\n");

    int x = 3, y = 5;

printf("Before exchanging:x=%d,y=%d\n", x, y);
    
    swap_wrong(x, y);
    printf("After swap_wrong:x=%d,y=%d (Not changed)\n", x, y);

    swap_right(&x, &y);
    printf("After exchanging:x=%d,y=%d\n", x, y);

    printf("\n");
}

void demo4_string() {
    printf("------Pointers & String------\n");

    char str[] = "hello";
    char* p = str;

    printf("Traverse the string with a pointer:\n");
    while (*p != '\0') {
        printf("%c",*p);
        p++;
    }
    printf("\n\n");
}

void demo5_double_pointer() {
    printf("------Double Pointer------\n");

    int a = 100;
    int* p = &a;
    int** pp = &p;

    printf("a=%d\n", a);
    printf("*p=%d\n", *p);
    printf("**pp=%d\n", **pp);
    printf("\n");
}

//链表节点定义

typedef struct Node {
    int data;
    struct Node* next;
}Node;

//辅助函数：打印链表

void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

//头插法（二级指针：**）

void insertHead(Node **head, int val) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;

    newNode->next = *head;

    *head = newNode;
    }

//头删法

void deleteHead(Node** head) {
    if (*head == NULL)return;

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

//链表逆置

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = next;
    }
    *head = prev;
}

//demo6:

void demo6_linked_list() {
    printf("------Linked List------\n\n");

    Node* head = NULL;

    printf("【头插法】依次插入 10, 20, 30:\n");
    insertHead(&head, 10);   // 传头指针的地址！
    printf("  插入 10 后: ");
    printList(head);

    insertHead(&head, 20);
    printf("  插入 20 后: ");
    printList(head);

    insertHead(&head, 30);
    printf("  插入 30 后: ");
    printList(head);
    printf("  ↑ 注意：新节点都插在最前面，所以顺序是反的\n\n");

    // —— 链表逆置演示 ——
    printf("【链表逆置】:\n");
    printf("  逆置前: ");
    printList(head);
    reverseList(&head);
    printf("  逆置后: ");
    printList(head);
    printf("\n");

    // —— 头删法演示 ——
    printf("【头删法】删两次:\n");
    printf("  删除前: ");
    printList(head);
    deleteHead(&head);
    printf("  删一次: ");
    printList(head);
    deleteHead(&head);
    printf("  删两次: ");
    printList(head);
    printf("\n");

    // 释放剩余节点（好习惯，防止内存泄漏）
    while (head != NULL) {
        deleteHead(&head);
    }
    printf("全部释放后，链表已清空。\n");
    printf("\n");
}

int main() {
    demo1_basic();
    demo2_array();
    demo3_swap();
    demo4_string();
    demo5_double_pointer();
    demo6_linked_list();
    return 0;
}
