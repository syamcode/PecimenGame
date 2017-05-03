#include "list.h"
void CreateStack(Stack *s) {
    Top(*s) = Nil;
}

address Alokasi(infotype n) {
    address N;
    N = (address) malloc (sizeof(node));
    if (N!=Nil) {
        Info(N) = n;
        Next(N) = Nil;
    }
    return N;
}

void Push(Stack *s, infotype n) {
    address N = Alokasi(n);
    if (N!=Nil) {
        Next(N) = Top(*s);
        Top(*s) = N;
    }
    else {
        printf("Overflow\n");
    }
}

infotype Pop(Stack *s) {
    address del;
    infotype info;

    del = Top(*s);
    if (del!=Nil) {
        info = Info(del);
        Top(*s) = Next(del);
        free(del);
    }
    else {
        info = -1; //Underflow
    }

    return info;
}

void CreateQueue(Queue *Q) {
    Front(*Q) = Nil;
    Rear(*Q) = Nil;
}

void EnQueue(Queue *Q, infotype n) {
    address N = Alokasi(n);
    if (N!=Nil) {
        if (Rear(*Q)!=Nil) {
            Next(Rear(*Q)) = N;
        }
        else {
            Front(*Q) = N;
        }
        Rear(*Q) = N;
    }
    else {
        printf("Overflow\n");
    }
}

infotype DeQueue(Queue *Q) {
    address del;
    infotype info;

    del = Front(*Q);
    if (del!=Nil) {
        info = Info(del);
        if (Next(del)==Nil) {
            Rear(*Q) = Nil;
        }
        Front(*Q) = Next(del);
        free(del);
    }
    else {
        info = -1; //Underflow
    }

    return info;
}
