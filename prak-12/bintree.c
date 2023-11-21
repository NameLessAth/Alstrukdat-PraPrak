#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bintree.h"
#define max(a, b) ((a < b) ? b : a)
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

void InfLoop(){
    while(true){
    }
}

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree){
    BinTree baru = newTreeNode(root); if (baru != NULL){
        LEFT(baru) = left_tree; RIGHT(baru) = right_tree; 
    } return baru;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val){
    Address p = (Address) malloc(sizeof(ElType)); ROOT(p) = val; LEFT(p) = NULL; RIGHT(p) = NULL; return p;
}

void deallocTreeNode(Address p){
    free(p);
}

boolean isTreeEmpty(BinTree p){
    return (p == NULL);
}

boolean isOneElmt(BinTree p){
    if (!isTreeEmpty(p)) return ((LEFT(p) == NULL)&&(RIGHT(p) == NULL));
    else return false;
}

boolean isUnerLeft(BinTree p){
    return ((!isTreeEmpty(p)) && (RIGHT(p) == NULL) && (LEFT(p) != NULL));
}

boolean isUnerRight(BinTree p){
    return ((!isTreeEmpty(p)) && (LEFT(p) == NULL) && (RIGHT(p) != NULL));
}

boolean isBinary(BinTree p){
    return ((!isTreeEmpty(p)) && (RIGHT(p) != NULL) && (LEFT(p) != NULL));
}

void printPreorder(BinTree p){
    printf("("); if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    } printf(")");
}

void printInorder(BinTree p){
    printf("("); if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    } printf(")");
}

void printPostorder(BinTree p){
    printf("("); if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    } printf(")");
}

void printSpace(int n){
    while(n--) printf(" ");
}

void printTreeSp(BinTree p, int indentNow, int indentStart){
    if (!isTreeEmpty(p)){
        printSpace(indentNow); printf("%d\n", ROOT(p));
        printTreeSp(LEFT(p), (indentNow+indentStart), indentStart);
        printTreeSp(RIGHT(p), (indentNow+indentStart), indentStart);
    }
}

void printTree(BinTree p, int h){
    printTreeSp(p, 0, h);
}



// int main(){
//     BinTree bt, left, right, leftpreq, rightpreq; 
//     left = newTreeNode(6); right = newTreeNode(9);
//     CreateTree(69, left, right, &leftpreq); 
//     CreateTree(96, right, left, &rightpreq);
//     CreateTree(6996, NULL, rightpreq, &bt);
//     printPostorder(bt); endl;
//     if (isUnerRight(bt)) printf("true true i agree\n");
//     else printf("false false i disagree\n");
// }