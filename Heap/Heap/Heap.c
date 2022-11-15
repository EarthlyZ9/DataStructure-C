//
// Created by Jisoo Lee on 2022/11/15.
//

#include "Heap.h"

// 힙 생성
Heap* HEAP_Create(int InitialSize)
{
    Heap* NewHeap = (Heap*) malloc(sizeof (Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*) malloc(sizeof (HeapNode) * NewHeap->Capacity);

    printf("size : %d\n", sizeof (HeapNode)); // HeapNode 안의 Data 는 int 이므로 4 (바이트)

    return NewHeap;
}

// 힙 제거
void HEAP_Destroy(Heap* H)
{
    free(H->Nodes);
    free(H);
}

// 삽입
void HEAP_Insert(Heap* H, ElementType NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    // UsedSize 가 Capacity 에 도달하면 Capaity 를 두배 늘려줌
    if (H->UsedSize == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*) realloc(H->Nodes, sizeof (HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    // 후속 처리
    // 삽입하려는 노드 > 부모 노드가 될 때까지 반복
    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        // 삽입하려는 노드 < 부모 노드일 때 둘의 자리를 바꿔줌
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

// 노드 자리 바꾸기
void HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
    int CopySize = sizeof (HeapNode);
    HeapNode* Temp = (HeapNode*) malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize); // Temp 에 Index1 의 값을 복사함
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize); // 기존 Index1 에 Index2 의 값을 복사함
    memcpy(&H->Nodes[Index2], Temp, CopySize);  // 기존 Index2 에 Temp 의 값을 복사함

    free(Temp);
}

// 최솟값 삭제
void HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    // Root 에 최솟값 저장
    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memset(&H->Nodes[0], 0, sizeof (HeapNode)); // Root 메모리 블럭에 0 할당

    H->UsedSize--;

    // 힙 최고 깊이 가장 오른쪽에 있는 노드를 뿌리 노드로 옮겨옴
    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    // 힙 순서 속성을 만족할 때까지 자식 노드와의 교환을 반복함
    while ( 1 )
    {
        int SelectedChild = 0;

        // LeftPosition 이 전체 크기 보다 같거나 커졌을 때 break
        if ( LeftPosition >= H->UsedSize )
            break;

        // LeftPosition 은 전체 크기 인덱스 범위 이내인데, RightPosition 이 전체 크기 보다 같거나 커졌을 때 -> 오른쪽 자식 노드가 없다는 뜻
        if ( RightPosition >= H->UsedSize )
        {
            SelectedChild = LeftPosition;
        }
        else {
            // LeftPosition, RightPosition 모두 인덱스 범위 이내

            // 왼쪽 자식 > 오른쪽 자식일 때, 작은 쪽인 오른쪽이 swap 의 대상
            if ( H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
                SelectedChild = RightPosition;
            // 왼쪽 자식 < 오른쪽 자식일 때, 작은 쪽인 왼쪽 swap 의 대상
            else
                SelectedChild = LeftPosition;
        }

        // 바꾸는 대상이 되는 노드의 값 < 부모 노드 값일 때 자리를 바꿔준다
        if ( H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data )
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition  = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    // UsedSize 가 Capacity 의 절반을 차지하지 못하면 사이즈를 줄여줌
    if ( H->UsedSize < ( H->Capacity / 2 ) )
    {
        H->Capacity /= 2;
        H->Nodes = (HeapNode*) realloc( H->Nodes, sizeof( HeapNode ) * H->Capacity );
    }
}

// 부모 노드의 인덱스 가져오기
int HEAP_GetParent(int Index)
{
    // k번 인덱스에 위치한 노드의 부모 노드가 위치한 인덱스: (k - 1) / 2 의 몫
    return (int) ((Index - 1) / 2);
}

// 왼쪽 자식 노드의 인덱스 가져오기
int HEAP_GetLeftChild(int Index)
{
    // k번 인덱스에 위치한 노드의 양쪽 자식 노드들이 위치한 인덱스
    // 왼쪽: 2k + 1
    // 오른쪽: 2k + 2
    return (2 * Index) + 1;
}

// 힙 출력
void HEAP_PrintNodes(Heap* H)
{
    int i = 0;
    for (i=0; i < H->UsedSize; i++)
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}
