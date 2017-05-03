#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(N) (N)->info
#define Next(N) (N)->next

#define Front(Q) (Q).Front
#define Rear(Q) (Q).Rear

#define Top(S) (S).top
typedef int infotype;
typedef struct tNode *address;
typedef struct tNode {
    infotype info;
    address next;
} node;

typedef struct {
    address top;
} Stack;

typedef struct {
    address Front;
    address Rear;
} Queue;

void CreateStack(Stack *s);
address Alokasi(infotype n);
void Push(Stack *s, infotype n);
infotype Pop(Stack *s);

void CreateQueue(Queue *Q);
void EnQueue(Queue *Q, infotype n);
infotype DeQueue(Queue *Q);
#endif // STACK_H_INCLUDED
