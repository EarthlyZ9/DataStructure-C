//
// Created by Jisoo Lee on 2022/11/16.
//

#include "PriorityQueue.h"

// 우선순위 큐 생성
PriorityQueue* PQ_Create(int InitialSize)
{
    PriorityQueue* NewPQ = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*) malloc(sizeof(PQNode) * NewPQ->Capacity);\

    return NewPQ;
}

// 우선순위 큐 제거
void PQ_Destroy(PriorityQueue* PQ)
{
    free(PQ->Nodes);
    free(PQ);
}

// 우선순위에 따라 삽입
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData)
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent(CurrentPosition);

    // UsedSize 가 Capacity 에 도달했을 때
    if (PQ->UsedSize == PQ->Capacity)
    {
        // Capacity 가 0 일 때 (즉, 처음 삽입할 때)
        if (PQ->Capacity == 0)
            PQ->Capacity = 1;

        // Capacity 를 두배로 늘려주고 메모리를 재할당함
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*) realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }

    PQ->Nodes[CurrentPosition] = NewData;

    // 후속 처리 (우선순위에 따라 정렬)
    // 부모 노드 > 자식 노드 일때 루프 (부모가 자식보다 작아야함)
    while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
    {
        // 자리를 바꿔줌
        PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent(CurrentPosition);
    }
    PQ->UsedSize++;
}

// 노드 간 자리 바꾸기
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
    int CopySize = sizeof (PQNode);
    PQNode* Temp = (PQNode*) malloc(sizeof (CopySize));

    memcpy(Temp, &PQ->Nodes[Index1], CopySize); // Temp 에 Index 1 의 값 복사
    memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize); // Index1 자리에 Index2 값 복사
    memcpy(&PQ->Nodes[Index2] , Temp, CopySize); // Index2 자리에 Temp (기존의 Index1) 값 복사

    free(Temp);
}

// 노드 꺼내기 (제거)
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode)); // Root 에 최솟값 저장
    memset(&PQ->Nodes[0], 0, sizeof(PQNode)); // Root 메모리 블럭에 0 할당

    PQ->UsedSize--;

    // 힙 트리 최고 깊이 가장 오른쪽에 있는 노드를 뿌리 노드로 옮겨옴
    PQ_SwapNodes(PQ, 0, PQ->UsedSize);

    LeftPosition = PQ_GetLeftChild(0);
    RightPosition - LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        // LeftPosition 이 전체 크기 보다 같거나 커졌을 때 break
        if ( LeftPosition >= PQ->UsedSize )
            break;

        // LeftPosition 은 전체 크기 인덱스 범위 이내인데, RightPosition 이 전체 크기 보다 같거나 커졌을 때 -> 오른쪽 자식 노드가 없다는 뜻
        if ( RightPosition >= PQ->UsedSize )
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            // LeftPosition, RightPosition 모두 인덱스 범위 이내

            // 왼쪽 자식 > 오른쪽 자식일 때, 작은 쪽인 오른쪽이 swap 의 대상
            if ( PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
                SelectedChild = RightPosition;
            // 왼쪽 자식 < 오른쪽 자식일 때, 작은 쪽인 왼쪽 swap 의 대상
            else
                SelectedChild = LeftPosition;
        }

        // 바꾸는 대상이 되는 노드의 값 < 부모 노드 값일 때 자리를 바꿔준다
        if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition  =PQ_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    // UsedSize 가 Capacity 의 절반을 차지하지 못하면 사이즈를 줄여줌
    if ( PQ->UsedSize < ( PQ->Capacity / 2 ) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*) realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}

// 부모 노드 인덱스 가져오기
int PQ_GetParent(int Index)
{
    return (int) ((Index - 1) / 2);
}

// 왼쪽 자식 노드 인덱스 가져오기
int PQ_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

// 큐가 비었는지 확인
int PQ_IsEmpty(PriorityQueue* PQ)
{
    return (PQ->UsedSize == 0);
}
