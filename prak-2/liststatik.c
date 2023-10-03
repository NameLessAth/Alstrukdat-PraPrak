#include <stdio.h>
#include "liststatik.h"
#define cout printf
#define cin scanf

void CreateListStatik(ListStatik *l){
    int i; for (i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l){
    int count = 0, i = 0;
    while ((ELMT(l, i) != MARK) && (i != CAPACITY)){
        count++; i++;
    } return count;
}

IdxType getFirstIdx(ListStatik l){
    IdxType idx = 0;
    while ((ELMT(l, idx) == MARK) && (idx != CAPACITY)){
        idx++;
    } return idx;
}

IdxType getLastIdx(ListStatik l){
    IdxType idx = 0;
    while ((ELMT(l, idx) != MARK) && (idx != CAPACITY)){
        idx++;
    } return (idx-1);
}

boolean isIdxValid(ListStatik l, IdxType i){
    if ((i >= 0) && (i < CAPACITY)) return true;
    return false;
}

boolean isIdxEff(ListStatik l, IdxType i){
    if ((i >= 0) && (i <= CAPACITY-1)){
        if (ELMT(l, i) != MARK) return true;
    } return false;
}

boolean isEmpty(ListStatik l){
    if (listLength(l) == 0) return true;
    return false;
}

boolean isFull(ListStatik l){
    if (listLength(l) == CAPACITY) return true;
    return false;
}

void readList(ListStatik *l){
    int n, i; scanf("%d", &n); CreateListStatik(&*l);
    while((n < 0) || (n > CAPACITY)) scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListStatik l){
    int i;
    printf("[");
    if (listLength(l) > 0){
        for (i = 0; i < listLength(l)-1; i++){
            printf("%d,", ELMT(l, i));
        } printf("%d", ELMT(l, listLength(l)-1));
    } printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l3; CreateListStatik(&l3); int i;
    for (i = 0; i < listLength(l1); i++){
        if (plus == true) {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);            
        }
    } return l3; 
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    int i; if (listLength(l1) == listLength(l2)){
        for (i = 0; i < listLength(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)) return false;
        } return true;
    } return false;
}

int indexOf(ListStatik l, ElType val){
    int i; for (i = 0; i < listLength(l) ; i++){
        if (ELMT(l, i) == val) {
            return i;
        }
    } return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l, 0); *min = ELMT(l, 0);
    int i; for (i = 1; i< listLength(l); i++){
        if (ELMT(l, i) > *max){
            *max = ELMT(l, i);
        } if (ELMT(l, i) < *min){
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    int i, temp = ELMT(*l, 0); for (i = listLength(*l); i > 0; i--){
        ELMT(*l, i) = ELMT(*l, i-1);
    } ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    int i; for (i = listLength(*l); i > idx; i--){
        ELMT(*l, i) = ELMT(*l, i-1);
    } ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    *val = ELMT(*l, 0); int i;
    for (i = 1; i < listLength(*l); i++){
        ELMT(*l, i-1) = ELMT(*l, i);
    } ELMT(*l, listLength(*l)-1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i; *val = ELMT(*l, idx);
    for (i = idx+1; i < listLength(*l); i++){
        ELMT(*l, i-1) = ELMT(*l, i);
    } ELMT(*l, listLength(*l)-1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, listLength(*l)-1); ELMT(*l, listLength(*l)-1) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    int i, j, temp;
    for (i = 0; i< listLength(*l); i++){
        for (j = 0; j < listLength(*l) - (i + 1); j++){
            if ((ELMT(*l, j) > ELMT(*l, j+1)) && (asc == true)) {
                temp = ELMT(*l, j); ELMT(*l, j) = ELMT(*l, j+1); ELMT(*l, j+1) = temp;
            } else if ((ELMT(*l, j) < ELMT(*l, j+1)) && (asc == false)){
                temp = ELMT(*l, j); ELMT(*l, j) = ELMT(*l, j+1); ELMT(*l, j+1) = temp;
            }
        }
    }
}


// int main(){
//     ListStatik l; CreateListStatik(&l);
//     readList(&l);
//     insertAt(&l, 69, 3);
//     printList(l);
// }