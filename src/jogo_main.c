#include <stdio.h>
#include <stdlib.h>

//ELEMENTO DA MATRIZ----------------------
typedef struct {
    int i_val;
    int j_val;
} tElementoMatriz;

tElementoMatriz initElementoMatriz(){
    tElementoMatriz m;
    char linha;
    int coluna;

    printf("Escolha uma Linha: ");
    scanf(" %c", &linha);
    printf("Escolha uma Coluna: ");
    scanf("%d", &coluna);

    if(linha == 'A'){
        m.i_val = 0;
    }else if (linha == 'B'){
        m.i_val = 1;
    }else if (linha == 'C'){
        m.i_val = 2;
    }

    m.j_val = coluna - 1;

    return m;
}
//----------------------------------------

void printJogo(char jogo[3][3]){
    int i, j;
    char linhas[3] = {'A', 'B', 'C'};

    system("cls");

    printf("    1   2   3\n");
    for (i = 0; i < 3; i++){
        printf("%c ", linhas[i]);
        for (j = 0; j < 3; j++){
            printf("| %c ", jogo[i][j]);
        }
        printf("|\n");
    } 
}

int fimJogo(int r, char jogo[3][3]){
    int i;

    //VALIDAÇÃO PARA SABER SE EXISTE ALGUMA LINHA, COLUNA OU DIAGONAL DE MESMO VALOR
    for (i = 0; i < 3; i++){
        if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2]){
            return 1;
        }
    }
    for (i = 0; i < 3; i++){
        if (jogo[0][i] == jogo[1][i] && jogo[1][i] == jogo[2][i]){
            return 1;
        }
    }
    if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2]){
        return 1;
    }
    if (jogo[2][0] == jogo[1][1] && jogo[1][1] == jogo[0][2]){
        return 1;
    }

    //SE O NÚMERO DE RODADAS É 9 NÃO HÁ MAIS MOVIMENTOS POSSÍVEIS
    if(r == 9){
        return 1;
    }

    return 0;
}

int main(){

    char jogo [3] [3];
    

    tElementoMatriz elemento;

    int i, j;
    int fim_jogo = 0, rodada=0;
    char jogador = 'X';

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }

    do{
        
        printJogo(jogo);

        elemento = initElementoMatriz();
        jogo[elemento.i_val][elemento.j_val] = jogador;

        if (jogador == 'X'){
            jogador = 'O';
        }else{
            jogador = 'X';
        }

        rodada++;
        fim_jogo = fimJogo(rodada, jogo);
    }while(!fim_jogo);

    printJogo(jogo); 

    printf("\nFIM DE JOGO!");

    return 0;
}