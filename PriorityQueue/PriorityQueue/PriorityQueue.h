//
// Created by Jisoo Lee on 2022/11/16.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int PriorityType;

typedef struct tagPQNode
{
    PriorityType Priority;
    void* Data;     // 다양한 자료형을 담을 수 있도록 함
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

// 함수 원형 선언
PriorityQueue* PQ_Create(int InitialSize);
void PQ_Destroy(PriorityQueue* PQ);
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
int PQ_GetParent(int Index);
int PQ_GetLeftChild(int Index);
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);
int PQ_IsEmpty(PriorityQueue* PQ);

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
