#include <stdio.h>
#include <stdlib.h>

main(){

    FILE *text1;
    char data[20], hora[10], letra;
    int nota;

    text1 = fopen("Planilha Dados Filtrados.csv", "r");

    if(text1 == NULL){
        printf("Erro!");
        system("pause");
        exit(0);
    }
    fscanf (text1, "%c", &letra);
    print("%c", letra);

  /*  do{
        fscanf (text1, "%c", &letra);
        print("%c", letra);
    }while (letra != '\n');
    */

    //  fscanf (text1, "%s", data);
    //fgets(data, 100, text1);
    //printf("Titulos: %s", data);

    while( fscanf (text1, "%s %s %d", data, hora, &nota) !=  EOF){

            printf("Data:%s Hora:%s Nota:%d\n", data, hora, &nota);
    }

    system("pause");
    fclose(text1);

}
