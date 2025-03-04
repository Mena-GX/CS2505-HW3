#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "search.h"

int main(int argc, char* argv[]){

    //what I am using to parse the file content
    char delimiter[] = " ";

    //where all of the tokens go one by one
    char *token;

    //array of first 10 values 
    int* searchingFor[10];

    int preCount = 0;

    //splits up the file content using spaces and stores it
    token = strtok(readEntireFile(argv[1]), delimiter);
    int i = 0;

    //going through the tokens until the end which is null
    while(token != NULL){

        //checks if the current number is negative
        //if yes, breaks the loop
        //if no, checks if we have space in array
        //if yes, adds the number to the array
        //if no, breaks the loop
        if(atoi(token) < 0){
            break;
            
        } else{
            preCount++;
            if(i < 10){
                searchingFor[i] = atoi(token);
            } else{
                preCount++;
                break;
            } 
        }
        i++;
        token = strtok(NULL, delimiter);
        
    }

    
    searchFor(argv[1], argv[2], preCount, searchingFor, delimiter, i, 10);

}
