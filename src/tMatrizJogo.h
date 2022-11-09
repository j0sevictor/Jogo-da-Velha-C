#include "tElementoMatriz.h"

//MATRIZ DO JOGO---------------------------
typedef struct {
    char matrizJogo[3][3];
} tMatrizJogo;

tMatrizJogo initMatrizJogo(){
    tMatrizJogo mj;
    int i, j;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            mj.matrizJogo[i][j] = ' ';
        }
    }

    return mj;
}

int existeNaMatriz(tMatrizJogo matriz, tElementoMatriz elemento){
    return matriz.matrizJogo[elemento.i_val][elemento.j_val] != ' ';
}
//-------------------------------------
