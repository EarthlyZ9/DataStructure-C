//
//  LinkedQueue.c
//  LinkedQueue
//
//  Created by Jisoo Lee on 2022/10/05.
//

#include "LinkedQueue.h"

// 링크드 큐 생성
void LQ_CreateQueue(LinkedQueue** Queue)
{
    // 큐를 자유 저장소에 생성
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

// 링크드 큐 소멸
void LQ_DestoryQueue(LinkedQueue* Queue)
{
    while(!LQ_IsEmpty(Queue))
    {
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }
    // 자유 저장소에서 할당 해제
    free(Queue);
}

// 노드 생성
Node* LQ_CreateNode(char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);
    
    strcpy(NewNode->Data, NewData); // 데이터 저장
    
    // 다음 노드에 대한 포인터는 NULL 로 초기화
    NewNode->NextNode = NULL;
    
    return NewNode;
}

// 노드 소멸
void LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}

// 노드 삽입
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
    if (Queue->Front == NULL)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }
    Queue->Count++;
}

// 노드 제거
Node* LQ_Dequeue(LinkedQueue* Queue)
{
    // 전단 노드
    Node* Front = Queue->Front;
    
    // 전단의 다음 노드가 NULL 일 때 -> 큐에 노드가 하나만 들어있을 때
    if (Queue->Front->NextNode == NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }
    Queue->Count--;
    
    // 제거 전 전단이었던 노드 반환
    return Front;
}

// 링크드 큐가 비었는지 확인
int LQ_IsEmpty(LinkedQueue* Queue)
{
    return (Queue->Front == NULL);
}

