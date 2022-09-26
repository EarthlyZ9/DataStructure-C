//
//  LinkedListStack.c
//  PostFixCalculator
//
//  Created by Jisoo Lee on 2022/09/27.


#include "LinkedListStack.h"

// 스택 생성
void LLS_CreateStack(LinkedListStack** Stack)
{
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

// 스택 소멸
void LLS_DestroyStack(LinkedListStack* Stack)
{
    while (!LLS_IsEmpty(Stack))
    {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    
    free(Stack);
}

// 노드 생성
Node* LLS_CreateNode(char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData)+1); // 문자열이므로 ₩0 자리 포함해서 + 1
    
    strcpy(NewNode->Data, NewData); // 데이터 저장
    NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL 로 초기화
    
    return NewNode; // 노드의 주소 반환
}

// 노드 소멸
void LLS_DestroyNode(Node* _Node)
{
    free(_Node->Data); // 자유 저장소에서 Data 필드 할당 해제
    free(_Node);  // 노드를 할당 해제
}

// 노드 삽입
void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
    if (Stack->List == NULL)
        Stack->List = NewNode;
    else
        // 스택의 Top 위에 새 노드를 얹음
        Stack->Top->NextNode = NewNode;
    
    // 스택의 Top 필드에 새 노드의 주소 등록
    Stack->Top = NewNode;
}

// 노드 제거
Node* LLS_Pop(LinkedListStack* Stack)
{
    // 함수가 반환할 최상위 노드 저장
    Node* TopNode = Stack->Top;
    
    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        Node* CurrentTop = Stack->List;
        
        // Top 아래에 있던 노드를 새로운 CurrentTop 에 저장
        while(CurrentTop != NULL & CurrentTop->NextNode != Stack->Top)
        {
            CurrentTop = CurrentTop->NextNode;
        }
        
        // CurrentTop 을 Top 에 저장
        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }
    return TopNode;
}

// 최상위 노드 반환
Node* LLS_Top(LinkedListStack* Stack)
{
    return Stack->Top;
}

// 스택의 크기 반환
int LLS_GetSize(LinkedListStack* Stack)
{
    int Count = 0;
    Node* Current = Stack->List;
    
    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}

// 스택이 비었는지 확인
int LLS_IsEmpty(LinkedListStack* Stack)
{
    return (Stack->List == NULL);
}

