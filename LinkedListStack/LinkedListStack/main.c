//
//  main.c
//  LinkedListStack
//
//  Created by Jisoo Lee on 2022/09/26.
//

#include <stdio.h>
#include "LinkedListStack.h"

int main(void) {
    int i = 0;
    int Count = 0;
    Node* Popped;
    
    LinkedListStack* Stack;
    
    LLS_CreateStack(&Stack);
    
    // 노드 추가
    LLS_Push(Stack, LLS_CreateNode("abc"));
    LLS_Push(Stack, LLS_CreateNode("def"));
    LLS_Push(Stack, LLS_CreateNode("efg"));
    LLS_Push(Stack, LLS_CreateNode("hij"));
    
    // 스택 크기 출력
    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n", Count, LLS_Top(Stack)->Data);
    
    // 스택이 빌 때 까지 노드 제거하기
    for (i = 0; i < Count; i++)
    {
        if (LLS_IsEmpty(Stack))
            break;
        
        Popped = LLS_Pop(Stack);
        
        printf("Popped: %s\n", Popped->Data);
        
        LLS_DestroyNode(Popped);
        
        if (!LLS_IsEmpty(Stack))
            printf("Current Top: %s\n", LLS_Top(Stack)->Data);
        else
            printf("Stack is empty\n");
    }
    LLS_DestroyStack(Stack);
}
