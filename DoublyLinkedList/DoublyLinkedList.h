//
//  DoublyLinkedList.h
//  DoublyLinkedList
//
//  Created by Jisoo Lee on 2022/09/22.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

// 함수 원형 선언
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);
void PrintNode(Node* Node);

#endif /* DoublyLinkedList_h */
