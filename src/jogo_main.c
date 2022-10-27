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

    //RECEBE O VALOR DA LINHA QUE O USUÁRIO DIGITAR E VALIDA
    while (1){
        printf("Escolha uma Linha: ");
        scanf(" %c", &linha);
        if (linha == 'A' || linha == 'B' || linha == 'C'){
            break;
        }else{
            printf("INVALIDO! TENTE DE NOVO\n");
        }
    }
    //RECEBE O VALOR DA COLUNA QUE O USUÁRIO DIGITAR E VALIDA
    while (1){
        printf("Escolha uma Coluna: ");
        scanf("%d", &coluna);
        if (coluna == 1 || coluna == 2 || coluna == 3){
            break;
        }else{
            printf("INVALIDO! TENTE DE NOVO\n");
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
    int fim_jogo, rodada, deNovo;  

    do{
        //INICIALIZAÇÃO DOS ELEMENTOS DA MATRIZ DE "jogo"
        jogo = initMatrizJogo();

        //INICIALIZAÇÃO DAS VARIÁVEIS NECESSÁRIAS
        jogador = 'X';
        fim_jogo = 0;
        rodada = 0; 

        do{ 
            printJogo(jogo);

            //JOGADOE ESCOLHE SUA JOGADA
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

            //TESTE PARA SABER SE ALGUEM GANHOU E INCREMENTO NA RODADA
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

        //IMPRIME O RESULTADO DO JOGO
        printJogo(jogo); 
        if (fim_jogo){
            printf("\nGANHOU [%c]!", jogador);
        }else{
            printf("\nNINGUEM GANHOU!");
        }
        printf("\nFIM DE JOGO!");

        //CONDIÇÕES PARA INICIAR UMA NOVA PARTIDA OU NÃO
        while (1){
            printf("\nJOGAR NOVAMENTE? \n[1] - SIM\n[0] - NAO\n");
            scanf("%d", &deNovo);
            if (deNovo == 1 || deNovo == 0){
                break;
            }else{
                printf("RESPOSTA INVALIDA!");
            }
        }
    }while(deNovo);
    
    return 0;
}