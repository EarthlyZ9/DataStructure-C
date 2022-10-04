//
//  main.c
//  LinkedQueue
//
//  Created by Jisoo Lee on 2022/10/05.
//

#include <stdio.h>
#include "LinkedQueue.h"

int main(void) {
    Node* Popped;
    LinkedQueue* Queue;
    
    // 링크드 큐 생성
    LQ_CreateQueue(&Queue);
    
    // 노드 삽입
    LQ_Enqueue(Queue, LQ_CreateNode("abc"));
    LQ_Enqueue(Queue, LQ_CreateNode("def"));
    LQ_Enqueue(Queue, LQ_CreateNode("efg"));
    LQ_Enqueue(Queue, LQ_CreateNode("hij"));
    
    printf("Queue Size: %d\n", Queue->Count);
    
    while(LQ_IsEmpty(Queue) == 0)
    {
        // 차례대로 전단 제거 및 소멸
        Popped = LQ_Dequeue(Queue);
        printf("Dequeue: %s\n", Popped->Data);
        LQ_DestroyNode(Popped);
    }
    
    // 링크드 큐 소멸
    LQ_DestoryQueue(Queue);
}
