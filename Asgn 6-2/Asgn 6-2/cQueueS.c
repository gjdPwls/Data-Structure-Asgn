#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

// 원형 큐 생성
QueueType* createCQueue() {
    QueueType* cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = 0;  // front 초깃값 설정
    cQ->rear = 0;   // rear 초깃값 설정
    return cQ;
}

// 원형 큐 공백 상태 검사
int isCQueueEmpty(QueueType* cQ) {
    if (cQ->front == cQ->rear) {
        printf(" Circular Queue is empty! ");
        return 1;
    }
    else return 0;
}

// 원형 큐 포화 상태 검사
int isCQueueFull(QueueType* cQ) {
    if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
        printf(" Circular Queue is full! ");
        return 1;
    }
    else return 0;
}

// 원형 큐 삽입 연산
void enCQueue(QueueType* cQ, element item) 
{
    if (isCQueueFull(cQ)) 
        return;
    else 
    {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

// 원형 큐 삭제 연산
element deCQueue(QueueType* cQ) 
{
    if (isCQueueEmpty(cQ)) return;
    else 
    {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

// 원형 큐 피크 연산
element peekCQ(QueueType* cQ) 
{
    if (isCQueueEmpty(cQ)) exit(1);
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

// 원형 큐 출력 연산
void printCQ(QueueType* cQ) 
{
    int i, first, last;
    first = (cQ->front + 1) % cQ_SIZE;
    last = (cQ->rear + 1) % cQ_SIZE;
    printf(" Circular Queue : [");
    i = first;
    while (i != last) 
    {
        printf("%3c", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf(" ] ");
}