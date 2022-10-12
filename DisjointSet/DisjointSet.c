//
//  DisjointSet.c
//  DisjointSet
//
//  Created by Jisoo Lee on 2022/10/12.
//

#include "DisjointSet.h"

// 합집합
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2)
{
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

// 집합 탐색 (원소가 속한 집합 탐색)
DisjointSet* DS_FindSet(DisjointSet* Set)
{
    while (Set->Parent != NULL)
    {
        Set = Set->Parent;
    }
    return Set;
}

// 분리 집합 생성
DisjointSet* DS_MakeSet(void* NewData)
{
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
    NewNode->Data = NewData;
    NewNode->Parent = NULL;
    
    return NewNode;
}

// 분리 집합 소멸
void DS_DestroySet(DisjointSet* Set)
{
    free(Set);
}
