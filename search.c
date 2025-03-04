#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* readEntireFile(char* fileName){
    FILE* open;
    open = fopen(fileName, "r");

    if (open == NULL){
        printf("The file is not opened search c");
        exit(0);
    }

    char *file_content;
    long file_size;

    //Looks for the end of the file starting from the beginning
    fseek(open, 0, SEEK_END);
    //once the end of the file is found, it uses the position to store the size of the file
    file_size = ftell(open);

    //goes back to the beginning of the file
    rewind(open);

    //allocating memory for the file content
    file_content = (char*)malloc(file_size+1);

    //if file content is still null allocating memory has failed
    if(file_content == NULL){
        printf("Failed Memory");
    }

    //
    if(fread(file_content, 1, file_size, open) != file_size){
        perror("Error reading file");
        free(file_content);
    }

    file_content[file_size] ='\0';

    return file_content;
    fclose(open);

}

void searchFor(char* fileName, char* fileNameOut, int preCount, int* values[10], char* delim, int count, int len){
    
    //open the file that will be written out to
    FILE* out;
    out = fopen(fileNameOut, "w");
    int countAfter = 0;

    fprintf(out, "Searching file for matches for %d values.\n", count);
    fprintf(out, "Searched at      Searching       Found at\n");
    fprintf(out, "-------------------------------\n");


    for(int i = 0; i < len; i++){
            //position of the value we're looking for in search area
            int countafter = 0;
            char* token2;
            token2 = strtok(readEntireFile(fileName), delim);
            int k = 0;

            //goes through the first values through the negative
            while(token2 != NULL && k < preCount+1){
                k++;
                token2 = strtok(NULL, delim);
            }
            
            while (token2 != NULL)
            {
                
                //if the token matches the value we're searching for print out the value
                if(values[i] == atoi(token2)){

                    fprintf(out, "    %d               ", i);
                    fprintf(out, "%d            ", atoi(token2));
                    fprintf(out, "%d\n", countafter);

                }
                countAfter = countafter;
                countafter++;
                token2 = strtok(NULL, delim);
            }
    }

    fprintf(out, "Number of items searched through in list: %d", countAfter);

    fclose(out);
}