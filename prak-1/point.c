#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "point.h"

void CreatePoint(POINT *P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P){
    scanf("%f %f", &Absis(*P), &Ordinat(*P));
}

void TulisPOINT(POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2){
    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))){
        return true;
    } return false;
}

boolean NEQ(POINT P1, POINT P2){
    if ((Absis(P1) != Absis(P2)) && (Ordinat(P1) != Ordinat(P2))){
        return true;
    } return false;
}

boolean IsOrigin(POINT P){
    if ((Absis(P) == 0) && (Ordinat(P) == 0)){
        return true;
    } return false;
}

boolean IsOnSbX(POINT P){
    if (Ordinat(P) == 0){
        return true;
    } return false;

}

boolean IsOnSbY(POINT P){
    if ((Absis(P) == 0)){
        return true;
    } return false;
}

int Kuadran(POINT P){
    if (Ordinat(P) > 0){
        if (Absis(P) > 0) return 1;
        else return 2;
    } else {
        if (Absis(P) < 0) return 3;
        else return 4;
    }
}

POINT NextX(POINT P){
    POINT Paksen;
    Absis(Paksen) = Absis(P)+1;
    Ordinat(Paksen) = Ordinat(P);
    return Paksen;
}

POINT NextY(POINT P){
    POINT Paksen;
    Absis(Paksen) = Absis(P);
    Ordinat(Paksen) = Ordinat(P)+1;
    return Paksen;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY){
    POINT Paksen;
    Absis(Paksen) = Absis(P) + deltaX;
    Ordinat(Paksen) = Ordinat(P) + deltaY;
    return Paksen;
}

POINT MirrorOf(POINT P, boolean SbX){
    POINT Paksen;
    Absis(Paksen) = Absis(P);
    Ordinat(Paksen) = Ordinat(P);
    if (SbX == true){
        Ordinat(Paksen) *= -1;
    } else {
        Absis(Paksen) *= -1;
    } return Paksen;
}

float Jarak0(POINT P){
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}

float Panjang(POINT P1, POINT P2){
    float DeltaX = Absis(P1) - Absis(P2);
    float DeltaY = Ordinat(P1) - Ordinat(P2);
    return sqrt((DeltaX*DeltaX) + (DeltaY*DeltaY));
}

void Geser(POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P){
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX){
    if(SbX){
        Ordinat(*P) *= -1;
    } else {
        Absis(*P) *= -1;
    }
}

void Putar(POINT *P, float Sudut){
    Sudut = Sudut * M_PI / -180.0;
    float x = Absis(*P), y = Ordinat(*P);
    Absis(*P) = (cos(Sudut) * x) + (-1 * sin(Sudut) * y);
    Ordinat(*P) = (sin(Sudut) * x) + (cos(Sudut) * y);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2){
    int a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    int b = Ordinat(P1) - ((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1)) * Absis(P1));
    printf("(%d,%d)",a,b);
}