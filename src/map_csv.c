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
    
    fwrite("\n", sizeof(char), 1, file_writer);

    int flag_title = 0;
    
    char tmp[50], line[110];
    while(!feof(file_reader)){
        
        fgets(tmp, 50, file_reader);
        tmp[strlen(tmp)-1] = '\0';
        sprintf(line, "%s,,,,,,\n", tmp);
        
        if(flag_title) fwrite(line, sizeof(char), strlen(line), file_writer);
        if(!flag_title) flag_title = 1;
    }
    
    fclose(file_writer);
    fclose(file_reader);

    return 0;
}