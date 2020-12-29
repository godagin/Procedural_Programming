///Parašyti funkciją, kuri duotame tekste sujungia eilutės viduje atsidūrusius perkeltus
///žodžius (žodis laikomas perkeltu, jei jo pirmoji dalis baigiasi simboliu "-", o tada
///be tarpo eina antroji dalis).

#include <stdio.h>
#include <stdlib.h>

/*
void connectWord(char * dash){
    *dash = 0;
}
*/

void checkAndConnect(char dataLine[], char resultLine[]){
    int i = 0;
    int resultSize = 0;
    int wordLetterIndex = 0;

    while(dataLine[i] != 0 && i < 255){
        if(dataLine[i] != '-' || wordLetterIndex == 0 || dataLine[i+1] == ' '){
            resultLine[resultSize] = dataLine[i];
            ++resultSize;
        }
        if(dataLine[i] == ' '){
            wordLetterIndex = 0;
        } else{
            ++wordLetterIndex;
        }
        ++i;
    }
}

void clearBuffer(char buffer[]){
    int i = 0;
    while(buffer[i] != 0){
        buffer[i++] = 0;
    }
}

int main(int argc, char *argv[]){

    FILE *fileRead;
    fileRead = fopen(argv[1], "r");

    //if error when opening file
    if(fileRead == NULL){
        printf("Negalima atidaryti failo.\n");
        return 0;
    }


    FILE *fileWrite;
    fileWrite = fopen(argv[2], "w");

    //if error when opening file
    if(fileWrite == NULL){
        printf("Negalima sukurti tokio failo.\n");
        return 0;
    }


    char *dataBuffer = NULL, *resultBuffer = NULL;
    dataBuffer = (char *)calloc(255, sizeof(char));
    resultBuffer = (char *)calloc(255, sizeof(char));

    while(!feof(fileRead) && dataBuffer && resultBuffer){
        fgets(dataBuffer, 255, fileRead);

        //check if there are separated words and connect them
        checkAndConnect(dataBuffer, resultBuffer);

        //printing to file
        fprintf(fileWrite, "%s", resultBuffer);

        //clear both buffers
        clearBuffer(dataBuffer);
        clearBuffer(resultBuffer);
    }

    free(dataBuffer);
    free(resultBuffer);

    fclose(fileRead);
    fclose(fileWrite);
    return 0;
}

