//
//  ArrayStack.h
//  ArrayStack
//
//  Created by Jisoo Lee on 2022/09/24.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node* Nodes; // // 노드 배열 (노드 배열을 가리키고 있으므로 배열의 첫번째 요소를 가리키고 있는 것과 동일)
} ArrayStack;

// 함수 원형 선언
void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);
int AS_IsFull(ArrayStack* Stack);

#endif /* ArrayStack_h */
