#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1,*text2;
    char letra,virgula;
    int year,month,nota;
    int count1,count2,count3,count4,count5,count6,count7;
    int teste[3901],i;

    count1=count2=count3=count4=count5=count6=count7=0;

    for(i=0;i<3900;++i){
        teste[i] = 999;
    }

    text1 = fopen("copia.csv","r");
    text2 = fopen("copy.csv","w");
  
    if(text1 == NULL && text2 == NULL){
        printf("Erro!");
        system("pause");
        exit(0);
    }

    do{
        fscanf (text1, "%c", &letra);
        fprintf(text2,"%c", letra);
    }while (letra != '\n');

    while( fscanf (text1, "%d %d %c %d", &year,&month,&virgula,&nota) !=  EOF){
        if(month == 7){
            /*for(i=0;i<3900;++i){
                teste[i] = nota;
                break;
            }*/
            count7++;
        }
        if(month == 6){
            count6++;
        }
        if(month == 5){
            count5++;
        }
        if(month == 4){
            count4++;
        }
        if(month == 3){
            count3++;
        }
        if(month == 2){
            count2++;
        }
        if(month == 1){
            count1++;
        }
    }

    printf("mes 1:%d\n mes 2:%d\n mes 3:%d\n mes 4:%d\n mes 5:%d\n mes 6:%d\n mes 7:%d\n",count1,count2,count3,count4,count5,count6,count7);

    /*for(i=0;i<3900;i++){
        fprintf(text2,"%d\n",teste[i]);
    }*/


    system("pause");
    fclose(text1);
    fclose(text2);


    return 0;
}
