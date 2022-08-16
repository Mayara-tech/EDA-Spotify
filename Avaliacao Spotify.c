/* UNIVERSIDADE DE BRASILIA - FGA 
GRUPO G- SPOTIFY/SelectionSort - EDA
Alunos: Mayara Alves de Oliveira
Vinicius de Oliveira Santos
Dara Maria Barbosa de Sousa
Paulo Vinicius Pinheiro do Nascimento
Arthur D'Assumpção */


#include <stdio.h>
#include <stdlib.h>     //BIBLIOTECAS
#include <string.h>

// CRIANDO STRUCT
struct AvaliacaoSpotify
{
    int nota;
    char ano[8];
};
typedef struct AvaliacaoSpotify avaliacao;


int main(){
    

//DECLARANDO AS VARIAVEIS
    FILE *arquivo1,*arquivo2,*arquivo3;
    char ano[8],dia[4],hora[15],letra,nota;
    avaliacao janeiro [4000];
    int i;
    int contador = 0;
    char avaliacao_ano[8];
    int avaliacao_nota;


//ABRINDO OS ARQUIVOS    
    arquivo1 = fopen("Planilha Dados Filtrados.csv", "r");
    arquivo2 = fopen("Dados.csv","w");
    arquivo3 = fopen("AvaliacaoJaneiro.csv","w");

//VERIFICANDO SE OS ARQUIVOS FORAM ABERTOS CORRETAMENTE
    if(arquivo1 == NULL && arquivo2 == NULL){
        printf("Não foi possivel abrir arquivo!");
        system("pause");
        exit(0);
    }
//COPIANDO OS DADOS NECESSARIOS DA PLANILHA DE DADOS FILTRADOS PARA PLANILHA COPIA
    do{
        fscanf (arquivo1, "%c", &letra);
        fprintf(arquivo2,"%c", letra);
    }while (letra != '\n');

// ESTRUTURA TESTE PARA SEPARAÇÃO POR MES
    while( fscanf (arquivo1, "%7s %3s %9s %c", ano,dia,hora,&nota) !=  EOF){
        strcpy(janeiro[contador].ano, ano);
        janeiro[contador].nota = nota;
    while(fscanf(arquivo3, "%s %d", avaliacao_ano, avaliacao_nota )!= EOF) {
        if(avaliacao_ano == "01-20022"){
            janeiro[4000].nota = avaliacao_nota;
        }
    }
        contador++;
    }
  system("pause");

//FECHANDO ARQUIVOS 
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

// TESTE PARA MOSTRAR RESULTADOS 
    printf("resultados: \n");
    for(i=0; i<4000; i++)
    if(janeiro[i].ano == "01-2022"){
        printf("%s %d", janeiro[i].ano,janeiro[i].nota);
  }

    return 0;
}
