#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1,*text2;
    char data[15],hora[15],letra,nota;

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

    while( fscanf (text1, "%10s %9s %c", data,hora,&nota) !=  EOF){
        fprintf(text2,"%s,%c\n", data,nota);
    }

    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}
