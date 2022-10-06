//
//  LCRSTree.c
//  LeftChildRightSiblingTree
//
//  Created by Jisoo Lee on 2022/10/07.
//

#include "LCRSTree.h"

//  노드 생성
LCRSNode* LCRS_CreateNode(ElementType NewData)
{
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;
    
    return NewNode;
}

// 노드 소멸
void LCRS_DestroyNode(LCRSNode* Node)
{
    free(Node);
}

// 트리 소멸
void LCRS_DestroyTree(LCRSNode* Root)
{
    // 형제 노드가 연결되어 있는 경우
    if (Root->RightSibling != NULL)
        LCRS_DestroyNode(Root->RightSibling);
    
    // 자식 노드가 연결되어 있는 경우
    if (Root->LeftChild != NULL)
        LCRS_DestroyNode(Root->LeftChild);
    
    Root->LeftChild = NULL;
    Root->RightSibling = NULL;
    
    LCRS_DestroyNode(Root);
}

// 자식 노드 연결
void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode *ChildNode)
{
    // 부모 노드에 자식 노드가 있는지 검사
    
    // 자식 노드가 없다면 Parent 의 LeftChild 포인터에 바로 연결
    if (ParentNode->LeftChild == NULL)
        ParentNode->LeftChild = ChildNode;
    else
    {
        // 부모 노드에 자식 노드가 있다면, 가장 오른쪽에 있는 자식 노드를 찾아 그 노드의 RightSibling 에 child 를 연결
        LCRSNode* TempNode = ParentNode->LeftChild;
        while (TempNode->RightSibling != NULL)
            TempNode = TempNode->RightSibling;
        
        TempNode->RightSibling = ChildNode;
    }
}

// 트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
    // 재귀 함수로 구현함
    int i = 0;
    
    // 하나의 depth 당 공백 3칸
    for (i=0; i<Depth-1; i++)
        printf("   ");
    
    // 자식 노드 여부 표시
    if (Depth > 0)
        printf("+--");
    
    // 노드 데이터 출력
    printf("%c\n", Node->Data);
    
    // 자식 노드가 있다면 재귀적으로 함수를 호출함
    if (Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth+1);
    
    // 형제 노드가 있다면 재귀적으로 함수를 호출함
    if (Node->RightSibling != NULL)
        LCRS_PrintTree(Node->RightSibling, Depth);
}
