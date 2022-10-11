//
//  ExpressionTree.c
//  ExpressionTree
//
//  Created by Jisoo Lee on 2022/10/11.
//

#include "ExpressionTree.h"

// 노드 생성
ETNode* ET_CreateNode(ElementType NewData)
{
    ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;
    
    return NewNode;
}

// 노드 소멸
void ET_DestroyNode(ETNode* Node)
{
    free(Node);
}

// 트리 소멸 - 후위 순회 이용 (잎 노드부터 제거해야 하기 때문)
void ET_DestroyTree(ETNode* Root)
{
    // 트리가 비어있을 때
    if (Root == NULL)
        return;
    
    // 왼쪽 하위 트리 소멸
    ET_DestroyTree(Root->Left);
    
    // 오른쪽 하위 트리 소멸
    ET_DestroyTree(Root->Right);
    
    // 뿌리 노드 소멸
    ET_DestroyNode(Root);
}

// 전위 순회를 이용한 이진 트리 출력
void ET_PreorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
    
    // 왼쪽 하위 트리 출력
    ET_PreorderPrintTree(Node->Left);
    
    // 오른쪽 하위 트리 출력
    ET_PreorderPrintTree(Node->Right);
}

// 중위 순회를 이용한 이진 트리 출력
void ET_InorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;
    
    // 왼쪽 하위 트리 출력
    ET_InorderPrintTree(Node->Left);
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
    
    // 오른쪽 하위 트리 출력
    ET_InorderPrintTree(Node->Right);
}

// 후위 순위를 이용한 이진 트리 출력
void ET_PostorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;
    
    // 왼쪽 하위 트리 출력
    ET_PostorderPrintTree(Node->Left);
    
    // 오른쪽 하위 트리 출력
    ET_PostorderPrintTree(Node->Right);
    
    // 뿌리 노드 출력
    printf(" %c", Node->Data);
}

// 수식 트리 구축
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node)
{
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len - 1];
    PostfixExpression[len-1] = '\0';
    
    switch(Token)
    {
        // 연산자인 경우
        case '+': case '-': case '*': case '/':
            (*Node) = ET_CreateNode(Token);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
            break;
        // 피연산자인 경우
        default:
            (*Node) = ET_CreateNode(Token);
            break;
            
    }
}

// 수식 트리 계산
double ET_Evaluate(ETNode* Tree)
{
    char Temp[2];
    
    double Left = 0;
    double Right = 0;
    double Result = 0;
    
    if (Tree == NULL)
        return 0;
    
    switch (Tree->Data)
    {
        // 연산자인 경우
        case '+': case '-': case '*': case '/':
            Left = ET_Evaluate(Tree->Left);
            Right = ET_Evaluate(Tree->Right);
            
            // Left 와 Right 구한 뒤 연산 수행
            if (Tree->Data == '+') Result = Left + Right;
            else if (Tree->Data == '-') Result = Left - Right;
            else if (Tree->Data == '*') Result = Left * Right;
            else if (Tree->Data == '/') Result = Left / Right;
            
            break;
        // 피연산자일 때
        default:
            
            // 메모리 블록에서 모든 바이트를 특정 값으로 설정할 때 사용하는 함수 -> 0 으로 초기화
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp); // 문자 스트링을 부동 소수점 값으로 변환
            break;
            
    }
    
    return Result;
}

