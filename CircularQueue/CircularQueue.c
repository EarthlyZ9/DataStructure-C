//
//  CircularQueue.c
//  CircularQueue
//
//  Created by Jisoo Lee on 2022/09/28.
//

#include "CircularQueue.h"

// 큐 생성
void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    
    // 입력된 capacity + 1 만큼의 노드를 자유 저장소에 생성
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity + 1));
    
    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}


// 큐 제거
void CQ_DestroyQueue(CircularQueue* Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

// 노드 삽입
void CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
    
    
//    if (CQ_IsFull(Queue))
//    {
//        printf("Queue is full\n");
//        return;
//    }
//    
    int Position;
   
    // capacity 가 8이고 전단이 4 후단이 8 (더미) 를 가리키고 있을 때, 노드를 삽입하면 후단은 0이 됨
    if (Queue->Rear == Queue->Capacity)
    {
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    else
        Position = Queue->Rear++;
    
    Queue->Nodes[Position].Data = Data;
}

// 노드 제거
// 이 함수는 큐가 비었는지 확인하지 않는다. 확인 뒤 실행할 것
ElementType CQ_Dequeue(CircularQueue* Queue)
{
    int Position = Queue->Front;
    
    // 전단이 배열 끝에 도달한 경우 Front 를 0 으로 초기화
    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    else
        Queue->Front++;
    
    return Queue->Nodes[Position].Data;
}


int CQ_GetSize(CircularQueue* Queue)
{
    // 전단 <= 후단 일 때, 후단에서 전단을 빼면 크기임
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    
    // 후단 < 전단 일 때,
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

// 큐가 공백 상태인가
int CQ_IsEmpty(CircularQueue* Queue)
{
    return (Queue->Front == Queue->Rear);
}

// 큐가 포화상태인가
int CQ_IsFull(CircularQueue* Queue)
{
    // 전단 < 후단 일 경우 더미 노드로 인해 후단 - 전단 = capacity 인지 확인하면 됨
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    
    // 후단 < 전단 일 경우 후단 + 1 이 전단인 걸 확인하면 됨
    else
        return (Queue->Rear + 1) == Queue->Front;
}

// 큐 출력
void CQ_PrintQueue(CircularQueue* Queue)
{
    if (CQ_IsEmpty(Queue))
    {
        printf("Queue is empty\n");
        return;
    }
        
    int Position = Queue->Front;
    
    printf("Front Position: %d\n", Position);
    
    int i;
    for (i=0; i < Queue->Capacity; i++)
    {
        printf("index: %d, data: %d\n", Position, Queue->Nodes[Position].Data);
        if (Position == Queue->Capacity)
            Position = 0;
        else
            Position++;
    }

}
