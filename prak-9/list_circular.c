#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list_circular.h"
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


boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}

void CreateList(List *l){
    FIRST(*l) = NULL; 
}

Address allocate(ElType val){
    Address p = (Address) malloc(sizeof(ElmtList)); INFO(p) = val; NEXT(p) = NULL; return p;
}

void deallocate(Address P){
    free(P);
}

Address search(List l, ElType val){
    if (isEmpty(l)) return NULL;
    else{
        Address p = FIRST(l); boolean notfound = true; while((NEXT(p) != FIRST(l)) && (notfound)){
            if (INFO(p) == val) notfound = false; 
            else p = NEXT(p);
        } if (INFO(p) == val) notfound = false; 

        if (notfound) return NULL; 
        else return p;
    } 
}

boolean addrSearch(List l, Address p){
    Address q = FIRST(l); boolean notfound = true; while((NEXT(q) != FIRST(l)&&(notfound))){
        if (q == p) notfound = false;
        else q = NEXT(q);
    } if (notfound) return false; else return true;
}

void insertFirst(List *l, ElType val){
    Address new = allocate(val);
    if (isEmpty(*l)){
        FIRST(*l) = new;
        NEXT(new) = new;
    } else{
        Address p = FIRST(*l); while (NEXT(p) != FIRST(*l)) p = NEXT(p); 
        NEXT(p) = new; NEXT(new) = FIRST(*l); FIRST(*l) = new;
    }
}

void insertLast(List *l, ElType val){
    if (isEmpty(*l)) insertFirst(&*l, val);
    else{
        Address new = allocate(val); Address p = FIRST(*l); while (NEXT(p) != FIRST(*l)) p = NEXT(p); 
        NEXT(p) = new; NEXT(new) = FIRST(*l);
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l); *val = INFO(p); 
    if (NEXT(p) == FIRST(*l)){
        deallocate(p); CreateList(&*l);
    } else{
        Address q = p; while (NEXT(p) != FIRST(*l)) p = NEXT(p); 
        FIRST(*l) = NEXT(q); NEXT(p) = NEXT(q); deallocate(q);
    }
}

void deleteLast(List *l, ElType *val){
    Address p = FIRST(*l), q = NULL;
    if (NEXT(p) == FIRST(*l)) deleteFirst(&*l, &*val);
    else{
        while (NEXT(p) != FIRST(*l)){
            q = p;
            p = NEXT(p);
        } NEXT(q) = FIRST(*l); *val = INFO(p); deallocate(p);
    }
}

void displayList(List l){
    blyat("["); Address p = FIRST(l); int tbp; if (p != NULL){
        while(NEXT(p) != FIRST(l)){
            blyat("%d,", INFO(p));
            p = NEXT(p);
        } blyat("%d", INFO(p));
    } blyat("]");
}

// int main(){
//     List l; CreateList(&l); int dec;
//     insertFirst(&l, 3); insertLast(&l, 69); displayList(l); 
//     deleteFirst(&l, &dec); displayList(l); 
//     deleteFirst(&l, &dec); displayList(l);
// }