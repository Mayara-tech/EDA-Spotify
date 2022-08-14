#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1,*text2;
    char ano[8], mes[3],dia[4],hora[15],letra;
    char mes1[2],mes2[2],mes3[2],mes4[2],mes5[2],mes6[2],mes7[2];
    int nota,mat[7][4000];
    int count=0,i,j;
    int abc = 9;

    mes1[2] = "01";
    mes2[2] = "02";
    mes3[2] = "03";
    mes4[2] = "04";
    mes5[2] = "05";
    mes6[2] = "06";
    mes7[2] = "07";

    for(i=0;1<7;i++){
        for(j=0;j<4000;j++){
            mat[i][j] = 0;
        }
    }

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

    while( fscanf (text1, "%5s %2s %3s %9s %d", ano,mes,dia,hora,&nota) !=  EOF){
        abc = strcmp(mes,mes7);
        if(abc < 1){
            printf("ola");
        }

        /*if(strcmp(mes,mes6)){
            count = nota;
        }
        if(strcmp(mes,mes5)){
            count = nota;
        }
        if(strcmp(mes,mes4)){
            count = nota;
        }
        if(strcmp(mes,mes3)){
            count = nota;
        }
        if(strcmp(mes,mes2)){
            count = nota;
        }
        if(strcmp(mes,mes1)){
            count = nota;
        }*/
        //fprintf(text2, "mes: %s,nota:%d\n", mes,nota);
    }

    /*for(j=0;j<4000;j++){
        fprintf(text2, "%d\n", mat[0][j]);
    }*/

    //fprintf(text2, "%d\n", mat[0][0]);



    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}
