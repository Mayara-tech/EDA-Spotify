#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1,*text2;
    char ano[8],dia[4],hora[15],letra,nota;

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

    while( fscanf (text1, "%7s %3s %9s %c", ano,dia,hora,&nota) !=  EOF){
        fprintf(text2,"%s,%c\n", ano,nota);
    }

    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}
