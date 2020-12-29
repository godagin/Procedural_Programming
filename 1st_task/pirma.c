/*
LSP: 2015977
Autorius: Goda Gintalaite
El. pastas: goda.gintalaite@mif.stud.vu.lt
Uzduoties numeris: 7
*/

#include <stdio.h>

int main(){
    int endNumber,
        number,
        count = 0,
        positiveCount = 0,
        negativeSum = 0,
        negativeProduct = 1;

    printf("Iveskite sveika skaiciu G, kuris zymes skaiciu sekos pabaiga\n");
    while(scanf("%d", &endNumber) != 1){
        printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
        while(getchar() != '\n');
    }
    printf("Iveskite sveiku skaiciu seka:\n");
    while(number != endNumber){
        if(scanf("%d", &number) != 1){
            while(getchar() != '\n');

            printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
            continue;
        }
        if(number > 0){
            positiveCount++;
        }
        else if(number < 0){
            negativeSum += number;
            negativeProduct *= number;
        }
        count++;
    }
    printf("Visu nariu skaicius: %d,\nTeigiamu nariu skaicius: %d,\n", count, positiveCount);
    if(count == positiveCount){
        printf("Neigiamu nariu neivesta.");
    }
    else {
        printf("Neigiamu nariu suma %d ir sandauga %d.", negativeSum, negativeProduct);
    }
    /*
    int i = 0;
    for( scanf("%d", &i); i < 3; ){

         printf("%d", i);
        ++i;
    }
      */
    return 0;
}
