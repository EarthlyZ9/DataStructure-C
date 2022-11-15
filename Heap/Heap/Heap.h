//
// Created by Jisoo Lee on 2022/11/15.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct tagHeapNode
{
    ElementType Data;
} HeapNode;

typedef struct tagHeap
{
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

// 함수 원형 선언
Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_PrintNodes(Heap* H);



#endif //HEAP_HEAP_H
