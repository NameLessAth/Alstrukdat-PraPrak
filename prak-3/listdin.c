// library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "listdin.h"

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


void CreateListDin(ListDin *l, int capacity){
    NEFF(*l) = 0; CAPACITY(*l) = capacity; BUFFER(*l) = (ElType*)malloc(capacity*sizeof(ElType));
}

void dealocateList(ListDin *l){
    NEFF(*l) = 0; CAPACITY(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return 0;
}

IdxType getLastIdx(ListDin l){
    return (NEFF(l)-1);
} 

boolean isIdxValid(ListDin l, IdxType i){
    if ((i < CAPACITY(l)) && (i >= 0)) return true;
    return false;
}

boolean isIdxEff(ListDin l, IdxType i){
    if ((i < NEFF(l)) && (i >= 0)) return true;
    return false;
}

boolean isEmpty(ListDin l){
    if (NEFF(l) == 0) return true;
    return false;
}

boolean isFull(ListDin l){
    if (NEFF(l) == CAPACITY(l)) return true;
    return false;
}

void readList(ListDin *l){
    int val, N = -1;
    while ((N < 0) || (N > CAPACITY(*l))) cyka("%d", &N);
    FOR(i, N){
        cyka("%d", &ELMT(*l, i)); NEFF(*l)++;
    } 
}

void printList(ListDin l){
    blyat("["); if (NEFF(l) != 0){
        FOR(i, NEFF(l)-1) blyat("%d,", ELMT(l, i));
        blyat("%d", ELMT(l, NEFF(l)-1));
    } blyat("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l3; CreateListDin(&l3, (CAPACITY(l1))); NEFF(l3) = NEFF(l1); FOR(i, NEFF(l3)){
        if (plus == true) ELMT(l3, i) = (ELMT(l1, i) + ELMT(l2, i));
        else ELMT(l3, i) = (ELMT(l1, i) - ELMT(l2, i));
    } return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){
    if (NEFF(l1) == NEFF(l2)){
        FOR(i, NEFF(l1)){
            if (ELMT(l1, i) != ELMT(l2, i)) return false;
        } return true;
    } return false;
}

IdxType indexOf(ListDin l, ElType val){
    FOR(i, NEFF(l)) if (ELMT(l, i) == val) return i;
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
    *max = ELMT(l, 0); *min = ELMT(l, 0);
    FORL(i, 1, NEFF(l)){
        if (ELMT(l, i) > *max) *max = ELMT(l, i);
        if (ELMT(l, i) < *min) *min = ELMT(l, i);
    } 
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(&*lOut, CAPACITY(lIn)); NEFF(*lOut) = NEFF(lIn);
    FOR(i, NEFF(lIn)) ELMT(*lOut, i) = ELMT(lIn, i);
}

ElType sumList(ListDin l){
    int count = 0; FOR(i, NEFF(l)) count+= ELMT(l, i);
    return count;
}

int countVal(ListDin l, ElType val){
    int count = 0; FOR(i, NEFF(l)){
        if (ELMT(l, i) == val) count++;
    } return count;
}

void sort(ListDin *l, boolean asc){
    int temp; FOR(i, NEFF(*l)){
        FOR(j, (NEFF(*l)-(i+1))){
            if ((ELMT(*l, j) > ELMT(*l, j+1)) && (asc == true)) {
                temp = ELMT(*l, j); ELMT(*l, j) = ELMT(*l, j+1); ELMT(*l, j+1) = temp;
            } else if ((ELMT(*l, j) < ELMT(*l, j+1)) && (asc == false)){
                temp = ELMT(*l, j); ELMT(*l, j) = ELMT(*l, j+1); ELMT(*l, j+1) = temp;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    NEFF(*l)++; ELMT(*l, NEFF(*l)-1) = val;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, NEFF(*l)-1); NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num){
    CAPACITY(*l) -= num;
}

void compressList(ListDin *l){
    CAPACITY(*l) = NEFF(*l);
}

// int main(){
//     ListDin l1; ListDin l2; CreateListDin(&l1, 100); readList(&l1); 
//     copyList(l1, &l2);
//     // l3 = plusMinusList(l1, l2, true); printList(l3);
//     printList(plusMinusList(l1, l2, true));
//     blyat("%d", sumList(l1));
//     return 0;
// }