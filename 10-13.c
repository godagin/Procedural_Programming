///Spausdina duota skaiciu seka be pasikartojimu

#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
   // printf("");
    scanf("%d", &n);

    int array[100] = {0};
    //printf("");
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        bool new_number = true;
        for(int j = 0; j < i; ++j)
        {
            if(array[i] == array[j])
            {
                 new_number = false;
                 break;
            }
        }
        if(new_number == true)
        printf("%d ", array[i]);
    }

    return 0;
}
