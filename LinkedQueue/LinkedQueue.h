//
//  LinkedQueue.h
//  LinkedQueue
//
//  Created by Jisoo Lee on 2022/10/05.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
    char* Data; // 문자열을 담기 위해 char* 로 선언했지만 다른 자료형도 가능
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front;
    Node* Rear;
    int Count;
} LinkedQueue;

// 함수 원형 선언
void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestoryQueue(LinkedQueue* Queue);
Node* LQ_CreateNode(char* Data);
void LQ_DestroyNode(Node* _Node);
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);
int LQ_IsEmpty(LinkedQueue* Queue);

#endif /* LinkedQueue_h */
