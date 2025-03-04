#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* readEntireFile(char* fileName);

void searchFor(char* fileName, char* fileNameOut, int preCount, int* values[10], char* delim, int count, int len);