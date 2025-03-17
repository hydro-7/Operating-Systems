#include<stdio.h>
int main() {
    char msg[100];
    char filename[100];
    FILE *file;

    file = fopen(filename, "w");

    fputs(msg, file);
    fclose(file);
}