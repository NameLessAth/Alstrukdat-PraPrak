#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S){
    if ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59)) {
        return true;
    } return false;
}

void CreateTime(TIME *T, int HH, int MM, int SS){
    Hour(*T) = HH; Minute(*T) = MM; Second(*T) = SS;
}

void BacaTIME(TIME *T){
    int a, b, c;
    while (true){
        scanf("%d %d %d", &a, &b, &c);
        if (IsTIMEValid(a, b, c)){
            Hour(*T) = a; Minute(*T) = b; Second(*T) = c;
            break;
        }
    }
}

void TulisTIME(TIME T){
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik(TIME T){
    return (3600*Hour(T) + 60*Minute(T) + Second(T));
}

TIME DetikToTIME(long N){
    TIME Timeaksen; N %= 86400;
    int HH = N / 3600; N %= 3600;
    int MM = N / 60; N %= 60;
    int SS = N;
    Hour(Timeaksen) = HH; Minute(Timeaksen) = MM; Second(Timeaksen) = SS;
    return Timeaksen;
}

boolean TEQ(TIME T1, TIME T2){
    if (TIMEToDetik(T1) == TIMEToDetik(T2)) return true;
    return false;
}

boolean TNEQ(TIME T1, TIME T2){
    if (TIMEToDetik(T1) == TIMEToDetik(T2)) return false;
    return true;
}

boolean TLT(TIME T1, TIME T2){
    if (TIMEToDetik(T1) < TIMEToDetik(T2)) return true;
    return false;
}

boolean TGT(TIME T1, TIME T2){
    if (TIMEToDetik(T1) < TIMEToDetik(T2)) return false;
    return true;
}

TIME NextDetik(TIME T){
    return DetikToTIME(TIMEToDetik(T)+1);
}

TIME NextNDetik(TIME T, int N){
    return DetikToTIME(TIMEToDetik(T)+N);
}

TIME PrevDetik(TIME T){
    long a = TIMEToDetik(T)-1;
    while (a < 0){
        a += 86400;
    } return DetikToTIME(a);
}

TIME PrevNDetik(TIME T, int N){
    long a = TIMEToDetik(T)-N;
    while (a < 0){
        a += 86400;
    } return DetikToTIME(a);
}

long Durasi(TIME TAw, TIME TAkh){
    if (TIMEToDetik(TAw) < TIMEToDetik(TAkh)){
        return TIMEToDetik(TAkh)-TIMEToDetik(TAw);
    } else {
        return 86400 - (TIMEToDetik(TAw) - TIMEToDetik(TAkh));
    }

}
