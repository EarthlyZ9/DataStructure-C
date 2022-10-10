//
//  SimpleBinaryTree.c
//  SimpleBinaryTree
//
//  Created by Jisoo Lee on 2022/10/10.
//

#include "SimpleBinaryTree.h"

// 노드 생성
SBTNode* SBT_CreateNode(ElementType NewData)
{
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;
    
    return NewNode;
}

// 노드 소멸
void SBT_DestroyNode(SBTNode* Node)
{
    free(Node);
}

// 트리 소멸 - 후위 순회 이용 (잎 노드부터 제거해야 하기 때문)
void SBT_DestroyTree(SBTNode* Root)
{
    // 트리가 비어있을 때
    if (Root == NULL)
        return;
    
    // 왼쪽 하위 트리 소멸
    SBT_DestroyTree(Root->Left);
    
    // 오른쪽 하위 트리 소멸
    SBT_DestroyTree(Root->Right);
    
    // 뿌리 노드 소멸
    SBT_DestroyNode(Root);
}

// 전위 순회를 이용한 이진 트리 출력
void SBT_PreorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
    
    // 왼쪽 하위 트리 출력
    SBT_PreorderPrintTree(Node->Left);
    
    // 오른쪽 하위 트리 출력
    SBT_PreorderPrintTree(Node->Right);
}

// 중위 순회를 이용한 이진 트리 출력
void SBT_InorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;
    
    // 왼쪽 하위 트리 출력
    SBT_InorderPrintTree(Node->Left);
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
    
    // 오른쪽 하위 트리 출력
    SBT_InorderPrintTree(Node->Right);
}

// 후위 순위를 이용한 이진 트리 출력
void SBT_PostorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;
    
    // 왼쪽 하위 트리 출력
    SBT_PostorderPrintTree(Node->Left);
    
    // 오른쪽 하위 트리 출력
    SBT_PostorderPrintTree(Node->Right);
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
}
