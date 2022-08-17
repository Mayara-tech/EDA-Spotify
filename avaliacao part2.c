#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(int vet[7][13803], int tam, int pos);
int smallerIndex(int vet[7][13803], int tam, int ini,int pos);

int main(){

    FILE *text1,*text2;
    char ano[8],dia[4],hora[15],letra,hifen;
    int c1,c2,c3,c4,c5,c6,c7;
    int notas[7][13803],i,j;
    int nota,mes;

    c1=c2=c3=c4=c5=c6=c7=0;

    for(i=0;i<7;i++){
        for(j=0;j<13803;j++){
            notas[i][j] = 0;
        }
    }

    text1 = fopen("Planilha Dados Filtrados.csv", "r");
    text2 = fopen("copa.csv","w");
  
    if(text1 == NULL && text2 == NULL){
        printf("Erro!");
        system("pause");
        exit(0);
    }

    do{
        fscanf (text1, "%c", &letra);
        fprintf(text2,"%c", letra);
    }while (letra != '\n');

    while( fscanf (text1, "%4s %c %d %3s %9s %d", ano,&hifen,&mes,dia,hora,&nota) !=  EOF){
        if(mes == 7){
            notas[6][c7] = nota;
            c7++;
        }
        if(mes == 6){
            notas[5][c6] = nota;
            c6++;
        }
        if(mes == 5){
            notas[4][c5] = nota;
            c5++;
        }
        if(mes == 4){
            notas[3][c4] = nota;
            c4++;
        }
        if(mes == 3){
            notas[2][c3] = nota;
            c3++;
        }
        if(mes == 2){
            notas[1][c2] = nota;
            c2++;
        }
        if(mes == 1){
            notas[0][c1] = nota;
            c1++;
        }
    }

    selectionSort(notas,c7,6);
    selectionSort(notas,c6,5);
    selectionSort(notas,c5,4);
    selectionSort(notas,c4,3);
    selectionSort(notas,c3,2);
    selectionSort(notas,c2,1);
    selectionSort(notas,c1,0);

    for(i=0;i<c7;i++){
        fprintf(text2,"%d\n",notas[6][i]);
    }
    for(i=0;i<c6;i++){
        fprintf(text2,"%d\n",notas[5][i]);
    }
    for(i=0;i<c5;i++){
        fprintf(text2,"%d\n",notas[4][i]);
    }
    for(i=0;i<c4;i++){
        fprintf(text2,"%d\n",notas[3][i]);
    }
    for(i=0;i<c3;i++){
        fprintf(text2,"%d\n",notas[2][i]);
    }
    for(i=0;i<c2;i++){
        fprintf(text2,"%d\n",notas[1][i]);
    }
    for(i=0;i<c1;i++){
        fprintf(text2,"%d\n",notas[0][i]);
    }


    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}

void selectionSort(int vet[7][13803], int tam, int pos){
    int i, min, aux , j;
    for(i=0; i<tam; i++){
        //Acha posicao do menor elemento a partir de i:
        min = smallerIndex(vet, tam, i, pos);
        aux = vet[pos][i];
        vet[pos][i] = vet[min];
        vet[pos][min] = aux;
    }
}

int smallerIndex(int vet[7][13803], int tam, int ini,int pos){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        if(vet[pos][min] > vet[pos][j]){
            min = j;
        }
    }
    return min;
}