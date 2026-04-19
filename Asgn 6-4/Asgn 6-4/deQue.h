#pragma once

typedef char element;         // 데크 원소(element)의 자료형을 char로 정의

typedef struct DQNode {       // 이중 연결 리스트 데크의 노드 구조 정의
    element data;
    struct DQNode* llink;     // 왼쪽 링크 (이전 노드)
    struct DQNode* rlink;     // 오른쪽 링크 (다음 노드)
} DQNode;

typedef struct {              // 데크에서 사용하는 포인터 front와 rear 정의
    DQNode* front, * rear;
} DQueueType;

DQueueType* createdQue(void);
int isDeQEmpty(DQueueType* DQ);
void insertFront(DQueueType* DQ, element item);
void insertRear(DQueueType* DQ, element item);
element deleteFront(DQueueType* DQ);
element deleteRear(DQueueType* DQ);
element peekFront(DQueueType* DQ);
element peekRear(DQueueType* DQ);
void printDQ(DQueueType* DQ);