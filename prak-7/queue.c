// library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "queue.h"

// snippet
#define cyka scanf
#define blyat printf
#define FOR(i, b) int i; for (i = 0; i < b; i++)
#define FORL(i, a, b) int i; for (i = a; i < b; i++)
#define FORR(i, a, b) int i; for (i = a; i > b; i--)
#define WHIT(a, b) while (a == b)
#define WHIF(a, b) while (a != b)
typedef unsigned long long int ull;
typedef long long int ll;
typedef int in;

void InfLoop(){
    while (true){
        continue;
    }
}

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF; IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q){
    return ((IDX_TAIL(q)+1)%CAPACITY == IDX_HEAD(q));
}

int length(Queue q){
    if (isEmpty(q)) return 0;
    int panjang = IDX_TAIL(q); if (panjang < IDX_HEAD(q)) panjang += CAPACITY;
    return (panjang-IDX_HEAD(q)+1);
}

void enqueue(Queue *q, ElType val){
    IDX_TAIL(*q)++; IDX_TAIL(*q)%=CAPACITY; if (IDX_HEAD(*q) == IDX_UNDEF) IDX_HEAD(*q) = IDX_TAIL(*q);
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) CreateQueue(&*q);
    else IDX_HEAD(*q) = (IDX_HEAD(*q)+1)%CAPACITY;
}

void displayQueue(Queue q){
    blyat("["); int i, val; while (!isEmpty(q)){
        dequeue(&q, &val);
        if (isEmpty(q)) blyat("%d", val);
        else blyat("%d,", val);
    } blyat("]\n");
}