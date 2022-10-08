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

int fimJogo(int r, char jogo[3][3], char user){
    int i;

    //VALIDAÇÃO PARA SABER SE EXISTE ALGUMA LINHA, COLUNA OU DIAGONAL DE MESMO VALOR
    for (i = 0; i < 3; i++){
        if (jogo[i][0] == user && jogo[i][1] == user && jogo[i][2] == user){
            return 1;
        }
    }
    for (i = 0; i < 3; i++){
        if (jogo[0][i] == user && jogo[1][i] == user && jogo[2][i] == user){
            return 1;
        }
    }
    if (jogo[0][0] == user && jogo[1][1] == user && jogo[2][2] == user){
        return 1;
    }
    if (jogo[2][0] == user && jogo[1][1] == user && jogo[0][2] == user){
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
    int fim_jogo_x = 0, fim_jogo_o = 0, rodada=0;
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
        fim_jogo_x = fimJogo(rodada, jogo, 'X');
        fim_jogo_o = fimJogo(rodada, jogo, 'O');
    }while(!fim_jogo_x && !fim_jogo_o);

    printJogo(jogo); 

    if (fim_jogo_o){
        printf("\nGANHOU [O]!");
    }else if (fim_jogo_x){
        printf("\nGANHOU [X]!");
    }else{
        printf("\nNINGUEM GANHOU!");
    }
    printf("\nFIM DE JOGO!");

    return 0;
}