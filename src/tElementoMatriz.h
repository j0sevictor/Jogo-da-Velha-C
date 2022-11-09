//ELEMENTO DA MATRIZ----------------------
typedef struct {
    int i_val;
    int j_val;
} tElementoMatriz;

tElementoMatriz initElementoMatriz(){
    tElementoMatriz m;
    char linha[3];

    //RECEBE O VALOR DA LINHA E DA COLUNA QUE O USUÁRIO DIGITAR E VALIDA
    while (1){
        printf("Escolha uma Linha e Coluna: ");
        scanf("%s", &linha);
        
        if (linha[0] == 'A' || linha[0] == 'B' || linha[0] == 'C'){
            if (linha[1] == '1' || linha[1] == '2' || linha[1] == '3'){
                break;
            }
        }else{
            printf("INVALIDO! TENTE DE NOVO\n");
        }
    }

    // 65 é o valor de 'A' na tabela ASCII, 49 o valor de '1'
    m.i_val = (linha[0] - 65);
    m.j_val = (linha[1] - 49);

    return m;
}
//----------------------------------------

/*
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
*/