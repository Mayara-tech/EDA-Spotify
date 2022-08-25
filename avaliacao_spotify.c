/* UNIVERSIDADE DE BRASILIA - FGA 
GRUPO G- SPOTIFY/SelectionSort - EDA
ALUNOS:
Vinicius de Oliveira Santos
Mayara Alves de Oliveira
Dara Maria Barbosa de Sousa
Paulo Vinicius Pinheiro do Nascimento
Arthur D'Assumpção */

#include <stdio.h>
#include <stdlib.h>    //BIBLIOTECAS
#include <time.h>

//FUNÇÕES
void selectionSort(int vet[], int tam);
int smallerIndex(int vet[], int tam, int ini);


int main(){

// DEFININDO VARIAVEIS

    FILE *text1,*text2,*text3;
    char ano[8],dia[4],hora[15],letra,hifen;
    int c1[5231],c2[7458],c3[8023],c4[13803],c5[10922],c6[12257],c7[3900];
    int i,j,posic,nota,mes;
    float c[]={0,0,0,0,0,0,0};
    float soma[]={0,0,0,0,0,0,0};
    float media[]={0,0,0,0,0,0,0};
    float mediames[]={0,0,0,0,0,0,0};
    clock_t startmedia_t,endmedia_t,startselection_t,endselection_t;
    double resultmedia_t,resultselection_t;


//ABRINDO OS ARQUIVOS   
    text1 = fopen("Planilha Dados Filtrados.csv", "r");
    text2 = fopen("Dados_ordenados.csv","w");
    text3 = fopen("Dados_grafico.csv","w");

//VERIFICANDO SE OS ARQUIVOS FORAM ABERTOS CORRETAMENTE

    if(text1 == NULL){
        printf("Erro ao abrir o texto1");
        exit(0);
    }
    if(text2 == NULL){
        printf("Erro ao abrir o texto2");
        exit(0);
    }
    if(text3 == NULL){
        printf("Erro ao abrir o texto3");
        exit(0);
    }

    do{
        fscanf (text1, "%c", &letra);
        fprintf(text2,"%c", letra);
    }while (letra != '\n');
   

//CALCULANDO A MEDIA DAS AVALIAÇÕES MENSAIS
    while( fscanf (text1, "%4s %c %d %3s %9s %d", ano,&hifen,&mes,dia,hora,&nota) !=  EOF){
        if(mes == 7){
            posic=c[mes-1];
            c7[posic] = nota;
            soma[mes-1] = soma[mes-1] + nota;
            c[mes-1]++;
        }
        if(mes == 6){
            posic=c[mes-1];
            c6[posic] = nota;
            soma[mes-1] = soma[mes-1] + nota;
            c[mes-1]++;
        }
        if(mes == 5){
            posic=c[mes-1];
            c5[posic] = nota;

            soma[mes-1] = soma[mes-1] + nota;

            c[mes-1]++;
        }
        if(mes == 4){
            posic=c[mes-1];
            c4[posic] = nota;

            soma[mes-1] = soma[mes-1] + nota;

            c[mes-1]++;
        }
        if(mes == 3){
            posic=c[mes-1];
            c3[posic] = nota;

            soma[mes-1] = soma[mes-1] + nota;

            c[mes-1]++;
        }
        if(mes == 2){
            posic=c[mes-1];
            c2[posic] = nota;

            soma[mes-1] = soma[mes-1] + nota;

            c[mes-1]++;
        }
        if(mes == 1){
            posic=c[mes-1];
            c1[posic] = nota;
            soma[mes-1] = soma[mes-1] + nota;
            c[mes-1]++;
        }
    }

//FUNÇÃO DE INÍCIO PARA O CÁLCULO DO TEMPO DE EXECUÇÃO DA MÉDIA    
    startmedia_t = clock();

    for(i=0;i<7;i++){
        media[i] = soma[i]/c[i];
    }

//FUNCAO QUE GRAVA O VALOR DA MEDIA AO SEU RESPECTIVO MES
    for(i=0;i<7;i++){
        mediames[i] = media[i];
    }

//FUNÇAO PARA MEDIR O TEMPO DE PROCESSAMENTO DA MEDIA
    endmedia_t = clock();
    resultmedia_t = (double)(endmedia_t - startmedia_t) / CLOCKS_PER_SEC;
    printf("Tempo de processamento do calculo da media: %f\n",resultmedia_t);
    


//FUNCAO PARA MEDIR O TEMPO DE PROCESSAMENTO DO ALGORITMO DE ORDENACAO
    startselection_t = clock();

// APLICANDO O SELECTIONSORT PARA ORDENAR AS NOTAS DE CADA MES
    selectionSort(c7,c[6]);
    selectionSort(c6,c[5]);
    selectionSort(c5,c[4]);
    selectionSort(c4,c[3]);
    selectionSort(c3,c[2]);
    selectionSort(c2,c[1]);
    selectionSort(c1,c[0]);

// APLICANDO O SELECTIONSORT PARA ORDENAR A MEDIA MENSAL DAS AVALIAÇÕES
    selectionSort(media,7);


//FUNÇAO PARA MEDIR O TEMPO DE PROCESSAMENTO DA MEDIA
    endselection_t = clock();
    resultselection_t = (double)(endselection_t - startselection_t) / CLOCKS_PER_SEC;
    printf("Tempo de processamento do algoritmo de ordenacao: %f\n",resultselection_t);


//COPIANDO E ORGANIZANDO OS DADOS DE ACORDO COM O MES NO ARQUIVO DE DADOS ORDENADOS  

    for(i=0;i<c[6];i++){
        fprintf(text2,"2022_07,%d\n",c7[i]);
    }
    for(i=0;i<c[5];i++){
        fprintf(text2,"2022_06,%d\n",c6[i]);
    }
    for(i=0;i<c[4];i++){
        fprintf(text2,"2022_05,%d\n",c5[i]);
    }
    for(i=0;i<c[3];i++){
        fprintf(text2,"2022_04,%d\n",c4[i]);
    }
    for(i=0;i<c[2];i++){
        fprintf(text2,"2022_03,%d\n",c3[i]);
    }
    for(i=0;i<c[1];i++){
        fprintf(text2,"2022_02,%d\n",c2[i]);
    }
    for(i=0;i<c[0];i++){
        fprintf(text2,"2022_01,%d\n",c1[i]);
    }
    
    fprintf(text3,"Meses,Avaliacao_Media\n");
    
//COPIANDO AS MEDIAS MENSAIS ORDENADAS PARA O ARQUIVO DE DADOS GRAFICOS  

    for(i=0;i<7;i++){
        if(mediames[0] == media[i]){
            fprintf(text3,"2022_01,%.2f\n",media[i]);
        }
        if(mediames[1] == media[i]){
            fprintf(text3,"2022_02,%.2f\n",media[i]);
        }
        if(mediames[2] == media[i]){
            fprintf(text3,"2022_03,%.2f\n",media[i]);
        }
        if(mediames[3] == media[i]){
            fprintf(text3,"2022_04,%.2f\n",media[i]);
        }
        if(mediames[4] == media[i]){
            fprintf(text3,"2022_05,%.2f\n",media[i]);
        }
        if(mediames[5] == media[i]){
            fprintf(text3,"2022_06,%.2f\n",media[i]);
        }
        if(mediames[6] == media[i]){
            fprintf(text3,"2022_07,%.2f\n",media[i]);
        }
    }
//FECHANDO ARQUIVOS 
    fclose(text1);
    fclose(text2);
    fclose(text3);

    return 0;
}

//FUNÇÃO DE ORDENAÇÃO SELECTIONSORT
void selectionSort(int vet[], int tam){
    int i, max, aux , j;
    for(i=0; i<tam; i++){
        //Acha posicao do maior elemento a partir de i:
        max = biggerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[max];
        vet[max] = aux;
    }
}
//FUNÇÃO PARA ACHAR MAIOR POSIÇÃO
    int biggerIndex(int vet[], int tam, int ini){
    int max = ini, j;
    for(j=ini+1; j<tam; j++){
        if(vet[max] < vet[j]){
            max = j;
        }
    }
    return max;
}
