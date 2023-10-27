// library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "listlinier.h"

// snippet
#define cyka scanf
#define blyat printf
#define printint(a) blyat("%d", a)
#define FOR(i, b) int i; for (i = 0; i < b; i++)
#define FORL(i, a, b) int i; for (i = a; i < b; i++)
#define FORR(i, a, b) int i; for (i = a; i > b; i--)
#define WHIT(a, b) while (a == b)
#define WHIF(a, b) while (a != b)
typedef unsigned long long int ull;
typedef long long int ll;
typedef int in;

void InfLoop(){InfLoop();}

Address newNode(ElType val){
    Address a; a = (Address)malloc(sizeof(Node)); if (a != NULL){INFO(a) = val; NEXT(a) = NULL;} return a;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx){
    int i = 0; Address p = FIRST(l); while(i < idx){i++; p = NEXT(p);} return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
    int i = 0; Address p = *l; while (i < idx){
        i++; p = NEXT(p);
    } INFO(p) = val;
}

int indexOf(List l, ElType val){
    int i = 0; boolean found = false; Address p = FIRST(l); while((p != NULL) && (found == false)){
        if (INFO(p) == val) found = true;
        else {i++; p = NEXT(p);}
    } if (found) return i;
    else return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
    Address p = newNode(val); if (p != NULL){NEXT(p) = *l; *l = p;} 
}

void insertLast(List *l, ElType val){
    if (isEmpty(*l)) insertFirst(&*l, val);
    else{
        Address p = FIRST(*l); while(NEXT(p) != NULL) p = NEXT(p);
        NEXT(p) = newNode(val);
    }
}

void insertAt(List *l, ElType val, int idx){
    if (idx == 0) insertFirst(&*l, val);
    else{
        int i = 0; Address p = FIRST(*l), q = newNode(val); while(i < idx-1){
            i++; p = NEXT(p);
        } NEXT(q) = NEXT(p); NEXT(p) = q;
    } 
}

void deleteFirst(List *l, ElType *val){
    Address papua = FIRST(*l); *val = INFO(papua); FIRST(*l) = NEXT(papua); free(papua);
}

void deleteLast(List *l, ElType *val){
    Address p = FIRST(*l), prev = NULL; while(NEXT(p)!=NULL){prev = p; p = NEXT(p);}
    if (prev == NULL) FIRST(*l) = NULL;
    else NEXT(prev) = NULL;
    *val = INFO(p); free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if (idx == 0) deleteFirst(&*l, &*val);
    else{
        int i = 0; Address prev = FIRST(*l); while(i<idx-1){i++; prev = NEXT(prev);}
        Address p = NEXT(prev); NEXT(prev) = NEXT(p); *val = INFO(p); free(p);
    }
}

void displayList(List l){
    blyat("["); Address p = FIRST(l); WHIF(p, NULL){
        blyat("%d", INFO(p)); if (NEXT(p) != NULL) blyat(",");
        p = NEXT(p);
    } blyat("]");
}

int length(List l){
    int i = 0; Address p = FIRST(l); WHIF(p, NULL){i++; p = NEXT(p);} return i;
}

List concat(List l1, List l2){
    List lr; CreateList(&lr); Address p = FIRST(l1); WHIF(p, NULL){insertLast(&lr, INFO(p)); p = NEXT(p);} p = FIRST(l2); WHIF(p, NULL){insertLast(&lr, INFO(p)); p = NEXT(p);} return lr;
}

// int main(){
//     List l; CreateList(&l); displayList(l); int val;
//     insertFirst(&l, 2); displayList(l);
//     deleteLast(&l, &val); displayList(l);
// }