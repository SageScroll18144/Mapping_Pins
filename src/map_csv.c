#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char file_name[50];
    printf("Provide the project (.qsf) name.: ");
    scanf(" %s", file_name);

    char path[110];
    sprintf(path, "%s.csv", file_name);

    FILE *file_writer = fopen(path, "a");  
    FILE *file_reader = fopen("pins.txt", "r");
    
    //fwrite("\n", sizeof(char), 1, file_writer);
    char line[110];
    while(!feof(file_reader)){
        fgets(line, 110, file_reader);
        printf("%s", line);
        fwrite(line, sizeof(char), strlen(line), file_writer);
    }
    //fwrite("\n", sizeof(char), 1, file_writer);

    fclose(file_writer);
    fclose(file_reader);

    return 0;
}