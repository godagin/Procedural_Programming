/*
LSP: 2015977
Autorius: Goda Gintalaite
El. pastas: goda.gintalaite@mif.stud.vu.lt
Uzduoties numeris: 14
*/
#include <stdio.h> //isvestis ivestis
#include <stdlib.h> //funkcijos iv
///Įvesti sveiką skaičių N. Įvesti N sveikų skaičių a1, a2, ... aN.
///Apskaičiuoti, kiek yra skaičių lygių maksimumui ir kiek lygių
///minimumui. Išvesti įvestus skaičius, išmetus lygius maksimumui ir minimumui.

void findMinMax(int i, int num, int* max, int* min){
    if(*max != NULL && *min != NULL){
        if(i == 0){
            *min = num;
            *max = num;
        }
        else if(*max < num)
            *max = num;
        else if(*min > num)
            *min = num;
    }


}

void countMinMax(int amount, int min, int max, int array[], int* minCount, int* maxCount){
    for(int i = 0; i < amount; ++i){
        if(array[i] == min){
            ++*minCount;
        }
        if(array[i] == max){
            ++*maxCount;
        }
    }
}

int main(){
    int amount, maximum, minimum, maxCount = 0, minCount =0;

    printf("Iveskite sveika skaiciu N, zyminti, kiek skaiciu sudarys skaiciu seka:\n");

    //read the amount of numbers of the array
    while(scanf("%d", &amount) != 1){
        printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
        while(getchar() != '\n');
    }

    int array[amount];

    printf("Iveskite skaiciu seka is %d nariu:\n", amount);

    //read and find minimum, maximum
    for(int i = 0; i < amount; ++i){
        while(scanf("%d", &array[i]) != 1){
            printf("Netinkamo formato ivestis. Prasome ivesti sveika skaiciu:\n");
            while(getchar() != '\n');
        }
        findMinMax(i, array[i], &maximum, &minimum);
    }

    countMinMax(amount, minimum, maximum, array, &minCount, &maxCount);

    printf("Maziausio skaiciaus sekoje pasikartojimu buvo %d\n", minCount);
    printf("Didziausio skaiciaus sekoje pasikartojimu buvo %d\n", maxCount);

    printf("Jusu seka be didziausiu ir maziausiu skaiciu:\n");

    //print array
    for(int i = 0; i < amount; ++i){
        if(array[i] != minimum && array[i] != maximum)
            printf("%d ", array[i]);
    }

    return 0;
}
