#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file_writer = fopen("teste2.csv", "a");  
    FILE *file_reader = fopen("pins.txt", "r");
    
    fwrite("\n", sizeof(char), 1, file_writer);
    char tmp[110];
    while(!feof(file_reader)){
        fgets(tmp, 110, file_reader);
        printf("%s", tmp);
        fwrite(tmp, sizeof(char), strlen(tmp), file_writer);
    }
    fwrite("\n", sizeof(char), 1, file_writer);

    fclose(file_writer);
    fclose(file_reader);

    return 0;
}