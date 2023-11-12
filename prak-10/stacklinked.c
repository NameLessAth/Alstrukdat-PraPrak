#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stacklinked.h"
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
#define endl blyat("\n")
typedef int in;
typedef long long int ll;
typedef unsigned long long int ull;


Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(ElType)); INFO(p) = x; NEXT(p) = NIL; return p;
}

boolean isEmpty(Stack s){
    return (ADDR_TOP(s) == NIL);
}

int length(Stack s){
    Address p = ADDR_TOP(s); int i = 0;
    while(p != NIL){
        i++; p = NEXT(p);
    } return i;
}

void CreateStack(Stack *s){
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s){
    blyat("["); Address p = ADDR_TOP(s); while(p != NULL){
        blyat("%d", INFO(p)); if (NEXT(p) != NIL) blyat(",");
        p = NEXT(p);
    } blyat("]");
}

void push(Stack *s, ElType x){
    Address new = newNode(x), p = ADDR_TOP(*s); NEXT(new) = p; ADDR_TOP(*s) = new; 
}

void pop(Stack *s, ElType *x){
    Address p = ADDR_TOP(*s); *x = INFO(p); ADDR_TOP(*s) = NEXT(p); free(p);
}

// int main(){
//     Stack s; CreateStack(&s); DisplayStack(s); endl;
//     push(&s, 79); DisplayStack(s); endl;
//     push(&s, 79); DisplayStack(s); endl;   
// }