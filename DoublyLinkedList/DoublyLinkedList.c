//
//  DoublyLinkedList.c
//  DoublyLinkedList
//
//  Created by Jisoo Lee on 2022/09/22.
//

#include "DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    NewNode-> Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    
    return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head
    if ( (*Head) == NULL )
    {
        *Head = NewNode;
    }
    else
    {
        //  테일을 찾아 NewNode를 연결한다.
        Node* Tail = (*Head);
        while ( Tail->NextNode != NULL )
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;  // 기존의 테일이 새로운 테일의 prevNode 가 됨
    }
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current -> NextNode;
    }

    return Current;
}

// 노드 삭제
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    // 삭제하고자 하는 노드가 헤드일 때
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        
        // 새로 헤드가 된 노드가 NULL 일 때, 즉 리스트에 remove 할 노드 밖에 존재하지 않았을 때의 경우가 아니라면,
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;
        
        Remove->PrevNode =  NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;
        
        // remove 하려던 노드가 헤드가 아니었다면
        if (Remove->PrevNode != NULL)
            // 삭제하고자 하는 노드의 PrevNode 의 NextNode 가 삭제하고자 하는 노드의 NextNode 가 되어야함
            Remove->PrevNode->NextNode = Temp->NextNode;
        
        // remove 하려던 노드가 테일이 아니었다면
        if (Remove->NextNode != NULL)
        {
            // 삭제하고자 하는 노드의 NextNode 의 PrevNode 가 삭제하고자 하는 노드의 PrevNode 가 되어야함
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
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

// 노드 개수 세기
int DLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;
    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
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
