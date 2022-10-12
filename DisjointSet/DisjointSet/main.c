//
//  main.c
//  DisjointSet
//
//  Created by Jisoo Lee on 2022/10/12.
//

#include <stdio.h>
#include "DisjointSet.h"

int main(void)
{
    // 분리 집합 생성
    int a = 1, b = 2, c = 3, d = 4;
    DisjointSet* Set1 = DS_MakeSet(&a);
    DisjointSet* Set2 = DS_MakeSet(&b);
    DisjointSet* Set3 = DS_MakeSet(&c);
    DisjointSet* Set4 = DS_MakeSet(&d);
    
    printf("Set1 == Set2 : %d\n", DS_FindSet(Set1) == DS_FindSet(Set2)); // Set1 과 Set2 는 서로 다른 뿌리 노드를 가리킴 -> false
    
    DS_UnionSet(Set1, Set3);
    printf("Set1 == Set3 : %d\n", DS_FindSet(Set1) == DS_FindSet(Set3)); // Set1 뿌리 노드의 자식 노드로 Set2 가 추가되었기에true 서로 같은 뿌리 노드를 가리킴 -> true
    
    DS_UnionSet(Set3, Set4);
    printf("Set3 == Set4 : %d\n", DS_FindSet(Set3) == DS_FindSet(Set3));
    
    return 0;
}
