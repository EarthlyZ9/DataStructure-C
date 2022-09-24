//
//  ArrayStack.c
//  ArrayStack
//
//  Created by Jisoo Lee on 2022/09/24.
//

#include "ArrayStack.h"
#include <stdio.h>

// 스택 및 노드 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    // 스택을 자유 저장소에 생성
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    
    // Capacity만큼의 노드를 자유 저장소에 생성
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    
    // 초기화
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

// 스택 제거
void AS_DestroyStack(ArrayStack* Stack)
{
    free(Stack->Nodes);
    free(Stack);
}

// 노드 삽입
void AS_Push(ArrayStack* Stack, ElementType Data)
{
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data; // 배열의 인덱스를 사용하여 Data 삽입
}


// 노드 제거
ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = Stack->Top--;
    return Stack->Nodes[Position].Data; // 제거한 노드의 반환
}

// 최상위 노드 반환
ElementType AS_Top(ArrayStack* Stack)
{
    return Stack->Nodes[Stack->Top].Data;
}

// 스택의 크기 반환
int AS_GetSize(ArrayStack* Stack)
{
    return Stack->Top+1;
}

// 스택이 비었는지 확인
int AS_IsEmpty(ArrayStack* Stack)
{
    return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack)
{
    return (Stack->Top+1 == Stack->Capacity);
}
