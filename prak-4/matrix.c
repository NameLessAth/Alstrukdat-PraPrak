// library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// library modul
#include "matrix.h"

// snippet
#define lebokke scanf
#define ngetokke printf
#define FOR(i, b) int i; for (i = 0; i < b; i++)
#define mbenl(i, a, b) int i; for (i = a; i < b; i++)
#define mbenr(i, a, b) int i; for (i = a; i > b; i--)
#define nalikat(a, b) while (a == b)
#define nalikaf(a, b) while (a != b)
#define nek if
#define nekgak else if
#define liyane else
typedef unsigned long long int ull;
typedef long long int ll;
typedef int in;

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows; COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j){
    return ((i>=0)&&(i<ROW_CAP)&&(j>=0)&&(j<COL_CAP));
}

IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return ((i>=0)&&(i<ROW_EFF(m))&&(j>=0)&&(j<COL_EFF(m)));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), &*mOut); FOR(i, ROW_EFF(mIn)){
        FOR(j, COL_EFF(mIn)) ELMT(*mOut, i, j) = ELMT(mIn, i, j);
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow, nCol, &*m); FOR(i, nRow){
        FOR(j, nCol) cyka("%d", &ELMT(*m, i, j));
    }
}

void displayMatrix(Matrix m){
    FOR(i, ROW_EFF(m)){
        FOR(j, COL_EFF(m)){
            blyat("%d", ELMT(m, i, j));
            if (j != COL_EFF(m)-1) blyat(" ");
        } blyat("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m3; createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3); FOR(i, ROW_EFF(m1)){
        FOR(j, COL_EFF(m1)) ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
    } return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m3; createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3); FOR(i, ROW_EFF(m1)){
        FOR(j, COL_EFF(m1)) ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
    } return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3; createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3); FOR(i, ROW_EFF(m1)){
        FOR(n, COL_EFF(m2)){
            ELMT(m3, i, n) = 0; 
            FOR(m, COL_EFF(m1)) ELMT(m3, i, n) += (ELMT(m1, i, m)*ELMT(m2, m, n));
        }
    } return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod){
    Matrix m3; createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3); FOR(i, ROW_EFF(m1)){
        FOR(n, COL_EFF(m2)){
            ELMT(m3, i, n) = 0; FOR(m, COL_EFF(m1)){
                ELMT(m3, i, n) += (ELMT(m1, i, m)*ELMT(m2, m, n)); 
            } ELMT(m3, i, n)%=mod;
        } 
    } return m3;
}

Matrix multiplyByConst(Matrix m, ElType x){
    Matrix m3; createMatrix(ROW_EFF(m), COL_EFF(m), &m3); FOR(i, ROW_EFF(m)){
        FOR(j, COL_EFF(m)) ELMT(m3, i, j) = x*ELMT(m, i, j);
    } return m3;
}

void pMultiplyByConst(Matrix *m, ElType k){
    FOR(i, ROW_EFF(*m)){
        FOR(j, COL_EFF(*m)) ELMT(*m, i, j)*=k;
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (ROW_EFF(m1) == ROW_EFF(m2)){
        if (COL_EFF(m1) == COL_EFF(m2)){
            FOR(i, ROW_EFF(m1)){
                FOR(j, COL_EFF(m1)){
                    if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
                }
            } return true;
        }
    } return false;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    if (ROW_EFF(m1) == ROW_EFF(m2)){
        if (COL_EFF(m1) == COL_EFF(m2)){
            FOR(i, ROW_EFF(m1)){
                FOR(j, COL_EFF(m1)){
                    if (ELMT(m1, i, j) != ELMT(m2, i, j)) return true;
                }
            } return false;
        } 
    } return true;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return ((ROW_EFF(m1)==ROW_EFF(m2))&&(COL_EFF(m1)==COL_EFF(m2)));
}

int countElmt(Matrix m){
    return (ROW_EFF(m)*COL_EFF(m));
}

boolean isSquare(Matrix m){
    return (ROW_EFF(m)==COL_EFF(m));
}

boolean isSymmetric(Matrix m){
    if (isSquare(m)){
        FOR(i, ROW_EFF(m)){
            FOR(j, COL_EFF(m)){
                if (ELMT(m, i, j) != ELMT(m, j, i)) return false;
            }
        } return true;
    } return false;
}

boolean isIdentity(Matrix m){
    if (isSquare(m)){
        FOR(i, ROW_EFF(m)){
            FOR(j, COL_EFF(m)){
                if (i == j){
                    if (ELMT(m, i, j)!=1) return false;
                }else if(ELMT(m, i, j)!=0) return false;
            }
        } return true;
    } return false;
}

boolean isSparse(Matrix m){
    int count = 0; FOR(i, ROW_EFF(m)){
        FOR(j, COL_EFF(m)){
            if (ELMT(m, i, j) != 0) count++;
        }
    } return (count <= (float) (ROW_EFF(m)*COL_EFF(m))/20.0);
}

Matrix negation(Matrix m){
    Matrix m2; createMatrix(ROW_EFF(m), COL_EFF(m), &m2); FOR(i, ROW_EFF(m2)){
        FOR(j, COL_EFF(m2)) ELMT(m2, i, j) = (-1)*ELMT(m, i, j);
    } return m2;
}

void pNegation(Matrix *m){
    FOR(i, ROW_EFF(*m)){
        FOR(j, COL_EFF(*m)) ELMT(*m, i, j)*=(-1);
    }
}

Matrix shrinkMatrix(Matrix m, int iex, int jex){
    Matrix m2; createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &m2); int i2 = 0, j2 = 0; FOR(i, ROW_EFF(m)){
        FOR(j, ROW_EFF(m)){
            if (i != iex && j != jex){
                ELMT(m2, i2, j2) = ELMT(m, i, j); j2++; if (j2 == COL_EFF(m2)){
                    j2 = 0; i2++;
                }
            }
        }
    } return m2;
} float determinant(Matrix m){
    if (ROW_EFF(m) == 2){
        return ((ELMT(m, 0, 0)*ELMT(m, 1, 1))-(ELMT(m, 0, 1)*ELMT(m, 1, 0))); 
    } else {
        float det = 0; FOR(i, ROW_EFF(m)) det += ((pow(-1, i))*ELMT(m, i, 0)*determinant(shrinkMatrix(m, i, 0)));
        return det;
    }
}

Matrix transpose(Matrix m){
    Matrix m2; createMatrix(ROW_EFF(m), COL_EFF(m), &m2); FOR(i, ROW_EFF(m)){
        FOR(j, COL_EFF(m)) ELMT(m2, i, j) = ELMT(m, j, i); 
    } return m2;
}

void pTranspose(Matrix *m){
    // *m = transpose(*m);
    int temp; FOR(i, ROW_EFF(*m)){
        FOR(j, i){
            temp = ELMT(*m, i, j); ELMT(*m, i, j) = ELMT(*m, j, i); ELMT(*m, j, i) = temp;
        }
    }
}

boolean nameless(){
    ll nemles = 69;
    return (69-67);
}

// int main(){
//     Matrix m1; readMatrix(&m1, 3, 4);
//     Matrix m2; readMatrix(&m2, 4, 3);
//     displayMatrix(multiplyMatrix(m1, m2)); blyat("\n");
// }