//
//  main.c
//  CircularQueue
//
//  Created by Jisoo Lee on 2022/09/28.
//

#include <stdio.h>
#include "CircularQueue.h"

int main(void) {
    int i;
    CircularQueue* Queue;
    
    // 큐 생성
    CQ_CreateQueue(&Queue, 10);
    
    // 노드 삽입
    CQ_Enqueue(Queue, 1);
    CQ_Enqueue(Queue, 2);
    CQ_Enqueue(Queue, 3);
    CQ_Enqueue(Queue, 4);
    
    // 노드 제거
    for (i=0; i<3; i++)
    {
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }
    
    // 노드 삽입
    i = 100;
    while (CQ_IsFull(Queue) == 0)
    {
        CQ_Enqueue(Queue, i++);
    }
    
    // 큐 크기
    printf("Capacity: %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));
    
    // 노드 제거
    while(CQ_IsEmpty(Queue) == 0)
    {
        printf("Dequeue: %d ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }
    
    // 큐 제거
    CQ_DestroyQueue(Queue);
    return 0;

}
