//
//  main.c
//  ExpressionTree
//
//  Created by Jisoo Lee on 2022/10/11.
//

#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
    ETNode* Root = NULL;
    
    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);
    
    // 트리 출력
    printf("Preorder...\n");
    ET_PreorderPrintTree(Root);
    printf("\n\n");
    
    printf("Inorder...\n");
    ET_InorderPrintTree(Root);
    printf("\n\n");
    
    printf("Postorder...\n");
    ET_PostorderPrintTree(Root);
    printf("\n\n");
    
    // 수식 트리 계산
    printf("Evaluation Result: %f\n", ET_Evaluate(Root));
    
    // 트리 소멸
    ET_DestroyTree(Root);
    
    return 0;
}

