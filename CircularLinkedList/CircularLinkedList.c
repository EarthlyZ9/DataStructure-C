//
//  CircularLinkedList.c
//  CircularLinkedList
//
//  Created by Jisoo Lee on 2022/09/23.
//

#include <stdio.h>
#include "CircularLinkedList.h"

// 노드 생성
Node* CDLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    NewNode-> Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    
    return NewNode;
}

// 노드 소멸
void CDLL_DestroyNode(Node* Node)
{
    free(Node);
}

// 노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head
    if ( (*Head) == NULL )
    {
        *Head = NewNode;
        (*Head)->PrevNode = *Head;
        (*Head)->NextNode = *Head;
    }
    else
    {
        //  헤드의 이전 노드가 Tail
        Node* Tail = (*Head)->PrevNode;
        
        // 테일의 다음 노드, 즉 헤드의 이전 노드 자리에 NewNode
        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;
        
        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

// 노드 삽입
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    
    // current node 가 테일이 아니었을 때
    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

// 노드 삭제
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
    // 삭제하고자 하는 노드가 헤드일 때
    if (*Head == Remove)
    {
        // 헤드의 이전 노드, 즉 테일의, 다음 노드는 삭제하고자 하는 노드의 다음 노드
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        
        // 헤드의 다음 노드의 이전 노드는 삭제하고자 하는 노드의 이전 노드가 됨
        (*Head)->NextNode->PrevNode = Remove->PrevNode;
        
        // 새로운 헤드: 삭제하고자 하는 노드의 다음 노드
        *Head = Remove->NextNode;
        
        Remove->PrevNode =  NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

// 노드 탐색
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current -> NextNode;
    }

    return Current;
}

// 노드 개수 세기
int CDLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;
    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
        if (Current == Head)
            break;
    }
    return Count;
}

// 노드 정보 출력
void PrintNode(Node* _Node)
{
    // 헤드일 때
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);
    
    printf("Current: %d", _Node->Data);
    
    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}
