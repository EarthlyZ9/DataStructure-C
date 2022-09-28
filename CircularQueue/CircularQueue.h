//
//  CircularQueue.h
//  CircularQueue
//
//  Created by Jisoo Lee on 2022/09/28.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagCircularNode
{
    int Capacity;
    int Front;
    int Rear;
    
    Node* Nodes;
} CircularQueue;

// 함수 원형 선언
void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
void CQ_PrintQueue(CircularQueue* Queue);

#endif /* CircularQueue_h */
