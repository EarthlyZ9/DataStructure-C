//
//  CircularLinkedList.h
//  CircularLinkedList
//
//  Created by Jisoo Lee on 2022/09/23.
//

#ifndef CircularLinkedList_h
#define CircularLinkedList_h

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
Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void Print_Node(Node* _Node);


#endif /* CircularLinkedList_h */
