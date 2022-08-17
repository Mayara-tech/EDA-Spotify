#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1,*text2;
    char ano[8],dia[4],hora[15],letra,hifen,m7[2];
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
    text2 = fopen("copias.csv","w");
  
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


    for(i=0;i<7;i++){
        for(j=0;j<13803;j++){
            if(notas[i][j]!=0){
                fprintf(text2,"%d\n",notas[i][j]);
            }
        }
    }


    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}
