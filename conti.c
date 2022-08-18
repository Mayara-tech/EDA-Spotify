#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(int vet[], int tam);
int smallerIndex(int vet[], int tam, int ini);

int main(){

    FILE *text1,*text2;
    char ano[8],dia[4],hora[15],letra,hifen;
    int c1[5231],c2[7458],c3[8023],c4[13803],c5[10922],c6[12257],c7[3900];
    int i,j,posic;
    int nota,mes;
    float c[]={0,0,0,0,0,0,0};
    float soma[]={0,0,0,0,0,0,0};
    float media[]={0,0,0,0,0,0,0};
    float mediames[]={0,0,0,0,0,0,0};

    text1 = fopen("Planilha Dados Filtrados.csv", "r");
    text2 = fopen("copia.csv","w");

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

    for(i=0;i<7;i++){
        media[i] = soma[i]/c[i];
    }

    for(i=0;i<7;i++){
        mediames[i] = media[i];
    }


    selectionSort(c7,c[6]);
    selectionSort(c6,c[5]);
    selectionSort(c5,c[4]);
    selectionSort(c4,c[3]);
    selectionSort(c3,c[2]);
    selectionSort(c2,c[1]);
    selectionSort(c1,c[0]);

    selectionSort(media,7);

    for(i=0;i<7;i++){
        if(mediames[0] == media[i]){
            fprintf(text2,"2022_01: %.2f\n",media[i]);
        }
        if(mediames[1] == media[i]){
            fprintf(text2,"2022_02: %.2f\n",media[i]);
        }
        if(mediames[2] == media[i]){
            fprintf(text2,"2022_03: %.2f\n",media[i]);
        }
        if(mediames[3] == media[i]){
            fprintf(text2,"2022_04: %.2f\n",media[i]);
        }
        if(mediames[4] == media[i]){
            fprintf(text2,"2022_05: %.2f\n",media[i]);
        }
        if(mediames[5] == media[i]){
            fprintf(text2,"2022_06: %.2f\n",media[i]);
        }
        if(mediames[6] == media[i]){
            fprintf(text2,"2022_07: %.2f\n",media[i]);
        }
    }

    /*for(i=0;i<c[6];i++){
        fprintf(text2,"mes7: %d\n",c7[i]);
    }
    for(i=0;i<c[5];i++){
        fprintf(text2,"mes6: %d\n",c6[i]);
    }
    for(i=0;i<c[4];i++){
        fprintf(text2,"mes5: %d\n",c5[i]);
    }
    for(i=0;i<c[3];i++){
        fprintf(text2,"mes4: %d\n",c4[i]);
    }
    for(i=0;i<c[2];i++){
        fprintf(text2,"mes3: %d\n",c3[i]);
    }
    for(i=0;i<c[1];i++){
        fprintf(text2,"mes2: %d\n",c2[i]);
    }
    for(i=0;i<c[0];i++){
        fprintf(text2,"mes1: %d\n",c1[i]);
    }*/



    /*for(i=0;i<7;i++){
        fprintf(text2,"2022_0%d,%.2f\n",i+1,media[i]);
    }*/


    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}

void selectionSort(int vet[], int tam){
    int i, min, aux , j;
    for(i=0; i<tam; i++){
        //Acha posicao do menor elemento a partir de i:
        min = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

int smallerIndex(int vet[], int tam, int ini){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        if(vet[min] > vet[j]){
            min = j;
        }
    }
    return min;
}
