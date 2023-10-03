// library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "stack.h"

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

// praprak
void CreateEmpty(Stack *S){Top(*S) = Nil;}boolean IsEmpty(Stack S){return (Top(S) == Nil);}boolean IsFull(Stack S){return (Top(S) == MaxEl-1);}void Push(Stack *S, infotype X){Top(*S)++; InfoTop(*S) = X;} void Pop(Stack *S, infotype *X){*X = InfoTop(*S); Top(*S)--; }