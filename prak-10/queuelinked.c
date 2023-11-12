#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queuelinked.h"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int (a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int (a) = (b); (a) < (c); (a)++)
#define FORR(a, b, c) for (int (a) = (b); (a) > (c); (a)--)
#define INF 1000000000000000003
#define WHIT(a, b) while (a == b)
#define WHIF(a, b) while (a != b)
#define cyka scanf
#define blyat printf
typedef int in;
typedef long long int ll;
typedef unsigned long long int ull;

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(ElType)); INFO(p) = x; NEXT(p) = NIL; return p;
}

boolean isEmpty(Queue q){
    return ((ADDR_HEAD(q) == NIL)&&(ADDR_TAIL(q) == NIL));
}

int length(Queue q){
    if (isEmpty(q)) return 0;
    else{
        Address p = ADDR_HEAD(q); int i = 1; while (p != ADDR_TAIL(q)){
            i++; p = NEXT(p);
        } return i;
    }
}

void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NIL; ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q){
    blyat("["); if (!isEmpty(q)){
        Address p = ADDR_HEAD(q); while(p != ADDR_TAIL(q)){
            blyat("%d,", INFO(p)); p = NEXT(p);
        } blyat("%d", INFO(p));
    } blyat("]");
}

void enqueue(Queue *q, ElType x){
    Address new = newNode(x); if (isEmpty(*q)) ADDR_HEAD(*q) = new;
    else{
        Address p = ADDR_TAIL(*q); NEXT(p) = new;
    } ADDR_TAIL(*q) = new;
}

void dequeue(Queue *q, ElType *x){
    Address p = ADDR_HEAD(*q); *x = INFO(p);
    if (length(*q) == 1){
        free(p); CreateQueue(&*q);
    } else{
        ADDR_HEAD(*q) = NEXT(p); free(p);
    }
}
