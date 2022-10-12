#include <stdio.h>
#include <stdlib.h>
#define INDEX_LINHAS 3
#define INDEX_COLUNAS 3

//ELEMENTO DA MATRIZ----------------------
typedef struct {
    int i_val;
    int j_val;
} tElementoMatriz;

tElementoMatriz initElementoMatriz(){
    tElementoMatriz m;
    char linha;
    int coluna;

    //RECEBE O VALOR DA LINHA QUE O USUÁRIO DIGITAR
    while (1){
        printf("Escolha uma Linha: ");
        scanf(" %c", &linha);
        if (linha == 'A' || linha == 'B' || linha == 'C'){
            break;
        }else{
            printf("INVALIDO! TENTE DE NOVO ");
        }
    }
    while (1){
        printf("Escolha uma Coluna: ");
        scanf("%d", &coluna);
        if (coluna >= 1 && coluna <= 3){
            break;
        }else{
            printf("INVALIDO! TENTE DE NOVO ");
        }
    }

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

//MATRIZ DO JOGO
typedef struct {
    char matrizJogo[INDEX_LINHAS][INDEX_COLUNAS];
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

void printJogo(tMatrizJogo jogo){
    int i, j;
    char linhas[3] = {'A', 'B', 'C'};

    system("cls");

    printf("    1   2   3\n");
    for (i = 0; i < 3; i++){
        printf("%c ", linhas[i]);
        for (j = 0; j < 3; j++){
            printf("| %c ", jogo.matrizJogo[i][j]);
        }
        printf("|\n");
    } 
}

int fimJogo(tMatrizJogo jogo, char user){
    int i;

    //VALIDAÇÃO PARA SABER SE EXISTE ALGUMA LINHA, COLUNA OU DIAGONAL DE MESMO VALOR
    for (i = 0; i < 3; i++){
        if (jogo.matrizJogo[i][0] == user && jogo.matrizJogo[i][1] == user && jogo.matrizJogo[i][2] == user){
            return 1;
        }
    }
    for (i = 0; i < 3; i++){
        if (jogo.matrizJogo[0][i] == user && jogo.matrizJogo[1][i] == user && jogo.matrizJogo[2][i] == user){
            return 1;
        }
    }
    if (jogo.matrizJogo[0][0] == user && jogo.matrizJogo[1][1] == user && jogo.matrizJogo[2][2] == user){
        return 1;
    }
    if (jogo.matrizJogo[2][0] == user && jogo.matrizJogo[1][1] == user && jogo.matrizJogo[0][2] == user){
        return 1;
    }

    return 0;
}

int main(){
    tMatrizJogo jogo;
    tElementoMatriz elemento;
    char jogador;
    int fim_jogo, rodada;

    //INICIALIZAÇÃO DOS ELEMENTOS DA MATRIZ DE "jogo"
    jogo = initMatrizJogo();

    //INICIALIZAÇÃO DAS VARIÁVEIS NECESSÁRIAS
    jogador = 'X';
    fim_jogo = 0;
    rodada = 0;   

    do{ 
        printJogo(jogo);

        //JOGADOE ESCOLHE SUA JOGADA, COM VALIDAÇÃO
        while(1){
            //USUÁRIO DIGITA EM QUAL POSIÇÃO QUER JOGAR
            elemento = initElementoMatriz();

            if (existeNaMatriz(jogo, elemento)){
                printJogo(jogo);
                printf("INVALIDO! ESCOLHA DE NOVO\n");
            }else{
                jogo.matrizJogo[elemento.i_val][elemento.j_val] = jogador;
                break;
            }
        }

        //TESTE PARA SABER SE ALGUEM GANHOU E INCREMENTA A RODADA
        fim_jogo = fimJogo(jogo, jogador);
        rodada++;

        //CONDIÇÕES PARA FINALIZAR O JOGO
        if (rodada == 9){
            break;
        }
        if (fim_jogo){
            continue;
        }

        //TROCA O JOGADOR NO FIM DA RODADA
        if (jogador == 'X'){
            jogador = 'O';
        }else{
            jogador = 'X';
        }
    }while(!fim_jogo);

    printJogo(jogo); 

    if (fim_jogo){
        printf("\nGANHOU [%c]!", jogador);
    }else{
        printf("\nNINGUEM GANHOU!");
    }
    printf("\nFIM DE JOGO!");

    return 0;
}