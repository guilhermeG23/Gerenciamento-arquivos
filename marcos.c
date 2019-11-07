#include <stdio.h>
#include <stdlib.h>

//Create -> X 
//Delete -> X
//Open -> X
//Close -> X
//Read -> X
//Write -> X
//Append -> X
//Seek
//Get Atributs
//Set Atributs
//Rename -> X

int main(void) {
    while(1) {
        int entrada;
        printf("\nEntre com a opcao\n1 - Criar arquivo\n2 - Escrever no arquivo\n3 - Apagar arquivo\n5 - Renomear arquivo\n6 - Conteudo arquivo\n7 - Acressentar conteudo\nEntrada: ");
        scanf ("%i", &entrada);
        switch (entrada) {
            case 1:
            criar_arquivo();
            break;
            case 2:
            escrever_arquivo();
            break;
            case 3:
            apagar_arquivo();
            break;
            case 5:
            renomear();
            break;
            case 6:
            ler();
            break;
            case 7:
            acressentar();
            break;
            default:
            printf("Opcao nao existente!Tente denovo\n");
        }     
    }
    return(0);
}

//Criar arquivos
int criar_arquivo() {

    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo);

    FILE *pont_arq;
        
    pont_arq = fopen(arquivo, "a");
        
    fclose(pont_arq);
        
    printf("O arquivo foi criado com sucesso!\n");
        
    return(0);
}

//Inserir valores no arquivo
int escrever_arquivo() {
    
    char arquivo[255];
    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo);

    FILE *pont_arq;
        
    pont_arq = fopen(arquivo, "r+");

    char texto[255];
    printf("Escreva: ");
    scanf("%s", &texto);
    fputs(texto, pont_arq);  
    fclose(pont_arq);
    printf("Escrita feita com sucesso!\n");

    return(0);

}

int apagar_arquivo() {
    char arquivo[255];
    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo);
    remove(arquivo);
    printf("Arquivo deletado!\n");
    return(0);
}

int renomear() {
    char arquivo_original[255];
    char arquivo_renomeado[255];

    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo_original);
    printf("Renomear: ");
    scanf("%s", &arquivo_renomeado);

    rename(arquivo_original, arquivo_renomeado);
    printf("O arquivo renomeado com sucesso!\n");

    return(0);
}

int ler() {
    char arquivo[255];
    int numPalavras = 0;
    char* palavras[50];
    char linha[50];
    int i = 0;

    FILE *pont_arq;
    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo);
    pont_arq = fopen(arquivo, "r");
    
    while(fgets(linha, sizeof linha, pont_arq) != NULL) {
        palavras[i] = strdup(linha);
        i++;
        numPalavras++;
    }

    for (int x = 0; x < numPalavras; x++) {
        printf("%s ", palavras[x]);
    }
    fclose(pont_arq);
    printf("\nO arquivo interpretado com sucesso!\n");

    return(0);
}

int acressentar() {
    
    char arquivo[255];
    printf("Entre com o nome do arquivo: ");
    scanf("%s", &arquivo);

    FILE *pont_arq;
    pont_arq = fopen(arquivo, "a");

    char texto[255];
    printf("Escreva: ");
    scanf("%s", &texto);

    fputs(texto, pont_arq);
    fclose(pont_arq);
    printf("Complemento feito com sucesso!\n");

    return(0);

}