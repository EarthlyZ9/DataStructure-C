//
//  SimpleBinaryTree.h
//  SimpleBinaryTree
//
//  Created by Jisoo Lee on 2022/10/10.
//

#ifndef SimpleBinaryTree_h
#define SimpleBinaryTree_h

#include <stdio.h>
#include <stdlib.h>

// 노드 선언
typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode* Left;
    struct tagSBTNode* Right;
    ElementType Data;
} SBTNode;

// 함수 원형 선언
SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Root);
void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

#endif /* SimpleBinaryTree_h */
