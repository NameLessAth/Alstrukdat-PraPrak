// standard library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "wordmachine.h"

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

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    WHIT(currentChar, BLANK) ADV();
}

void STARTWORD(){
    START(); IgnoreBlanks();
    if (currentChar == MARK) EndWord = true;
    else{
        EndWord = false; CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar == MARK) EndWord = true;
    else{
        CopyWord(); IgnoreBlanks();
    }
}

void CopyWord(){
    in i = 0;
    while((currentChar != MARK) && (currentChar != BLANK)){
        if (i < NMax){
            currentWord.TabWord[i] = currentChar; i++;
        } ADV();
    } currentWord.Length = i;
}

