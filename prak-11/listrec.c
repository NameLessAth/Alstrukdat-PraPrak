#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listrec.h"
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
#define InfLoop() InfLoop()
typedef int in;
typedef long long int ll;
typedef unsigned long long int ull;

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(ElType)); INFO(p) = x; NEXT(p) = NIL; return p;
}

boolean isEmpty(List l){
    return (l == NULL);
}

boolean isOneElmt(List l){
    return (!isEmpty(l) && (NEXT(l)==NULL));
}

ElType head(List l){
    return INFO(l);
}

List tail(List l){
    return (NEXT(l));
}

List konso(List l, ElType e){
    Address new = newNode(e); if (new != NULL){
        Address p = l; NEXT(new) = p; l = new;
    } return l;
}

List konsb(List l, ElType e){
    Address new = newNode(e); if (new != NULL){
        if (isEmpty(l)) return konso(l, e);
        Address p = l; while (NEXT(p) != NULL){ 
            p = NEXT(p);
        } NEXT(p) = new;
    } return l;
}

List copy(List l){
    return l;
}

List concat(List l1, List l2){
    List l3 = copy(l1); Address p = l2; while(p != NULL){
        l3 = konsb(l3, INFO(p)); p = NEXT(p);
    } return l3;
}

int length(List l){
    int i = 0; Address p = l; while(p != NULL){
        i++; p = NEXT(p);
    } return i;
}

boolean isMember(List l, ElType x){
    Address p = l; boolean ada = false; while((p != NIL)&&(!ada)){
        if (INFO(p) == x) ada = true;
        else p = NEXT(p);
    } return ada;
}   

void displayList(List l){
    Address p = l; while(p != NIL){
        blyat("%d\n", INFO(p));
        p = NEXT(p);
    }
}

// int main(){
//     List l1, l2; l1 = NULL; l2 = NULL;
//     l1 = konsb(l1, 22); l1 = konso(l1, 11); konsb(l1, 33);
//     l2 = copy(l1);
//     l1 = konso(l1, 0);
//     displayList(l1);
//     displayList(l2);
// }