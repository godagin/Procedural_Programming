#include <stdio.h>

int main(){
    int endNumber,
        number,
        factorial=1;

    scanf("%d%d", &number, &endNumber);

    if (number > endNumber)
    {
        int a = number;
        number = endNumber;
        endNumber = a;
    }

    for(int i = 1; i < endNumber; ++i)
    {
        factorial *= i;
        if(factorial >= number && factorial <= endNumber)
            printf("%d\n", factorial);

        else if (factorial >= endNumber)
            break;
    }
    return 0;}
