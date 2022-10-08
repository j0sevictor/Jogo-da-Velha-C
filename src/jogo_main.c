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

void printJogo(){
    printf("");
}

int fimJogo(int r){
    if(r == 9){
        return 1;
    }
    return 0;
}

int main(){

    char jogo [3] [3];
    char linhas[3] = {'A', 'B', 'C'};

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
        
        system("cls");

        printf("    1   2   3\n");
        for (i = 0; i < 3; i++){
            printf("%c ", linhas[i]);
            for (j = 0; j < 3; j++){
                printf("| %c ", jogo[i][j]);
            }
            printf("|\n");
        }   

        elemento = initElementoMatriz();
        jogo[elemento.i_val][elemento.j_val] = jogador;

        if (jogador == 'X'){
            jogador = 'O';
        }else{
            jogador = 'X';
        }

        rodada++;
        fim_jogo = fimJogo(rodada);
    }while(!fim_jogo);

    system("cls");
    
    printf("    1   2   3\n");
    for (i = 0; i < 3; i++){
        printf("%c ", linhas[i]);
        for (j = 0; j < 3; j++){
            printf("| %c ", jogo[i][j]);
        }
        printf("|\n");
    } 

    printf("\nFIM DE JOGO!");

    return 0;
}